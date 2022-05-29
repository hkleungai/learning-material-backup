//
//  bigint.cpp
//  PA4
//
//  Created by Felix Zhao on 30/10/2015.
//  Copyright © 2015 Felix Zhao. All rights reserved.
//
#include <vector>
#include <math.h>
#include <iostream>
#include <sstream>
#include "bigint.h"


BigInt::BigInt(){
    sign = '+';
}
BigInt::BigInt(const char *str){
    if (!from_string(str)) {
        std::cout<<"invalid input"<<std::endl;
    }
}
BigInt::BigInt(int i){
    if (i < 0) {
        sign = '-';
        i = -i;
    }else {
        sign = '+';
    }
    while (i >= 100) {
        abs_value.push_back(i%100);
        i = i / 100;
    }
    abs_value.push_back(i);
}

BigInt::BigInt(unsigned long long i){
    sign = '+';
    while (i >= 100) {
        abs_value.push_back(i%100);
        i = i / 100;
    }
    abs_value.push_back(i);
}

BigInt::BigInt(const BigInt &bi){
    abs_value = bi.abs_value;
    sign = bi.sign;
}
BigInt::~BigInt(){
    //empty destructor
}


bool BigInt::from_string(const char *str){
    unsigned long strlength = strlen(str);
    //check if the dirst character is valid
    if (str[0]!='+'&&str[0]!='-'&&!(str[0]>='0'&&str[0]<='9'))
        return false;
    //record the length of the number
    int startingIndex = 0;
    if (str[0]=='+') {
        sign = '+';
        startingIndex++;
    }else if(str[0]=='-'){
        sign = '-';
        startingIndex++;
    }else{
        sign = '+';
    }
    //check if all the rest characters are valid
    for (unsigned long i = startingIndex; i < strlen(str);i++) {
        if (!(str[i]>='0'&&str[i]<='9'))
            return false;
    }
    //remove leading 0
    while (str[startingIndex]=='0' && startingIndex < strlength - 1)
        startingIndex++;
    //read number
    switch ((strlength-startingIndex)%2) {
        case 0:
            for (long long i = strlength - 1; i >= startingIndex + 1; i-=2) {
                abs_value.push_back((str[i-1]-'0')*10+str[i]-'0');
            }
            break;
            
        case 1:
            for (long long i = strlength - 1; i >= startingIndex + 2; i-=2) {
                abs_value.push_back((str[i-1]-'0')*10+str[i]-'0');
            }
            abs_value.push_back(str[startingIndex]-'0');
            break;
    }
    return true;
}


void BigInt::to_string(char *str){
    //clear the char[] array
    str[0]='\0';
    //print the sign
    if (sign == '-'&&!isAbsSame(0))
        strcat(str, "-");
    //print the number
    unsigned long vecsize = abs_value.size();
    char temp[3];
    sprintf(temp, "%d", abs_value[vecsize-1]);
    strcat(str, temp);
    for (unsigned long i = 1; i < vecsize; i++){
        char temp[3];
        sprintf(temp, "%d", abs_value[vecsize-i-1]);
        if (temp[1]=='\0') {
            temp[2]='\0';
            temp[1]=temp[0];
            temp[0]='0';
        }
        strcat(str, temp);
    }
}


