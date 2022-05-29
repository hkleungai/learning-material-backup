#include <limits>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <cstdio>
#include "bigint.h"

using namespace std;

#define CHAR_BUFFER_LENGTH 1024
#define SIGN_PLUS '+'
#define SIGN_MINUS '-'

BigInt::BigInt() :
        abs_value(), sign(SIGN_PLUS) {
}

BigInt::BigInt(const char *numstr) :
        sign(SIGN_MINUS) {

    if (!from_string(numstr)) {
        throw domain_error("Bad input number");
    }
}

BigInt::BigInt(int i) {
    *this = i;
}

BigInt::BigInt(const BigInt &bi) :
        abs_value(bi.abs_value), sign(bi.sign) {

}

BigInt::BigInt(char signum, vector<unsigned short> value) :
        abs_value(value), sign(signum) {

}

BigInt::~BigInt() {

}

bool BigInt::from_string(const char* str) {
    int len = strlen(str);

    char signum = SIGN_PLUS;    // Suppose the number is positive
    int offset = 0;             // Offset to the first digit

    // Try to identify the sign symbol
    char ch = str[0];
    if (ch == SIGN_MINUS || ch == SIGN_PLUS) {
        signum = ch;
        offset++;
    }

    // Check if the string is only either the sign symbol or empty string
    if (len - offset <= 0) {
        return false;
    }

    // Check if all characters starting from offset are decimal digits
    bool zero_only = true;
    for (int i = offset; i < len; i++) {
        ch = str[offset];

        if (ch < '0' || ch > '9') {
            return false;
        } else if (ch != '0') {
            zero_only = false;
        }
    }

    if (zero_only) {
        // The str is zero
        sign = SIGN_PLUS;
        abs_value.resize(0);
    }

    sign = signum;
    abs_value.clear();
    // Starting from the last digit
    int idx = len - 1;

    while (idx >= offset) {
        unsigned short value;
        value = char2num(str[idx--]);

        if (idx - offset >= 0) {
            // Parse one more digit
            value += char2num(str[idx--]) * 10;
        }

        abs_value.push_back(value);
    }

    return true;
}

/**
 * Write the contained number to the C string
 */
void BigInt::write_buffer(char * str) const {
    int idx = 0;

    if (abs_value.empty()) {
        str[idx++] = num2char(0);
        str[idx++] = '\0';
        return;
    }

    if (sign == SIGN_MINUS) {
        str[idx++] = '-';
    }

    CoeVector::const_reverse_iterator itr = abs_value.rbegin();

    if (*itr >= 10) {
        str[idx++] = num2char(*itr / 10);
    }

    str[idx++] = num2char(*itr % 10);
    itr++;

    while (idx < CHAR_BUFFER_LENGTH - 2 && itr != abs_value.rend()) {
        str[idx++] = num2char(*itr / 10);
        str[idx++] = num2char(*itr % 10);
        itr++;
    }

    str[idx++] = '\0';

}

void BigInt::to_string(char * str) {
    write_buffer(str);
}

unsigned short BigInt::char2num(char ch) const {
    return ch - '0';
}

char BigInt::num2char(unsigned short i) const {
    return i + '0';
}

BigInt BigInt::operator+() const {
    return *this;
}

BigInt BigInt::operator-() const {
    return negate();
}

BigInt BigInt::operator+(BigInt const& bi) const {
    if (isZero()) {
        return bi;
    } else if (bi.isZero()) {
        return *this;
    }

    char signum = sign;

    if (signum == bi.sign) {
        CoeVector result;
        value_add(result, &abs_value, &bi.abs_value);
        return BigInt(signum, result);
    } else {
        int cmp = value_compare(&abs_value, &bi.abs_value);

        if (cmp == 0) {
            return BigInt();
        }

        CoeVector result;

        if (cmp > 0) {
            value_subtract(result, &abs_value, &bi.abs_value);
        } else {
            value_subtract(result, &bi.abs_value, &abs_value);
            signum = flip_sign(signum);
        }

        return BigInt(signum, result);
    }
}

