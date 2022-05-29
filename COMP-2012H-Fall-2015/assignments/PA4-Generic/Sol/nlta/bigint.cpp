/**
 * This file contains implementation of the class BigInt
 */

#include "bigint.h"

#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include <iostream>



using namespace std;



/*************************
 * Region Constructor
 ************************/
BigInt::BigInt() {
    abs_value = VDIGITS();
    abs_value.push_back(0);

    sign = POSITIVE;
}



BigInt::BigInt(const BigInt& bi) {
    abs_value = VDIGITS(bi.abs_value);
    sign = bi.sign;
}



BigInt::BigInt(int i) {
    abs_value = VDIGITS();

    if (i < 0) {
        sign = NEGATIVE;
        i = -i;
    } else {
        sign = POSITIVE;
    }

    while (i > 0) {
        abs_value.push_back(i % UNIT);
        i /= UNIT;
    }

    if (abs_value.empty()) {
        abs_value.push_back(0);
    }
}



BigInt::BigInt(const char *str) {
    from_string(str);
}
/*************************
 * EndRegion Constructor
 ************************/



 /*************************
 * Region Destructor
 ************************/
 BigInt::~BigInt() {
    abs_value.clear();
 }
 /*************************
 * EndRegion Destructor
 ************************/



/*********************************************************
 * Region Public Methods
 *********************************************************/
bool BigInt::from_string(const char *str) {
    abs_value = VDIGITS();
    sign = POSITIVE;

    int len = strlen(str);

    if (len == 0) {
        *this = BigInt();

        return true;
    }

    if (str[0] == '-') {
        sign = NEGATIVE;
    }

    int start = 0;

    if (str[0] == '-' || str[0] == '+') {
        start = 1;
    }

    int d = 0, u = 1;

    for (int i = len - 1; i >= start; --i) {
        if ('0' <= str[i] && str[i] <= '9') {
            if (u == UNIT) {
                abs_value.push_back(d);

                d = (str[i] - '0');
                u = 10;
            } else {
                d += (str[i] - '0') * u;
                u *= 10;
            }
        } else {
            *this = BigInt();

            return false;
        }
    }

    abs_value.push_back(d);

    trimHeadingZero(*this);

    return true;
}



void BigInt::to_string(char *str) const {
    stringstream ss;
    string output;

    if (sign == NEGATIVE) {
        ss << "-";
    }

    ss << *abs_value.rbegin();

    for (int i = abs_value.size() - 2; i >= 0; --i)
        ss << setfill('0') << setw(UNIT_WIDTH) << abs_value[i];

    output = ss.str();
    memcpy(str, output.c_str(), output.length() + 1);
}