BigInt BigInt::operator+(const BigInt &right) const{
    BigInt result;
    //determine what operation should be used
    char flag;
    if (sign=='+'&&right.sign=='+'){
        result.sign='+';
        flag = '+';
    }else if (sign=='-'&&right.sign=='-'){
        result.sign='-';
        flag = '+';
    }else {
        flag = '-';
    }
    //calculation
    
    //mark the longer one and the shorter one
    const BigInt * larger = &right;
    const BigInt * smaller = this;
    if (abs_value.size()<right.abs_value.size()) {
        larger = &right;
        smaller = this;
    } else {
        larger = this;
        smaller = &right;
    }
    switch (flag) {
        case '+': // ordinary plus
        {//define a scope
            bool carrybit = false;
            for (unsigned long i = 0; i < smaller->abs_value.size(); i++) {
                
                unsigned short temp = larger->abs_value[i] + smaller->abs_value[i] + carrybit;
                if (temp>=100) {
                    result.abs_value.push_back(temp-100);
                    carrybit = true;
                } else {
                    result.abs_value.push_back(temp);
                    carrybit = false;
                }
            }
            if (abs_value.size()==right.abs_value.size()) {
                if (carrybit)
                    result.abs_value.push_back(1);
            } else {
                for (unsigned long i = smaller->abs_value.size(); i < larger->abs_value.size(); i++) {
                    unsigned short temp = larger->abs_value[i] + carrybit;
                    if (temp>=100) {
                        result.abs_value.push_back(temp-100);
                        carrybit = true;
                    } else {
                        result.abs_value.push_back(temp);
                        carrybit = false;
                    }
                }
                if (carrybit)
                    result.abs_value.push_back(1);
            }
            break;
        }
        case '-':
        {
            //determine sign
            if (isAbsSame(right)) {
                result.abs_value.push_back(0);
                return result;
            }
            if (isAbsLarger(right)) {
                result.sign = sign;
            }else{
                result.sign = right.sign;
            }
            //mark the longer one and the shorter one
            const BigInt * larger = &right;
            const BigInt * smaller = this;
            if (isAbsSmaller(right)) {
                larger = &right;
                smaller = this;
            } else {
                larger = this;
                smaller = &right;
            }
            //subtract operation
            bool borrowbit = false;
            for (unsigned long i = 0; i < smaller->abs_value.size(); i++) {
                unsigned short temp = larger->abs_value[i] - smaller->abs_value[i] - borrowbit + 100;
                if (temp>=100) {
                    result.abs_value.push_back(temp-100);
                    borrowbit = false;
                } else {
                    result.abs_value.push_back(temp);
                    borrowbit = true;
                }
            }
            if (larger->abs_value.size() > smaller->abs_value.size()) {
                for (unsigned long i = smaller->abs_value.size(); i < larger->abs_value.size(); i++) {
                    unsigned short temp = larger->abs_value[i] - borrowbit + 100;
                    if (temp>=100) {
                        result.abs_value.push_back(temp-100);
                        borrowbit = false;
                    } else {
                        result.abs_value.push_back(temp);
                        borrowbit = true;
                    }
                }
            }
            
        }
            result.removeLeadingZeros();
            break;
    }
    
    return result;
}
BigInt BigInt::operator+(const int &right) const{
    return *this+BigInt(right);
}

BigInt BigInt::operator-(const BigInt &right) const{
    BigInt right2(right);
    //change sign and call plus
    if (right.sign=='+') {
        right2.sign = '-';
    }else{
        right2.sign = '+';
    }
    return *this + right2;
}
BigInt BigInt::operator-(const int &right) const{
    return *this - BigInt(right);
}

BigInt BigInt::abs() const{
    BigInt result(*this);
    result.sign = '+';
    return result;
}

void BigInt::removeLeadingZeros(){
    while (abs_value.back()==0&&abs_value.size() > 1) {
        abs_value.pop_back();
    }
}

BigInt BigInt::dec_left_shift(unsigned long b100pow) const{
	//This function returns number * 100 ^ b100pow with high efficiency
    BigInt result(*this);
    if (*this == 0) {
        return BigInt(0);
    }
    while (b100pow) {
        result.abs_value.insert(result.abs_value.begin(), 0);
        --b100pow;
    }
    return result;
}

BigInt BigInt::dec_right_shift(unsigned long b100pow) const{
	//This function returns number / 100 ^ b100pow with high efficiency
    BigInt result(*this);
    if (*this == 0) {
        return BigInt(0);
    }
    while (b100pow) {
        result.abs_value.erase(result.abs_value.begin());
        if (result.abs_value.size()==0) {
            result.abs_value.push_back(0);
            return result;
        }
        --b100pow;
    }
    return result;
}