BigInt BigInt::operator+(int i) const {
    if (i == 0) {
        return *this;
    } else {
        return *this + BigInt(i);
    }
}

BigInt operator+(int i, const BigInt& bi) {
    return bi + i;
}

BigInt BigInt::operator-(BigInt const& bi) const {
    if (isZero()) {
        return bi.negate();
    } else if (bi.isZero()) {
        return *this;
    }

    char signum = sign;
    if (signum == bi.sign) {
        int cmp = value_compare(&abs_value, &bi.abs_value);

        if (cmp == 0) {
            return BigInt();
        }

        CoeVector result;

        if (cmp > 0) {
            value_subtract(result, &abs_value, &bi.abs_value);
        } else {
            value_subtract(result, &bi.abs_value, &abs_value);
            signum = flip_sign(signum);
        }

        return BigInt(signum, result);
    } else {
        CoeVector result;
        value_add(result, &abs_value, &bi.abs_value);
        return BigInt(signum, result);
    }
}

BigInt BigInt::operator-(int i) const {
    if (i == 0) {
        return *this;
    } else {
        return *this - BigInt(i);
    }
}

BigInt operator-(int i, const BigInt& bi) {
    if (i == 0) {
        return bi.negate();
    } else {
        return BigInt(i) - bi;
    }
}

BigInt BigInt::operator*(BigInt const& bi) const {
    if (isZero()) {
        return *this;
    } else if (bi.isZero()) {
        return bi;
    }

    CoeVector result;
    value_multiply(result, &abs_value, &bi.abs_value);

    return BigInt(sign == bi.sign ? SIGN_PLUS : SIGN_MINUS, result);
}

BigInt BigInt::operator*(int i) const {
    if (i == 0 || isZero()) {
        return BigInt();
    } else if (i == 1) {
        return *this;
    } else if (i == -1) {
        return BigInt(flip_sign(sign), abs_value);
    }

    char signum = sign;
    CoeVector result;

    if (i > 0) {
        value_multiply(result, &abs_value, i);
    } else {
        value_multiply(result, &abs_value, -i);
        signum = flip_sign(signum);
    }

    return BigInt(signum, result);
}

BigInt operator*(int i, const BigInt& bi) {
    return bi * i;
}

BigInt BigInt::operator/(BigInt const& bi) const {
    if (bi.isZero()) {
        throw domain_error("division by zero");
    }

    if (isZero()) {
        return *this;
    }

    int cmp = value_compare(&abs_value, &bi.abs_value);

    if (cmp < 0) {
        return BigInt(0);
    } else if (cmp == 0) {
        if (sign == bi.sign) {
            return BigInt(1);
        } else {
            return BigInt(-1);
        }
    }

    CoeVector quotient;
    value_divide(&quotient, NULL, &abs_value, &bi.abs_value);

    return BigInt(sign == bi.sign ? SIGN_PLUS : SIGN_MINUS, quotient);
}

BigInt BigInt::operator/(int i) const {
    if (i == 1) {
        return *this;
    } else if (i == -1) {
        return negate();
    }

    return *this / BigInt(i);
}

BigInt operator/(int i, const BigInt& bi) {
    return BigInt(i) / bi;
}

BigInt BigInt::operator%(BigInt const& bi) const {
    if (bi.isZero()) {
        throw domain_error("division by zero");
    }

    if (isZero()) {
        return *this;
    }

    int cmp = value_compare(&abs_value, &bi.abs_value);

    if (cmp == 0) {
        return BigInt(0);
    }

    CoeVector remainder;
    value_divide(NULL, &remainder, &abs_value, &bi.abs_value);
    return BigInt(sign, remainder);
}

BigInt BigInt::operator%(int i) const {
    return *this % BigInt(i);
}

BigInt operator%(int i, const BigInt& bi) {
    return BigInt(i) % bi;
}