bool BigInt::divide(const BigInt& rhs, BigInt& quo, BigInt& rem) const {
    ///Special Case: Divided by zero
    if (rhs == 0) {
        quo = 0;
        rem = 0;
        return false;
    }

    ///Trivial Case: When the dividend (*this) is zero
    if (*this == 0) {
        quo = 0;
        rem = 0;
        return true;
    }

    char quoSign, remSign;

    ///Determine the sign of the quotient and the remainder
    if (this->sign == POSITIVE && rhs.sign == POSITIVE) {
        quoSign = POSITIVE;
        remSign = POSITIVE;
    } else if (this->sign == POSITIVE && rhs.sign == NEGATIVE) {
        quoSign = NEGATIVE;
        remSign = POSITIVE;
    } else if (this->sign == NEGATIVE && rhs.sign == POSITIVE) {
        quoSign = NEGATIVE;
        remSign = NEGATIVE;
    } else {
        quoSign = POSITIVE;
        remSign = NEGATIVE;
    }

    int cmp;

    cmp = compare(rhs, true);

    ///Trivial Case: Dividend (*this) < Divisor (rhs)
    if (cmp == -1) {
        quo = BigInt(0);
        rem = *this;

        return true;
    }

    ///Trivial Case: Dividend (*this) == Divisor (rhs)
    if (cmp == 0) {
        quo = BigInt(1);
        quo.sign = quoSign;

        rem = BigInt(0);

        return true;
    }

    /**
     * Until this part, only normal case: Divident (*this) > Divisor (rhs)
     * Find the quotient using binary search
     * Although this approach have the same computing complexity with the "classical" approach,
     * it is easier to code and make use of previously implemented * operator and Karatsuba
     * quick multiplication algorithm
     */

    int diff = this->abs_value.size() - rhs.abs_value.size();
    BigInt lo, hi, mid;

    lo = powUNIT(diff);

    cmp = compare(rhs * lo, true);

    if (cmp == 0) {
        quo = lo;
        quo.sign = quoSign;
        rem = BigInt(0);

        return true;
    } else if (cmp == -1) {
        hi = lo;
        lo = powUNIT(diff - 1);
    } else {
        hi = powUNIT(diff + 1);
    }

    int dummy;

    while (lo + 1 < hi) {
        BigInt(lo + hi).divideBy2(mid, dummy);

        cmp = compare(rhs * mid, true);

        if (cmp == 0) {
            quo = mid;
            quo.sign = quoSign;
            rem = BigInt(0);

            return true;
        } else if (cmp == -1) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    if (compare(rhs * hi, true) >= 0) {
        quo = hi;
    } else {
        quo = lo;
    }

    subtractAbsPositive(*this, quo * rhs, rem);
    trimHeadingZero(rem);

    quo.sign = quoSign;
    rem.sign = remSign;

    return true;
}



void BigInt::divideBy2(BigInt& quo, int& rem) const {
    quo.sign = this->sign;
    quo.abs_value.clear();

    rem = 0;

    int dividend;

    for (int i = this->abs_value.size() - 1; i >= 0; --i) {
        dividend = rem * UNIT + this->abs_value[i];
        quo.abs_value.push_back(dividend / 2);
        rem = dividend % 2;
    }

    reverse(quo.abs_value.begin(), quo.abs_value.end());
    trimHeadingZero(quo);
}

/*********************************************************
 * EndRegion Public Methods
 *********************************************************/



/*********************************************************
 * Region In-class Operators
 *********************************************************/
BigInt BigInt::operator + (const BigInt& rhs) const {
    BigInt res;

    if (this->sign == rhs.sign) {
        res.sign = sign;

        int len = max(this->abs_value.size(), rhs.abs_value.size());

        res.abs_value = VDIGITS(len);

        int sum;
        int carry = 0;

        for (int i = 0; i < len; ++i) {
            sum = carry;

            if (i < this->abs_value.size()) {
                sum += this->abs_value[i];
            }

            if (i < rhs.abs_value.size()) {
                sum += rhs.abs_value[i];
            }

            if (sum >= UNIT) {
                res.abs_value[i] = sum - UNIT;
                carry = 1;
            } else {
                res.abs_value[i] = sum;
                carry = 0;
            }
        }

        if (carry > 0) {
            res.abs_value.push_back(carry);
        }
    } else {
        BigInt *realLHS;
        BigInt *realRHS;

        int cmp = compare(rhs, true);

        if (cmp == 1) {
            subtractAbsPositive(*this, rhs, res);
            res.sign = this->sign;
        } else if (cmp == -1) {
            subtractAbsPositive(rhs, *this, res);
            res.sign = rhs.sign;
        }
    }

    trimHeadingZero(res);

    return res;
}



BigInt BigInt::operator + (const int& rhs) const {
    return (*this) + BigInt(rhs);
}



BigInt BigInt::operator - (const BigInt& rhs) const {
    return (*this) + (-rhs);
}


BigInt BigInt::operator - (const int& rhs) const {
    return (*this) + (-rhs);
}



BigInt BigInt::operator * (const BigInt& rhs) const {
    BigInt res = karatsubaMultiply(*this, rhs);

    if (this->sign == rhs.sign) {
        res.sign = POSITIVE;
    } else {
        res.sign = NEGATIVE;
    }

    if (res.abs_value.size() == 1 && res.abs_value[0] == 0) {
        res.sign = POSITIVE;
    }

    return res;
}



BigInt BigInt::operator * (const int& rhs) const {
    return (*this) * BigInt(rhs);
}



BigInt BigInt::operator / (const BigInt& rhs) const {
    BigInt quo, rem;

    divide(rhs, quo, rem);
    return quo;
}



BigInt BigInt::operator / (const int& rhs) const {
    return (*this) / BigInt(rhs);
}



BigInt BigInt::operator % (const BigInt& rhs) const {
    BigInt quo, rem;

    divide(rhs, quo, rem);
    return rem;
}



BigInt BigInt::operator % (const int& rhs) const {
    return (*this) % BigInt(rhs);
}



BigInt& BigInt::operator = (const BigInt& rhs) {
    if (this == &rhs) {
        return *this;
    }

    sign = rhs.sign;
    abs_value = rhs.abs_value;

    return *this;
}


BigInt& BigInt::operator = (const int& rhs) {
    *this = BigInt(rhs);

    return *this;
}



///Prefix Increment Operator
BigInt& BigInt::operator ++ () {
    *this = *this + 1;

    return *this;
}



///Prefix Decrement Operator
BigInt& BigInt::operator -- () {
    *this = *this - 1;

    return *this;
}



///Postfix Increment Operator
BigInt BigInt::operator ++ (int dummy) {
    BigInt res = *this;

    ++(*this);

    return res;
}



///Postfix Decrement Operator
BigInt BigInt::operator -- (int dummy) {
    BigInt res = *this;

    --(*this);

    return res;
}



///Unary Minus Operator
BigInt BigInt::operator - () const {
    BigInt res = *this;

    if (res.sign == NEGATIVE) {
        res.sign = POSITIVE;
    } else if (res.abs_value.size() > 1 ||
            (res.abs_value.size() == 1  && res.abs_value[0] != 0)) {
        res.sign = NEGATIVE;
    }

    return res;
}



bool BigInt::operator > (const BigInt& rhs) const {
    return compare(rhs) == 1;
}


bool BigInt::operator > (const int& rhs) const {
    return compare(BigInt(rhs)) == 1;
}



bool BigInt::operator >= (const BigInt& rhs) const {
    return compare(rhs) >= 0;
}


bool BigInt::operator >= (const int& rhs) const {
    return compare(BigInt(rhs)) >= 0;
}



bool BigInt::operator < (const BigInt& rhs) const {
    return compare(rhs) == -1;
}


bool BigInt::operator < (const int& rhs) const {
    return compare(BigInt(rhs)) == -1;
}



bool BigInt::operator <= (const BigInt& rhs) const {
    return compare(rhs) <= 0;
}



bool BigInt::operator <= (const int& rhs) const {
    return compare(BigInt(rhs)) <= 0;
}



bool BigInt::operator == (const BigInt& rhs) const {
    return compare(rhs) == 0;
}



bool BigInt::operator == (const int& rhs) const {
    return compare(BigInt(rhs)) == 0;
}



bool BigInt::operator != (const BigInt& rhs) const {
    return compare(rhs) != 0;
}



bool BigInt::operator != (const int& rhs) const {
    return compare(BigInt(rhs)) != 0;
}
/*********************************************************
 * EndRegion In-class Operators
 *********************************************************/



/*******************************************************************************************
* Region In-class function
*******************************************************************************************/
void BigInt::trimHeadingZero(BigInt& b) const {
    while (b.abs_value.size() > 0 && *(b.abs_value.rbegin()) == 0) {
       b.abs_value.pop_back();
   }

   if (b.abs_value.empty()) {
       b = BigInt();
   }
}



int BigInt::compare(const BigInt& rhs, bool compareAbsolute) const {
    if (!compareAbsolute) {
        if (this->sign == POSITIVE && rhs.sign == NEGATIVE) {
            return 1;
        }

        if (this->sign == NEGATIVE && rhs.sign == POSITIVE) {
            return -1;
        }
    }

    int res;

    if (!compareAbsolute && this->sign == NEGATIVE && rhs.sign == NEGATIVE) {
        res = -1;
    } else {
        res = 1;
    }

    if (this->abs_value.size() > rhs.abs_value.size()) {
        return res;
    }

    if (this->abs_value.size() < rhs.abs_value.size()) {
        return -res;
    }

    for (int i = this->abs_value.size() - 1; i >= 0; --i) {
        if (this->abs_value[i] > rhs.abs_value[i]) {
            return res;
        }

        if (this->abs_value[i] < rhs.abs_value[i]) {
            return -res;
        }
    }

    return 0;
}



void BigInt::subtractAbsPositive(const BigInt& lhs, const BigInt& rhs, BigInt& res) const {
   int len = lhs.abs_value.size();
   res.abs_value = VDIGITS(len, 0);

   int sub;
   int carry = 0;

   for (int i = 0; i < len; ++i) {
       sub = lhs.abs_value[i] - carry;

       if (i < rhs.abs_value.size()) {
           sub -=  rhs.abs_value[i];
       }

       if (sub < 0) {
           res.abs_value[i] = sub + UNIT;
           carry = 1;
       } else {
           res.abs_value[i] = sub;
           carry = 0;
       }
   }
}



BigInt BigInt::karatsubaMultiply(const BigInt& lhs, const BigInt& rhs) const {
    int llen = lhs.abs_value.size();
    int rlen = rhs.abs_value.size();

    ///This function assumes that the the number of digits of rhs does not exceeds that of lhs
    ///Therefore, swap the position of lhs and rhs if necessary
    if (llen < rlen) {
        return karatsubaMultiply(rhs, lhs);
    }

    BigInt res;
    res.abs_value = VDIGITS(llen + rlen + 3);

    int sum, carry;

    if (llen < KARATSUBA_THRESHOLD || rlen < KARATSUBA_THRESHOLD) {     ///Use normal multiplication when the number size is small enough
        for (int i = 0; i < rlen; ++i) {
            if (rhs.abs_value[i] == 0) {
                continue;
            }

            carry = 0;

            for (int j = 0; j < llen; ++j) {
                sum = rhs.abs_value[i] * lhs.abs_value[j] + res.abs_value[i + j] + carry;
                res.abs_value[i + j] = sum % UNIT;
                carry = sum / UNIT;
            }

            for (int j = llen; i + j < res.abs_value.size() && carry > 0; ++j) {
                sum = res.abs_value[i + j] + carry;
                res.abs_value[i + j] = sum % UNIT;
                carry = sum / UNIT;
            }
        }
    } else {    ///Otherwise, use Karatsuba Multiplication with recursion
        int m = llen / 2;

        BigInt x1, x0, y1, y0;

        x0.abs_value = DigitsFromRange(lhs.abs_value, 0, m);
        x1.abs_value = DigitsFromRange(lhs.abs_value, m, llen);

        if (rlen <= m) {
            y0.abs_value = rhs.abs_value;
        } else {
            y0.abs_value = DigitsFromRange(rhs.abs_value, 0, m);
            y1.abs_value = DigitsFromRange(rhs.abs_value, m, rlen);
        }

        BigInt z[3];
        z[0] = karatsubaMultiply(x0, y0);
        z[2] = karatsubaMultiply(x1, y1);

        z[1].abs_value = VDIGITS(z[0].abs_value.size() + 1, 0);
        subtractAbsPositive(karatsubaMultiply(x0 + x1, y0 + y1), z[0] + z[2], z[1]);
        trimHeadingZero(z[1]);

        for (int i = 0; i <= 2; ++i) {
            carry = 0;

            for (int j = 0; j < z[i].abs_value.size(); ++j) {
                sum = res.abs_value[m * i + j] + z[i].abs_value[j] + carry;
                res.abs_value[m * i + j] = sum % UNIT;
                carry = sum / UNIT;
            }

            if (carry > 0) {
                res.abs_value[m * i + z[i].abs_value.size()] += carry;
            }
        }
    }

    carry = 0;
    for (VDIGITS::iterator it = res.abs_value.begin(); it!= res.abs_value.end(); ++it) {
        sum = *it + carry;
        *it = sum % UNIT;
        carry = sum / UNIT;
    }

    trimHeadingZero(res);

    return res;
}



VDIGITS BigInt::DigitsFromRange(const VDIGITS& d, int first, int last) const {
    --last;

    while (last > first && d[last] == 0) {
        --last;
    }

    ++last;

    return VDIGITS(d.begin() + first, d.begin() + last);
}



BigInt BigInt::powUNIT(int p) const {
    BigInt res;
    res.abs_value = VDIGITS(p, 0);

    res.abs_value.push_back(1);

    return res;
}

/*******************************************************************************************
* EndRegion In-class function
*******************************************************************************************/



/*********************************************************
 * Region Global Operators
 *********************************************************/
BigInt operator + (const int& lhs, const BigInt& rhs) {
    return rhs + lhs;
}



BigInt operator - (const int& lhs, const BigInt& rhs) {
    return -(rhs - lhs);
}



BigInt operator * (const int& lhs, const BigInt& rhs) {
    return rhs * lhs;
}



BigInt operator / (const int& lhs, const BigInt& rhs) {
    return BigInt(lhs) / rhs;
}



BigInt operator % (const int& lhs, const BigInt& rhs) {
    return BigInt(lhs) % rhs;
}



bool operator < (const int& lhs, const BigInt& rhs) {
    return rhs > lhs;
}


bool operator <= (const int& lhs, const BigInt& rhs) {
    return rhs >= lhs;
}



bool operator > (const int& lhs, const BigInt& rhs) {
    return rhs < lhs;
}



bool operator >= (const int& lhs, const BigInt& rhs) {
    return rhs <= lhs;
}



bool operator == (const int& lhs, const BigInt& rhs) {
    return rhs == lhs;
}



bool operator != (const int& lhs, const BigInt& rhs) {
    return rhs != lhs;
}



///Right bit-shifting Operator
BigInt operator >> (const BigInt& lhs, const BigInt& rhs) {
    if (rhs < 0) {
        return lhs << (-rhs);
    } else {
        return lhs / pow2(rhs);
    }
}



///Right bit-shifting Operator
BigInt operator >> (const BigInt& lhs, const int& rhs) {
    return lhs >> BigInt(rhs);
}



///Left bit-shifting Operator
BigInt operator << (const BigInt& lhs, const BigInt& rhs) {
    if (rhs < 0) {
        return lhs >> (-rhs);
    } else {
        return lhs * pow2(rhs);
    }
}



///Left bit-shifting Operator
BigInt operator << (const BigInt& lhs, const int& rhs) {
    return lhs << BigInt(rhs);
}



///Input-stream Operator
istream& operator >> (istream& in, BigInt& bi) {
    string str;
    in >> str;

    bi = BigInt(str.c_str());

    return in;
}



///Output-stream Operator
ostream& operator << (ostream& out, const BigInt& bi) {
    char *str = new char[800001];
    bi.to_string(str);

    out << string(str);

    delete [] str;

    return out;
}
/*********************************************************
 * EndRegion Global Operators
 *********************************************************/



/**********************************************************************
 * Region Global Helper Function
 **********************************************************************/
BigInt pow2(BigInt p) {
    if (p < 0) {
        return BigInt();
    }

    BigInt res = BigInt(1);

    BigInt quo;
    int rem;
    BigInt accum = BigInt(2);

    while (p > 0) {
        p.divideBy2(quo, rem);

        if (rem == 1) {
            res = res * accum;
        }

        accum = accum * accum;

        p = quo;
    }

    return res;
}

/**********************************************************************
 * EndRegion Global operator
 **********************************************************************/