BigInt BigInt::_mul_long(const BigInt &right) const{
	//This is the school book long multiplication algorithm
    BigInt result;
    for (unsigned long i = 0; i < right.abs_value.size(); i++) {
        result = result + (*this * int(right.abs_value[i])).dec_left_shift(i);
    }
    return result;
}

BigInt BigInt::_mul_karatsuba(const BigInt &right) const{
    //mark the longer one and the shorter one
    const BigInt * larger = &right;
    const BigInt * smaller = this;
    if (isAbsSmaller(right)) {
        larger = &right;
        smaller = this;
    } else {
        larger = this;
        smaller = &right;
    }
    //base case
    if (*smaller < 10000 )
        return larger->_mul_long(*smaller);
    //split the integers at half of larger integer size
    unsigned long halfMaxPos = (larger->abs_value.size())/2;
    BigInt high1; BigInt low1;
    for (unsigned long i = 0; i < halfMaxPos; i++)
        low1.abs_value.push_back(larger->abs_value[i]);
    low1.removeLeadingZeros();
    for (unsigned long i = halfMaxPos; i < larger->abs_value.size(); i++)
        high1.abs_value.push_back(larger->abs_value[i]);
    high1.removeLeadingZeros();
    BigInt high2; BigInt low2;
    if (smaller->abs_value.size() <= halfMaxPos) {
        for (unsigned long i = 0; i < smaller->abs_value.size(); i++)
            low2.abs_value.push_back(smaller->abs_value[i]);
        low2.removeLeadingZeros();
        high2 = 0;
    }else{
        for (unsigned long i = 0; i < halfMaxPos; i++)
            low2.abs_value.push_back(smaller->abs_value[i]);
        low2.removeLeadingZeros();
        for (unsigned long i = halfMaxPos; i < smaller->abs_value.size(); i++)
            high2.abs_value.push_back(smaller->abs_value[i]);
        high2.removeLeadingZeros();
    }
    //solve the subproblems
    BigInt z0(low1._mul_karatsuba(low2));
    BigInt z1((low1+high1)._mul_karatsuba(low2+high2));
    BigInt z2(high1._mul_karatsuba(high2));
    return (z2.dec_left_shift(2*halfMaxPos))+((z1-z2-z0).dec_left_shift(halfMaxPos))+(z0);
}
BigInt BigInt::_mul_toom3(const BigInt &right) const{
    //Algorithm description
    //https://en.wikipedia.org/wiki/Toom–Cook_multiplication
    
    //mark the longer one and the shorter one
    const BigInt * larger = &right;
    const BigInt * smaller = this;
    if (isAbsSmaller(right)) {
        larger = &right;
        smaller = this;
    } else {
        larger = this;
        smaller = &right;
    }
    //base case, call other algorithms
    if (*smaller < BigInt("1000000000000") )
        return larger->_mul_karatsuba(*smaller);
    
    //step 1: splitting (into 3 parts)
    unsigned long splitPosLow = larger->abs_value.size()/3+1;
    unsigned long splitPosHigh = 2 * splitPosLow;
    BigInt m0; BigInt m1; BigInt m2;
    for (unsigned long i = 0; i < splitPosLow; i++)
        m0.abs_value.push_back(larger->abs_value[i]);
    m0.removeLeadingZeros();
    for (unsigned long i = splitPosLow; i < splitPosHigh; i++)
        m1.abs_value.push_back(larger->abs_value[i]);
    m1.removeLeadingZeros();
    for (unsigned long i = splitPosHigh; i < larger->abs_value.size(); i++)
        m2.abs_value.push_back(larger->abs_value[i]);
    m2.removeLeadingZeros();
    BigInt n0; BigInt n1; BigInt n2;
    if (smaller->abs_value.size() <= splitPosLow) {
        for (unsigned long i = 0; i < smaller->abs_value.size(); i++)
            n0.abs_value.push_back(smaller->abs_value[i]);
        n0.removeLeadingZeros();
        n1 = 0; n2 = 0;
    }else if (smaller->abs_value.size() <= splitPosHigh) {
        for (unsigned long i = 0; i < splitPosLow; i++)
            n0.abs_value.push_back(smaller->abs_value[i]);
        n0.removeLeadingZeros();
        for (unsigned long i = splitPosLow; i < smaller->abs_value.size(); i++)
            n1.abs_value.push_back(smaller->abs_value[i]);
        n1.removeLeadingZeros();
        n2 = 0;
    }else{
        for (unsigned long i = 0; i < splitPosLow; i++)
            n0.abs_value.push_back(smaller->abs_value[i]);
        n0.removeLeadingZeros();
        for (unsigned long i = splitPosLow; i < splitPosHigh; i++)
            n1.abs_value.push_back(smaller->abs_value[i]);
        n1.removeLeadingZeros();
        for (unsigned long i = splitPosHigh; i < smaller->abs_value.size(); i++)
            n2.abs_value.push_back(smaller->abs_value[i]);
        n2.removeLeadingZeros();
    }
    //step 2: point evaluation
    /* Calculates the product of 2 polynomials by point multiplication
     * This algorithm chooses 5 points: 0, 1, -1, -2, inf
     * where p(inf)=m2, q(inf)=n2
     * p(0)=m0, p(1)=m0+m1+m2, p(-1)=m0-m1+m2, p(-2)=m0-2m1+4m2
     */
    BigInt p_temp(m0+m2);
    BigInt p_0(m0);
    BigInt p_1(p_temp+m1);
    BigInt p_min1(p_temp-m1);
    BigInt p_min2((p_min1+m2)*2-m0);
    BigInt p_inf(m2);
    
    BigInt q_temp(n0+n2);
    BigInt q_0(n0);
    BigInt q_1(q_temp+n1);
    BigInt q_min1(q_temp-n1);
    BigInt q_min2((q_min1+n2)*2-n0);
    BigInt q_inf(n2);
    
    //step 3: point-wise multiplication
    BigInt r_0(p_0 * q_0);
    BigInt r_1(p_1 * q_1);
    BigInt r_min1(p_min1 * q_min1);
    BigInt r_min2(p_min2 * q_min2);
    BigInt r_inf(p_inf * q_inf);
    
    //step 4: interpolation
    BigInt r0(r_0);
    BigInt r4(r_inf);
    BigInt r3((r_min2-r_1)/3); //not finalized
    BigInt r1((r_1-r_min1)/2); //not finalized
    BigInt r2(r_min1-r_0); //not finalized
    r3 = (r2-r3)/2 + 2* r_inf;
    r2 = r2 + r1 - r4;
    r1 = r1 - r3;
    
    //step 5: recomposition
    
    BigInt result(r0 + r1.dec_left_shift(splitPosLow) + r2.dec_left_shift(splitPosLow * 2) + r3.dec_left_shift(splitPosLow * 3) + r4.dec_left_shift(splitPosLow * 4));
    return result;
}