BigInt& BigInt::operator++() {
    BigInt after = *this + 1;
    *this = after;
    return *this;
}

BigInt BigInt::operator++(int) {
    BigInt before = *this;
    BigInt after = before + 1;
    *this = after;
    return before;
}

BigInt& BigInt::operator--() {
    BigInt after = *this - 1;
    *this = after;
    return *this;
}

BigInt BigInt::operator--(int) {
    BigInt before = *this;
    BigInt after = before - 1;
    *this = after;
    return before;
}

BigInt& BigInt::operator=(BigInt const& bi) {
    sign = bi.sign;
    abs_value = bi.abs_value;
    return *this;
}

BigInt& BigInt::operator=(int i) {
    sign = SIGN_PLUS;
    abs_value.clear();

    if (i == 0) {
        return *this;
    }

    unsigned int u = i;

    if (i < 0) {
        sign = SIGN_MINUS;

        if (i == numeric_limits<int>::min()) {
            u = (unsigned int) numeric_limits<int>::max() + 1;
        } else {
            u = -i;
        }
    }

    while (u > 0) {
        unsigned short r = u % 100;
        u = u / 100;
        abs_value.push_back(r);
    }

    return *this;
}

bool BigInt::operator<(BigInt const& bi) const {
    if (isZero()) {
        return bi.sign == SIGN_PLUS && !bi.isZero();
    } else if (sign == SIGN_PLUS) {
        return bi.sign == SIGN_PLUS && value_compare(&abs_value, &bi.abs_value) < 0;
    } else {
        return bi.isZero() || bi.sign == SIGN_PLUS || value_compare(&abs_value, &bi.abs_value) > 0;
    }
}

bool BigInt::operator<(int i) const {
    return *this < BigInt(i);
}

bool operator<(int i, const BigInt &bi) {
    return BigInt(i) < bi;
}

bool BigInt::operator<=(const BigInt &bi) const {
    if (isZero()) {
        return bi.isZero() || bi.sign == SIGN_PLUS;
    } else if (sign == SIGN_PLUS) {
        return bi.sign == SIGN_PLUS && value_compare(&abs_value, &bi.abs_value) <= 0;
    } else {
        return bi.isZero() || bi.sign == SIGN_PLUS || value_compare(&abs_value, &bi.abs_value) >= 0;
    }
}

bool BigInt::operator<=(int i) const {
    return *this <= BigInt(i);
}

bool operator<=(int i, const BigInt &bi) {
    return BigInt(i) <= bi;
}

bool BigInt::operator==(const BigInt &bi) const {
    if (isZero() && bi.isZero()) {
        return true;
    } else {
        return value_compare(&abs_value, &bi.abs_value) == 0 && sign == bi.sign;
    }
}

bool BigInt::operator==(int i) const {
    return *this == BigInt(i);
}

bool operator==(int i, const BigInt &bi) {
    return BigInt(i) == bi;
}

bool BigInt::operator!=(const BigInt &bi) const {
    return !(*this == bi);
}

bool BigInt::operator!=(int i) const {
    return !(*this == i);
}

bool operator!=(int i, const BigInt &bi) {
    return !(bi == i);
}

bool BigInt::operator>=(const BigInt &bi) const {
    return !(*this < bi);
}

bool BigInt::operator>=(int i) const {
    return !(*this < i);
}

bool operator>=(int i, const BigInt &bi) {
    return !(i < bi);
}

bool BigInt::operator>(const BigInt &bi) const {
    return !(*this <= bi);
}

bool BigInt::operator>(int i) const {
    return !(*this <= i);
}

bool operator>(int i, const BigInt &bi) {
    return !(i <= bi);
}

BigInt BigInt::operator<<(int shift) const {
    if (shift == 0) {
        return *this;
    } else if (shift > 0) {
        CoeVector result;
        value_multiply(result, &abs_value, 1 << shift);
        return BigInt(sign, result);
    } else {
        return *this / BigInt(1 << (-shift));
    }
}

