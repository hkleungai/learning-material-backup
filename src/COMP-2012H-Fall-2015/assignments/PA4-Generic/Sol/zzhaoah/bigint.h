/*
 * bigint.h
 */

#ifndef BIGINT_H_
#define BIGINT_H_

#include <vector>
#include <complex>
#include <stdio.h>
#include <cstring>

using namespace std;

class BigInt {
    
public:
    BigInt();
    BigInt(const char *str);
    BigInt(int i);
    BigInt(unsigned long long i);
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
    BigInt operator+(const BigInt &right) const;
    BigInt operator+(const int &right) const;
    
    BigInt operator-(const BigInt &right) const;
    BigInt operator-(const int &right) const;
    
    BigInt operator*(const BigInt &right) const;
    BigInt operator*(const int &right) const;
    
    BigInt operator/(const BigInt &right) const;
    BigInt operator/(const int &right) const;
    
    BigInt operator%(const BigInt &right) const;
    BigInt operator%(const int &right) const;
    
    BigInt &operator=(const BigInt &right);
    BigInt &operator=(const int &right);
    BigInt &operator++();
    BigInt operator++(int);
    BigInt &operator--();
    BigInt operator--(int);
    bool operator>(const BigInt &right) const;
    bool operator>(const int &right) const;
    
    bool operator>=(const BigInt &right) const;
    bool operator>=(const int &right) const;
    
    bool operator<(const BigInt &right) const;
    bool operator<(const int &right) const;
    
    bool operator<=(const BigInt &right) const;
    bool operator<=(const int &right) const;
    
    bool operator==(const BigInt &right) const;
    bool operator==(const int &right) const;
    
    bool operator!=(const BigInt &right) const;
    bool operator!=(const int &right) const;
    
    BigInt &operator<<(const BigInt &leftShift);
    BigInt &operator<<(const int &leftShift);
    
    BigInt &operator>>(const BigInt &rightShift);
    BigInt &operator>>(const int &rightShift);
    
    friend ostream &operator<<(ostream &out,const BigInt &num);
    friend istream &operator>>(istream &in,const BigInt &num);
    
    BigInt pow(BigInt right) const;
    BigInt pow(int right) const;
    BigInt abs() const;
    
    
    
private:
    vector<unsigned short> abs_value;
    char sign;
    bool isAbsLarger(const BigInt &right) const;
    bool isAbsSmaller(const BigInt &right) const;
    bool isAbsSame(const BigInt &right) const;
    unsigned long long integerLength() const;
    void removeLeadingZeros();
    BigInt dec_left_shift(unsigned long b100pow) const;
    BigInt dec_right_shift(unsigned long b100pow) const;
    BigInt bad_log_2() const;
    BigInt invert_fixedP(unsigned long &length) const;
    BigInt _mul_long(const BigInt &right) const;
    BigInt _mul_karatsuba(const BigInt &right) const;
    BigInt _mul_toom3(const BigInt &right) const;
    BigInt _mul_fft(const BigInt &right) const;
    BigInt _div_long(const BigInt &right) const;
    BigInt _div_newton(const BigInt &right) const;
    BigInt _mod_def(const BigInt &right) const;
    BigInt _mod_barett(const BigInt &right) const;
    
};

BigInt operator+(const int &left, const BigInt &right);
BigInt operator-(const int &left, const BigInt &right);
BigInt operator*(const int &left, const BigInt &right);
BigInt operator/(const int &left, const BigInt &right);
BigInt operator%(const int &left, const BigInt &right);
bool operator>(const int &left, const BigInt &right);
bool operator>=(const int &left, const BigInt &right);
bool operator<(const int &left, const BigInt &right);
bool operator<=(const int &left, const BigInt &right);
bool operator==(const int &left, const BigInt &right);
bool operator!=(const int &left, const BigInt &right);
BigInt &operator<<(int &num, const BigInt &leftShift);
BigInt &operator>>(int &num, const BigInt &rightShift);
void fft(std::complex<double> * arr, unsigned long size);
void inversefft(std::complex<double> * arr, unsigned long size);


#endif /* BIGINT_H_ */