void fft(std::complex<double> * arr, unsigned long size)
{
    //Cooley–Tukey FFT
    //base case, fft of one element is itself
    if (size <= 1) return;
    //divide even and odd terms
    std::complex<double> *even = new std::complex<double>[size/2+size%2];
    std::complex<double> *odd = new std::complex<double>[size/2];
    unsigned long evenInd = 0;
    unsigned long oddInd = 0;
    for (unsigned long i = 0; i < size; i++) {
        if (i%2==0) {
            even[evenInd] = arr[i];
            ++evenInd;
        }else{
            odd[oddInd] = arr[i];
            ++oddInd;
        }
    }
    
    //call subproblems
    fft(even, size/2+size%2);
    fft(odd, size/2);
    
    //combine subproblems
    for (unsigned long i = 0; i < size/2; i++){
        std::complex<double> t = std::polar(1.0, -2 * 3.14159265358979323846 * i / size) * odd[i];
        arr[i] = even[i] + t;
        arr[i+size/2] = even[i] - t;
    }
    //delete dynamic allocated array
    delete[] even;
    delete[] odd;
}

void inversefft(std::complex<double> * arr, unsigned long size){
	//performs the inverse fft
    for (unsigned long i = 0; i < size; i++) {
        arr[i] = std::conj(arr[i]);
    }
    
    fft(arr, size);
    
    for (unsigned long i = 0; i < size; i++) {
        arr[i] = std::conj(arr[i]);
    }
    
    for (unsigned long i = 0; i < size; i++) {
        arr[i] /= size;
    }
}