BigInt BigInt::operator>>(int shift) const {
    return *this << -shift;
}

char BigInt::flip_sign(char const signum) const {
    if (signum == SIGN_PLUS) {
        return SIGN_MINUS;
    } else {
        return SIGN_PLUS;
    }
}

void BigInt::swap(const CoeVector*& a, const CoeVector*& b) const {
    const CoeVector* tmp = a;
    a = b;
    b = tmp;
}

/**
 * Compare two values
 * the shift is of the power of the base, which is 100
 * so shift is 1, the q is treated as 100*q, shift is 2, q is treated as 10000*q
 */
int BigInt::value_compare(const CoeVector* p, const CoeVector* q, const int shift) const {
    int p_size = p->size();
    int q_size = q->size();

    int cmp = p_size - q_size - shift;

    if (cmp != 0) {
        return cmp;
    }

    for (int i = p_size - 1, j = q_size - 1; cmp == 0 && i >= shift && i >= 0; i--, j--) {
        cmp = (int) (*p)[i] - (*q)[j];
    }

    return cmp;

}

/**
 * Add two values together
 */
void BigInt::value_add(CoeVector& result, const CoeVector* p, const CoeVector* q) const {
    if (q->size() > p->size()) {
        swap(p, q);
    }

    int size_max = p->size();
    int size_common = q->size();
    result.clear();
    result.reserve(size_max);

    int sum = 0;

    for (int i = 0; i < size_common; i++) {
        sum += (*p)[i] + (*q)[i];
        result.push_back(sum % BASE);
        sum /= BASE;
    }

    for (int i = size_common; i < size_max; i++) {
        sum += (*p)[i];
        result.push_back(sum % BASE);
        sum /= BASE;
    }

    if (sum > 0) {
        result.reserve(size_max + 1);
        result.push_back(sum);
    }
}

/**
 * Subtract p from q
 * Precondition: p is bigger or equal to q, i.e. value_compare(p, q) >= 0
 */
void BigInt::value_subtract(CoeVector& result, CoeVector const* p, CoeVector const* q) const {
    int size_max = p->size();
    int size_common = q->size();

    result.clear();
    result.reserve(size_max);

    int i = 0;
    int borrow = 0;

    for (; i < size_common; i++) {
        borrow = borrow + (*p)[i] - (*q)[i];

        if (borrow >= 0) {
            result.push_back(borrow);
        } else {
            result.push_back(borrow + BASE);

            if (borrow + BASE > 0) {
                borrow -= BASE;
            }
        }

        borrow /= BASE;
    }

    for (; i < size_max; i++) {
        borrow = borrow + (*p)[i];

        if (borrow >= 0) {
            result.push_back(borrow);
        } else {
            result.push_back(borrow + BASE);

            if (borrow + BASE > 0) {
                borrow -= BASE;
            }
        }

        borrow /= BASE;
    }

    i--;

    while (i >= 0 && result[i] == 0) {
        i--;
    }

    result.resize(i + 1);
}

/**
 * Multiply two coefficient vectors
 * The result is saved in the result vector
 */
void BigInt::value_multiply(CoeVector& result, const CoeVector* p, const CoeVector* q) const {
    if (q->size() > p->size()) {
        swap(p, q);
    }

    result.clear();

    int p_max = p->size();
    int q_max = q->size();
    int total = p_max + q_max - 1;

    if (p_max <= 0 || q_max <= 0) {
        return;
    }

    result.reserve(total);

    int power = 0;
    unsigned long sum = 0;       // int may be small to hold sum of the same power

    // Collect the like terms
    for (; power < q_max; power++) {
        // i, j are the indices of p and q respectively
        for (int j = power; j >= 0; j--) {
            int i = power - j;
            sum += (*p)[i] * (*q)[j];
        }

        result.push_back(sum % BASE);
        sum /= BASE;
    }

    for (; power < total; power++) {
        // i, j are the indices of p and q respectively
        int j = q_max - 1;
        int i = power - j;

        for (; j >= 0 && i < p_max; --j, ++i) {
            sum += (*p)[i] * (*q)[j];
        }

        result.push_back(sum % BASE);
        sum /= BASE;

    }

    while (sum > 0) {
        result.push_back(sum % BASE);
        sum /= BASE;
    }
}

