/*
 * bigint.h
 */

#ifndef BIGINT_H_
#define BIGINT_H_

#include <vector>
#include <iostream>

using namespace std;

class BigInt {

public:
    typedef unsigned short Coefficient;
    typedef vector<Coefficient> CoeVector;

    BigInt();
    BigInt(const char *str);
    BigInt(int i);
    BigInt(const BigInt &bi);
    ~BigInt();

    /* #### You need to implement from_string(const char*) and to_string(char*) methods. #### */
    /**
     * Method: void from_string(const char *str)
     * Description:
     * 		from_string method will read the number from str.
     * 		If str is valid, it will be parsed and stored into sign and storage, and then return true. Otherwise, false will be returned.
     */
    bool from_string(const char *str);

    /**
     * Method: void to_string(const char *str)
     * Description:
     * 		to_string method will output the current number to str.
     */
    void to_string(char *str);

    /* #### Please add your overloading methods below. #### */
    BigInt operator+() const;
    BigInt operator-() const;
    BigInt operator+(const BigInt &bi) const;
    BigInt operator+(int i) const;
    BigInt operator-(const BigInt &bi) const;
    BigInt operator-(int i) const;
    BigInt operator*(const BigInt &bi) const;
    BigInt operator*(int i) const;
    BigInt operator/(const BigInt &bi) const;
    BigInt operator/(int i) const;
    BigInt operator%(const BigInt &bi) const;
    BigInt operator%(int i) const;
    BigInt& operator++();
    BigInt operator++(int);
    BigInt& operator--();
    BigInt operator--(int);
    BigInt& operator=(const BigInt &bi);
    BigInt& operator=(int i);
    bool operator<(const BigInt &bi) const;
    bool operator<(int i) const;
    bool operator<=(const BigInt &bi) const;
    bool operator<=(int i) const;
    bool operator==(const BigInt &bi) const;
    bool operator==(int i) const;
    bool operator!=(const BigInt &bi) const;
    bool operator!=(int i) const;
    bool operator>=(const BigInt &bi) const;
    bool operator>=(int i) const;
    bool operator>(const BigInt &bi) const;
    bool operator>(int i) const;
    BigInt operator<<(int shift) const;
    BigInt operator>>(int shift) const;
    friend BigInt operator+(int i, const BigInt & bi);
    friend BigInt operator-(int i, const BigInt & bi);
    friend BigInt operator*(int i, const BigInt & bi);
    friend BigInt operator/(int i, const BigInt & bi);
    friend BigInt operator%(int i, const BigInt & bi);
    friend bool operator<(int i, const BigInt &bi);
    friend bool operator<=(int i, const BigInt &bi);
    friend bool operator==(int i, const BigInt &bi);
    friend bool operator!=(int i, const BigInt &bi);
    friend bool operator>=(int i, const BigInt &bi);
    friend bool operator>(int i, const BigInt &bi);

    friend ostream& operator<<(ostream& out, const BigInt& bi);
    friend istream& operator>>(istream& out, BigInt& bi);

private:
    static Coefficient const BASE = 100;
    CoeVector abs_value;
    char sign;

    BigInt(char signum, vector<unsigned short> value);

    unsigned short char2num(char ch) const;
    char num2char(unsigned short i) const;

    void dump_vector(const CoeVector* u, const CoeVector* v = NULL, int shift = 0) const;
    void write_buffer(char* str) const;

    char flip_sign(char const signum) const;
    void swap(const CoeVector*& a, const CoeVector*& b) const;
    int value_compare(const CoeVector* a, const CoeVector* b, const int shift = 0) const;
    void value_add(CoeVector& result, const CoeVector* a, const CoeVector* b) const;
    void value_subtract(CoeVector& result, const CoeVector* a, const CoeVector* b) const;
    void value_multiply(CoeVector& result, const CoeVector* a, const CoeVector* b) const;
    void value_multiply(CoeVector& result, const CoeVector* a, int b, int shift = 0) const;
    void value_divide(CoeVector* quotient, CoeVector* remainder, const CoeVector* dividend,
            const CoeVector* divisor) const;

    bool isZero() const;
    BigInt negate() const;

    BigInt add(char const signum, CoeVector const* a, CoeVector const* b) const;
    BigInt subtract(CoeVector const* a, CoeVector const* b) const;

};

#endif /* BIGINT_H_ */