BigInt BigInt::_mul_fft(const BigInt &right) const{
	//pad the length of the problem to a power of 2
    unsigned long actualRSize = abs_value.size()+right.abs_value.size();
    unsigned long resultSize = 2<<int(log2(actualRSize));
    //p means *this and q means right
    //do fft for the two polynomials, O(n*log(n))
    std::complex<double> * pfft = new std::complex<double>[resultSize];
    for (unsigned long i = 0; i < abs_value.size(); i++) {
        pfft[resultSize-i-1] = abs_value[i];
    }
    for (unsigned long i = abs_value.size(); i < resultSize; i++) {
        pfft[resultSize-i-1] = 0.0;
    }
    fft(pfft, resultSize);
    std::complex<double> * qfft = new std::complex<double>[resultSize];
    for (unsigned long i = 0; i < right.abs_value.size(); i++) {
        qfft[resultSize-i-1] = right.abs_value[i];
    }
    for (unsigned long i = right.abs_value.size(); i < resultSize; i++) {
        qfft[resultSize-i-1] = 0.0;
    }
    fft(qfft, resultSize);
    //point wise multiplication, O(n)
    std::complex<double> * rfft = new std::complex<double>[resultSize];
    for (unsigned long i = 0; i < resultSize; i++) {
        rfft[i] = pfft[i] * qfft[i];
    }
    //use inverse fft to transform back, O(n*log(n))
    inversefft(rfft, resultSize);
    delete[] pfft;
    delete[] qfft;
    //if you change unsigned long to unsigned long long, the max of the correct answer of fft can increase
    std::vector<unsigned long> uncarriedResult;
    for (unsigned long i = 0; i < actualRSize; i++) {
        uncarriedResult.push_back(rfft[resultSize - 2 - i].real()+0.01);
    }
    delete[] rfft;
    //carry process
    unsigned long carry = 0;
    for (unsigned long i = 0; i < uncarriedResult.size(); i++) {
        uncarriedResult[i] += carry;
        carry = 0;
        if(uncarriedResult[i]>=100){
            carry = uncarriedResult[i]/100;
            uncarriedResult[i] = uncarriedResult[i]%100;
        }
    }
    while (carry) {
        uncarriedResult.push_back(carry%100);
        carry /= 100;
    }
    //put result into short arrays after carrying
    BigInt result;
    for (unsigned long i = 0; i < uncarriedResult.size(); i++) {
        result.abs_value.push_back((unsigned short)uncarriedResult[i]);
    }
    result.removeLeadingZeros();
    return result;
}

BigInt BigInt::operator*(const BigInt &right) const{
    BigInt result;
    //multiplication calls different algorithms based on the benchmark test
    if (abs_value.size() > 6){
        result = this->abs()._mul_fft(right.abs());
    }else{
        result = this->abs()._mul_long(right.abs());
    }
    //determine sign, the algorithms don't consider signs
    if ((right > 0&&sign=='+')||(right < 0&&sign=='-')) {
        result.sign = '+';
    } else{
        result.sign = '-';
    }
    return result;
}