/**
 * Multiply a coefficient vector with a non negative integer
 * The shifting power is the same as the base
 * See the documentation in value_compare
 */
void BigInt::value_multiply(CoeVector& result, const CoeVector* p, int multiplier, int shift) const {
    result.clear();

    int size = p->size();
    if (multiplier == 0 || size == 0) {
        return;
    }

    if (shift >= 0) {
        result.reserve(size + shift);
    } else {
        result.reserve(size);
    }

    int power = 0;
    unsigned long sum = 0;       // int may be small to hold sum of the same power

    for (; power < size; power++) {
        sum += (*p)[power] * multiplier;

        result.push_back(sum % BASE);
        sum /= BASE;
    }

    while (sum > 0) {
        result.push_back(sum % BASE);
        sum /= BASE;
    }

    if (shift > 0) {
        result.insert(result.begin(), shift, 0);
    } else if (shift < 0) {
        result.erase(result.begin(), result.begin() - shift);
    }
}

/**
 * Divide dividend by divisor
 */
void BigInt::value_divide(CoeVector* quotient, CoeVector* remainder, const CoeVector* dividend,
        const CoeVector* divisor) const {
    // Precondition: dividend > divisor and divisor != 1

    // t=temporary result; q=quotient; r=remainder
    int divisor_power = divisor->size() - 1;
    Coefficient divisor_leading = divisor->back();
    CoeVector r = *dividend;
    CoeVector multiple;
    CoeVector q = CoeVector(dividend->size());
    CoeVector t;

    while (true) {
        int base_shift = r.size() - divisor->size();
        if (base_shift < 0) {
            break;
        }

        int head = r.back();
        int cmp = value_compare(&r, divisor, base_shift);

        if (cmp < 0 && base_shift == 0) {
            break;
        }

        while (cmp < 0) {
            base_shift--;
            cmp = value_compare(&r, divisor, base_shift);
            head *= BASE;
            head += r.at(divisor_power + base_shift);
        }

        int multiplier = head / divisor_leading;

        while (true) {
            value_multiply(multiple, divisor, multiplier, base_shift);
            cmp = value_compare(&r, &multiple);

            if (cmp >= 0) {
                break;
            }

            --multiplier;
        }

        q.at(base_shift) = multiplier;
        value_subtract(t, &r, &multiple);
        r = t;
        head = 0;
    }

    if (quotient != NULL) {
        int back = q.size() - 1;

        for (; back >= 0; --back) {
            if (q[back] != 0) {
                break;
            }
        }

        quotient->clear();
        quotient->reserve(back + 1);

        for (int i = 0; i <= back; i++) {
            quotient->push_back(q[i]);
        }
    }

    if (remainder != NULL) {
        *remainder = r;
    }
}

bool BigInt::isZero() const {
    return abs_value.empty();
}

BigInt BigInt::negate() const {
    if (isZero()) {
        return *this;
    } else {
        return BigInt(flip_sign(sign), abs_value);
    }
}

ostream& operator<<(ostream& os, const BigInt & bi) {
    int count = bi.abs_value.size() * 2 + 2;

    char* cbuf = new char[count];
    bi.write_buffer(cbuf);
    os << cbuf;
    delete[] cbuf;
    return os;
}

istream& operator>>(istream& is, BigInt & bi) {
    char cbuf[CHAR_BUFFER_LENGTH];
    is.get(cbuf, CHAR_BUFFER_LENGTH);

    if (!bi.from_string(cbuf)) {
        is.setstate(ios::failbit);
    }

    return is;
}