BigInt BigInt::operator*(const int &right) const{
	//calculates num times a less than 100 number using the native multiplication, increases efficiency
    if (right == 0) {
        return BigInt(0);
    }
    if (right > 100 || right < -100)
        return *this * BigInt(right);
    BigInt result;
    if (right == 100 || right == -100) {
        result = dec_left_shift(1);
        return result;
    }
    int rightabs = (right>0)?right:-right;
    unsigned short carry = 0;
    for (unsigned long i = 0; i < abs_value.size(); i++) {
        unsigned int temp = abs_value[i] * rightabs + carry;
        carry = temp / 100;
        result.abs_value.push_back(temp % 100);
    }
    if (carry)
        result.abs_value.push_back(carry);
    if ((right > 0&&sign=='+')||(right < 0&&sign=='-')) {
        result.sign = '+';
    } else{
        result.sign = '-';
    }
    return result;
}
BigInt BigInt::_div_long(const BigInt &right) const{
    //This algorithm implements modified Knuth division Algorithm D
    //It is similar to the school book long division. 
    if (*this < right) {
        return BigInt(0);
    }
    BigInt _operand(0);
    BigInt result;
    unsigned long dividendsize = abs_value.size();
    for (unsigned long i = 0; i < dividendsize; i++) {
        result.abs_value.push_back(0);
    }
    for (unsigned long i = 0; i < dividendsize; i++ ) {
        _operand = _operand.dec_left_shift(1);
        _operand = _operand + abs_value[dividendsize - i - 1];
        if (_operand < right) {
            continue;
        }
        unsigned short low = 1; unsigned short high = 99;
        while (low < high - 1) {
            unsigned short temp = (low + high) / 2;
            if (right * int(temp) > _operand) {
                high = temp;
            } else if(right * int(temp) < _operand) {
                low = temp;
            } else {
                result.abs_value[dividendsize - i - 1] = temp;
                _operand = 0;
                break;
            }
        }
        if (_operand!=0) {
            _operand = _operand - low * right;
            result.abs_value[dividendsize - i - 1] = low;
        }
    }
    result.removeLeadingZeros();
    return result;
}

BigInt BigInt::invert_fixedP(unsigned long &length) const{
    //calculates the reciprocal of the bigint, and express as
    //a fixed point int with length "length"
    //the algorithm uses Newton Method
    BigInt guess(BigInt(1).dec_left_shift(length-abs_value.size()));
    BigInt lastGuess(guess);
    const BigInt two(BigInt(2).dec_left_shift(length));
    BigInt delta(0);
    do{
        guess = ((two - *this * guess) * guess).dec_right_shift(length);
        delta = guess - lastGuess;
        lastGuess = guess;
    } while (delta != 0);
    return guess;
}


BigInt BigInt::_div_newton(const BigInt &right) const{
	//This algorithm takes the reciprocal of the divisor, and multiply with a fast multiplication algorithm
    if (*this < right) {
        return BigInt(0);
    }
    unsigned long vecsize = abs_value.size();
    BigInt result((*this * right.invert_fixedP(vecsize)).dec_right_shift(vecsize));
    //since the reciprocal is approximate, errors can occur when a exact division happens.
    //following code check whether the result is correct and correct it if it's not.
    //These code takes constant time, since the error of the result is at most 1 or -1
    BigInt _mod(*this - result * right);
    while (_mod < 0) {
        --result;
        _mod = _mod + right;
    }
    while (_mod >= right) {
        ++result;
        _mod = _mod - right;
    }
    return result;
}

BigInt BigInt::operator/(const BigInt &right) const{
	//multiplication calls different algorithms based on the benchmark test
    BigInt result;
    if (abs_value.size() < 31){
        result = this->abs()._div_long(right.abs());
    }else{
        result = this->abs()._div_newton(right.abs());
    }
    
    if ((right > 0&&sign=='+')||(right < 0&&sign=='-')) {
        result.sign = '+';
    } else{
        result.sign = '-';
    }
    return result;
}

BigInt BigInt::operator/(const int &right) const{
	//calculates num divides a less than 100 number using the native division, increases efficiency
    if (right == 0) {
        std::cout<<"error"<<std::endl;
        return BigInt(0);
    }
    if (right > 100 || right < -100)
        return *this / BigInt(right);
    BigInt result;
    if (right == 100 || right == -100) {
        result = *this;
        result.abs_value.erase(result.abs_value.begin());
        return result;
    }
    int rightabs = (right>0)?right:-right;
    unsigned short borrow = 0;
    unsigned long vecsize = abs_value.size();
    for (unsigned long i = 0; i < vecsize; i++) {
        result.abs_value.push_back(0);
    }
    for (unsigned long i = 0; i < vecsize; i++) {
        borrow = borrow * 100 + abs_value[vecsize - 1 - i];
        if (borrow < rightabs) {
            continue;
        }
        result.abs_value[vecsize - 1 - i] = borrow / rightabs;
        borrow = borrow % rightabs;
    }
    result.removeLeadingZeros();
    if ((right > 0&&sign=='+')||(right < 0&&sign=='-')) {
        result.sign = '+';
    } else{
        result.sign = '-';
    }
    return result;
}

BigInt BigInt::_mod_def(const BigInt &right) const{
	//this is the definition of mod
    return *this - (*this/right)*right;
}

BigInt BigInt::_mod_barett(const BigInt &right) const{
	//this is the barrett reduction algorithm, however it is running much slower than the definition one

    BigInt k(right.bad_log_2()+1);
    BigInt temp(BigInt(4).pow(k));
    BigInt r(temp/right);
    BigInt t(*this - (*this * r / temp)* right);
    if (t<right) {
        return t;
    }else{
        return (t-right)._mod_barett(right);
    }
}

BigInt BigInt::operator%(const BigInt &right) const{
    BigInt result(this->abs()._mod_def(right.abs()));
    if (sign=='-') {
        result.sign = '-';
    }else{
        result.sign = '+';
    }
    return result;
}

BigInt BigInt::operator%(const int &right) const{
    return *this % BigInt(right);
}

BigInt &BigInt::operator=(const BigInt &right){
    this->sign = right.sign;
    this->abs_value = right.abs_value;
    return *this;
}
BigInt &BigInt::operator=(const int &right){
    BigInt bigRight(right);
    this->sign = bigRight.sign;
    this->abs_value = bigRight.abs_value;
    return *this;
}
BigInt &BigInt::operator++(){
    *this = *this + BigInt(1);
    return *this;
}
BigInt BigInt::operator++(int){
    BigInt temp(*this);
    *this = *this + BigInt(1);
    return temp;
}
BigInt &BigInt::operator--(){
    *this = *this - BigInt(1);
    return *this;
}
BigInt BigInt::operator--(int){
    BigInt temp(*this);
    *this = *this - BigInt(1);
    return temp;
}

bool BigInt::isAbsLarger(const BigInt &right) const{
    //check size
    if (abs_value.size() < right.abs_value.size())
        return false;
    if (abs_value.size() > right.abs_value.size())
        return true;
    //check by vector elements
    unsigned long vecsize = abs_value.size();
    for (unsigned long i = 0; i < vecsize; i++) {
        if (abs_value[vecsize-i-1] < right.abs_value[vecsize-i-1])
            return false;
        if (abs_value[vecsize-i-1] > right.abs_value[vecsize-i-1])
            return true;
    }
    return false;
}

bool BigInt::isAbsSmaller(const BigInt &right) const{
    return right.isAbsLarger(*this);
}

bool BigInt::isAbsSame(const BigInt &right) const{
    //check size
    if (abs_value.size()!=right.abs_value.size())
        return false;
    //check if everything is the same
    for (unsigned long i = 0; i < abs_value.size(); i++) {
        if (abs_value[i]!=right.abs_value[i])
            return false;
    }
    return true;
}
bool BigInt::operator>(const BigInt &right) const{
    if (sign=='+' && right.sign=='-')
        return true;
    if (sign=='-' && right.sign=='+')
        return false;
    if (sign=='+' && right.sign=='+')
        return isAbsLarger(right);
    return !isAbsLarger(right);
}
bool BigInt::operator>(const int &right) const{
    return *this > BigInt(right);
}

bool BigInt::operator>=(const BigInt &right) const{
    return *this > right || *this == right;
}
bool BigInt::operator>=(const int &right) const{
    return *this > BigInt(right) || *this == BigInt(right);
}

bool BigInt::operator<(const BigInt &right) const{
    return right > *this;
}
bool BigInt::operator<(const int &right) const{
    return *this < BigInt(right);
}

bool BigInt::operator<=(const BigInt &right) const{
    return *this < right || *this == right;
}
bool BigInt::operator<=(const int &right) const{
    return *this < BigInt(right) || *this == BigInt(right);
}

bool BigInt::operator==(const BigInt &right) const{
    //check 0
    if (isAbsSame(0)&&right.isAbsSame(0))
        return true;
    //check sign
    if (sign!=right.sign)
        return false;
    return isAbsSame(right);
}
bool BigInt::operator==(const int &right) const{
    return *this==BigInt(right);
}

bool BigInt::operator!=(const BigInt &right) const{
    return !(*this==right);
}
bool BigInt::operator!=(const int &right) const{
    return !(*this==BigInt(right));
}

BigInt BigInt::pow(BigInt right) const{
	//traditional fast power algorithm
    BigInt base(*this);
    BigInt result(1);
    while (right != 0) {
        if (right.abs_value[0]&1) {
            result = result * base;
        }
        right = right / 2;
        base = base * base;
    }
    return result;
}

BigInt BigInt::pow(int right) const{
    BigInt base(*this);
    BigInt result(1);
    while (right != 0) {
        if (right&1) {
            result = result * base;
        }
        right = right >> 1;
        base = base * base;
    }
    return result;
}

BigInt &BigInt::operator<<(const BigInt &leftShift){
    *this = *this * BigInt(2).pow(leftShift);
    return *this;
}
BigInt &BigInt::operator<<(const int &leftShift){
    *this = *this * BigInt(2).pow(leftShift);
    return *this;
}

BigInt &BigInt::operator>>(const BigInt &rightShift){
    *this = *this / BigInt(2).pow(rightShift);
    return *this;
}

BigInt &BigInt::operator>>(const int &rightShift){
    *this = *this / BigInt(2).pow(rightShift);
    return *this;
}


BigInt operator+(const int &left, const BigInt &right){
    return BigInt(left)+right;
}
BigInt operator-(const int &left, const BigInt &right){
    return BigInt(left)-right;
}
BigInt operator*(const int &left, const BigInt &right){
    return BigInt(left)*right;
}
BigInt operator/(const int &left, const BigInt &right){
    return BigInt(left)/right;
}
BigInt operator%(const int &left, const BigInt &right){
    return BigInt(left)%right;
}
bool operator>(const int &left, const BigInt &right){
    return BigInt(left)>right;
}
bool operator>=(const int &left, const BigInt &right){
    return BigInt(left)>=right;
}
bool operator<(const int &left, const BigInt &right){
    return BigInt(left)<right;
}
bool operator<=(const int &left, const BigInt &right){
    return BigInt(left)<=right;
}
bool operator==(const int &left, const BigInt &right){
    return BigInt(left)==right;
}
bool operator!=(const int &left, const BigInt &right){
    return BigInt(left)!=right;
}
ostream &operator<<(ostream &out,const BigInt &num){
    //print the sign
    if (num.sign == '-')
        out<<"-";
    //print the number
    unsigned long vecsize = num.abs_value.size();
    out<<num.abs_value[vecsize-1];
    for (unsigned long i = 1; i < vecsize; i++){
        unsigned int val = num.abs_value[vecsize-i-1];
        if (val < 10)
            out<<"0";
        out<<num.abs_value[vecsize-i-1];
    }
    return out;
}
istream &operator>>(istream &in,const BigInt &num){
    char input[65535];
    in>>input;
    return in;
}
BigInt &operator<<(int &num, const BigInt &leftShift){
    return BigInt(num)<<leftShift;
}
BigInt &operator>>(int &num, const BigInt &rightShift){
    return BigInt(num)>>rightShift;
}

unsigned long long BigInt::integerLength() const{
    unsigned long long result = 2 * abs_value.size();
    if (abs_value.back()<10) {
        result--;
    }
    return result;
}

BigInt BigInt::bad_log_2() const{
	//gives a very approximate result of log2, uses log10/log(10,2)
    unsigned long long bad_log_10 = integerLength();
    BigInt result(bad_log_10 * 33 / 10);
    return result;
}

