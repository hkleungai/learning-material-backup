//
//  matrix.cpp
//  PA3
//
//  Created by Felix Zhao on 8/10/2015.
//  Copyright © 2015 Felix Zhao. All rights reserved.
//
/* These code are from stackoverflow to fix the to_string is not a member of std problem.
 */
#include <string>
#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}


#include <iostream>
#include <string>
#include <iomanip>
#include "matrix.h"
//This number can be changed to adjust the precision setting. (EXPERIMENTAL)
#define PRECISION 0.000001

//This part overloads the operators for complex arithmetic
cplxnum operator+(cplxnum num1, cplxnum num2){
    cplxnum result;
    result.re = num1.re+num2.re;
    result.im = num1.im+num2.im;
    return result;
}
cplxnum operator+(double num1, cplxnum num2){
    cplxnum result;
    result.re = num1+num2.re;
    result.im = num2.im;
    return result;
}
cplxnum operator+(cplxnum num1, double num2){
    return num2+num1;
}
cplxnum operator-(cplxnum num1, cplxnum num2){
    cplxnum result;
    result.re = num1.re-num2.re;
    result.im = num1.im-num2.im;
    return result;
}
cplxnum operator-(double num1, cplxnum num2){
    cplxnum result;
    result.re = num1-num2.re;
    result.im = num2.im;
    return result;
}
cplxnum operator-(cplxnum num1, double num2){
    return num2-num1;
}
cplxnum operator*(cplxnum num1, cplxnum num2){
    cplxnum result;
    result.re = num1.re*num2.re-num1.im*num2.im;
    result.im = num1.re*num2.im+num1.im*num2.re;
    return result;
}
cplxnum operator*(double num1, cplxnum num2){
    cplxnum result;
    result.re = num1*num2.re;
    result.im = num1*num2.im;
    return result;
}
cplxnum operator*(cplxnum num1, double num2){
    return num2*num1;
}
cplxnum power(cplxnum num1, int num2){
    cplxnum result;
    if (num2==0) {
        result.re = 1; result.im = 0;
        return result;
    }
    result = num1;
    for (int i = 1; i < num2; i++) {
        result = result* num1;
    }
    return result;
}
cplxnum operator/(cplxnum num1, cplxnum num2){
    cplxnum result;
    result.re = (num1.re*num2.re+num1.im*num2.im)/(num2.re*num2.re+num2.im*num2.im);
    result.im = (num1.im*num2.re-num1.re*num2.im)/(num2.re*num2.re+num2.im*num2.im);
    return result;
}
cplxnum operator/(double num1, cplxnum num2){
    cplxnum result;
    result.re = (num1*num2.re)/(num2.re*num2.re+num2.im*num2.im);
    result.im = -(num1*num2.im)/(num2.re*num2.re+num2.im*num2.im);
    return result;
}
cplxnum operator/(cplxnum num1, double num2){
    cplxnum result;
    result.re = num1.re/num2;
    result.im = num1.im/num2;
    return result;
}
double abs(cplxnum num){
    return num.re*num.re+num.im*num.im;
}
cplxnum conj(cplxnum num){
    cplxnum result;
    result.re = num.re;
    result.im = -num.im;
    return result;
}

//This is a function to print complex numbers, should be in the complex number class
//It displays complex numbers according to the values of real and imaginary part.
void displayComplex(cplxnum c){
    std::string realstr = patch::to_string(c.re);
    realstr.erase (realstr.find_last_not_of('0') + 1, std::string::npos );
    std::string imstr = patch::to_string(c.im);
    imstr.erase (imstr.find_last_not_of('0') + 1, std::string::npos );
    if (c.im!=0&&c.re!=0) {
        std::cout<< realstr+((c.im<0)?"":"+")+imstr+"i"+" "<<std::endl;
    }else if(c.im==0&&c.re!=0){
        std::cout<< realstr + " "<<std::endl;
    }else if(c.im!=0&&c.re==0){
        std::cout<< imstr + "i "<<std::endl;
    }else{
        std::cout<< "0."<<std::endl;
    }
}

//Implement of Matrix class apart from basic functions, most are redirected to complex implementations
Matrix::Matrix(int rows, int cols):r(rows),c(cols)
{
    if (r < 0) r = 0;
    if (c < 0) c = 0;
    elm = new double*[rows];
    for (int i = 0; i < rows; i++) {
        elm[i] = new double[cols];
    }
}

Matrix::Matrix(const Matrix & mt):r(mt.r),c(mt.c)
{
    elm = new double*[r];
    for (int i = 0; i < r; i++) {
        elm[i] = new double[c];
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            el(i,j) = mt.el(i,j);
        }
    }
}

Matrix::~Matrix(){
    for (int i = 0; i < r; i++) {
        delete[] elm[i];
    }
    delete[] elm;
}

int Matrix::rows() const{
    return r;
}

int Matrix::cols() const{
    return c;
}

double & Matrix::el(int i, int j) const{
    return elm[i][j];
}

void Matrix::assign(const Matrix & op){
    if (!(r == op.r && c == op.c)) {
        for (int i = 0; i < r; i++) {
            delete[] elm[i];
        }
        delete[] elm;
        r = op.r;
        c = op.c;
        elm = new double*[r];
    }
        for (int i = 0; i < r; i++) {
            elm[i] = new double[c];
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                el(i,j) = op.el(i,j);
            }
        }
    
    
}
//Overloads = to make a deep copy of the matrix to prevent double deletion error
void Matrix::operator=(const Matrix & op){
    assign(op);
}

Matrix Matrix::mul(const Matrix & op) const{
    if (c != op.r) {
        std::cout<<"ncompatible shapes"<<std::endl;
    }
    Matrix result(r, op.c);
    for (int i = 0; i < result.r; i++) {
        for (int j = 0; j < result.c; j++) {
            double sum = 0.0;
            for (int k = 0; k < c; k++) {
                sum += el(i,k)*op.el(k,j);
            }
            result.el(i,j) = sum;
        }
    }
    return result;
}

Matrix Matrix::transpose() const{
    Matrix result(c, r);
    for (int i = 0; i < result.r; i++) {
        for (int j = 0; j < result.c; j++) {
            result.el(i,j) = el(j,i);
        }
    }
    return result;
}


Matrix Matrix::inverse() const{
    return toCplx().inverse().toReal();
}

double Matrix::det() const{
    return toCplx().det().re;
}

Matrix Matrix::minorMat(int row, int col) const{
    return toCplx().minorMat(row, col).toReal();
}

double Matrix::minor(int row, int col) const{
    return minorMat(row, col).det();
}

Matrix Matrix::cofactorMatrix() const{
    return toCplx().cofactorMatrix().toReal();
}

Matrix Matrix::scalarMul(double num) const{
    cplxnum num2; num2.re = num;
    return toCplx().scalarMul(num2).toReal();
}

void Matrix::printMatrix() const{
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            std::cout<<el(i,j)<<"\t";
        }
        std::cout<<std::endl;
    }
}

Matrix Matrix::plus(const Matrix & op) const{
    return toCplx().plus(op.toCplx()).toReal();
}

Matrix Matrix::matpower(int power) const{
    return toCplx().matpower(power).toReal();
}

Matrix Matrix::times(const Matrix & op) const{
    return toCplx().times(op.toCplx()).toReal();
}

double Matrix::trace() const{
    return toCplx().trace().re;
}

double Matrix::perm() const{
    return toCplx().perm().re;
}

Matrix Matrix::CharacteristicPolynomialCoefficient() const{
    return toCplx().CharacteristicPolynomialCoefficient().toReal();
}

double Matrix::diagonalMinor(int level) const{
    return toCplx().diagonalMinor(level).re;
}


Matrix Matrix::companionMatrix()const{
    return toCplx().companionMatrix().toReal();
}

Matrix Matrix::rowReduceShowSteps() const{
    return toCplx().rowReduce(true).toReal();
}

Matrix Matrix::rowReduce(bool showSteps) const{
    return toCplx().rowReduce(showSteps).toReal();
}

int Matrix::matrixRank() const{
    return toCplx().matrixRank();
}

Matrix Matrix::range() const{
    return toCplx().range().toReal();
}

Matrix Matrix::kernel() const{
    return toCplx().kernel().toReal();
}

Matrix Matrix::concatenate(const Matrix & op) const{
    return toCplx().concatenate(op.toCplx()).toReal();
}

Matrix Matrix::SolveLinearSystem() const{
    return toCplx().SolveLinearSystem().toReal();
}
Matrix Matrix::polynomialNumericalRoots() const{
    return toCplx().polynomialNumericalRoots().toReal();
}

CplxMatrix Matrix::eigenvalues() const{
    return toCplx().eigenvalues();
}

CplxMatrix Matrix::eigenvectors() const{
    return toCplx().eigenvectors();
}

//transfer the double matrix to complex
CplxMatrix Matrix::toCplx()const{
    CplxMatrix transfer(r,c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            transfer.el(i,j).re = el(i,j);
            transfer.el(i,j).im = 0;
        }
    }
    return transfer;
}

//--------------------------------------
//Implement of complex matrix

CplxMatrix::CplxMatrix(int rows, int cols):r(rows),c(cols)
{
    if (r < 0) r = 0;
    if (c < 0) c = 0;
    elm = new cplxnum*[rows];
    for (int i = 0; i < rows; i++) {
        elm[i] = new cplxnum[cols];
    }
}

CplxMatrix::CplxMatrix(const CplxMatrix & mt):r(mt.r),c(mt.c)
{
    elm = new cplxnum*[r];
    for (int i = 0; i < r; i++) {
        elm[i] = new cplxnum[c];
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            el(i,j).re = mt.el(i,j).re;
            el(i,j).im = mt.el(i,j).im;
        }
    }
}

CplxMatrix::~CplxMatrix(){
    for (int i = 0; i < r; i++) {
        delete[] elm[i];
    }
    delete[] elm;
}

int CplxMatrix::rows() const{
    return r;
}

int CplxMatrix::cols() const{
    return c;
}

cplxnum & CplxMatrix::el(int i, int j) const{
    return elm[i][j];
}

void CplxMatrix::assign(const CplxMatrix & op){
    if (!(r == op.r && c == op.c)) {
        for (int i = 0; i < r; i++) {
            delete[] elm[i];
        }
        delete[] elm;
        r = op.r;
        c = op.c;
        elm = new cplxnum*[r];
        for (int i = 0; i < r; i++) {
            elm[i] = new cplxnum[c];
        }
    }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                el(i,j).re = op.el(i,j).re;
                el(i,j).im = op.el(i,j).im;
            }
        }
    
    
}

//Overloads = to make a deep copy of the matrix to prevent double deletion error
void CplxMatrix::operator=(const CplxMatrix & op){
    assign(op);
}

CplxMatrix CplxMatrix::mul(const CplxMatrix & op) const{
    if (c != op.r) {
        std::cout<<"incompatible shapes"<<std::endl;
    }
    CplxMatrix result(r, op.c);
    for (int i = 0; i < result.r; i++) {
        for (int j = 0; j < result.c; j++) {
            cplxnum sum;
            for (int k = 0; k < c; k++) {
                sum = sum + el(i,k)*op.el(k,j);
            }
            result.el(i,j) = sum;
        }
    }
    return result;
}

CplxMatrix CplxMatrix::transpose() const{
    CplxMatrix result(c, r);
    for (int i = 0; i < result.r; i++) {
        for (int j = 0; j < result.c; j++) {
            result.el(i,j).re = el(j,i).re;
            result.el(i,j).im = el(j,i).im;
        }
    }
    return result;
}

CplxMatrix CplxMatrix::ConjugateTranspose() const{
    CplxMatrix result(c, r);
    for (int i = 0; i < result.r; i++) {
        for (int j = 0; j < result.c; j++) {
            result.el(i,j).re = el(j,i).re;
            result.el(i,j).im = -el(j,i).im;
        }
    }
    return result;
}

//Inverse is implemented using adjoint method
CplxMatrix CplxMatrix::inverse() const{
    if (r != c) {
        std::cout<<"incompatible shapes"<<std::endl;
        CplxMatrix result;
        return result;
    }
    if (det().re == 0&&det().im==0) {
        std::cout<<"singular matrix encountered"<<std::endl;
        CplxMatrix result;
        return result;
    }
    return cofactorMatrix().transpose().scalarMul(1.0/det());
}

//Determinant is implemented using recursive calls
cplxnum CplxMatrix::det() const{
    if (r != c) {
        std::cout<<"incompatible shapes"<<std::endl;
        return cplxnum();
    }
    if (r == 0) return cplxnum();
    if (r == 1) return el(0,0);
    cplxnum result;
    for (int dem = 0; dem < r; dem++) {
        result = result + ((dem%2==0)?(1):(-1))*el(0,dem)*(minor(0, dem));
    }
    return result;
}

//This function removes the row and col in a matrix, thich is called first i,j minor according to wikipedia
CplxMatrix CplxMatrix::minorMat(int row, int col) const{
    if (row > r || row < 0 || col > c || col < 0) {
        std::cout<<"invalid element specification"<<std::endl;
        CplxMatrix result;
        return result;
    }
    CplxMatrix minor(r-1, c-1);
    for (int i = 0, ori_i = 0; i < r-1; i++, ori_i++) {
        for (int j = 0, ori_j = 0; j < c-1; j++, ori_j++) {
            if (ori_i == row) ori_i++;
            if (ori_j == col) ori_j++;
            minor.el(i,j) = el(ori_i,ori_j);
        }
    }
    return minor;
}

cplxnum CplxMatrix::minor(int row, int col) const{
    return minorMat(row, col).det();
}

//recursive call for permenant, ignoring the signs for det
cplxnum CplxMatrix::subperm(int row, int col) const{
    return minorMat(row, col).perm();
}

CplxMatrix CplxMatrix::cofactorMatrix() const{
    CplxMatrix result(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            result.el(i,j) = ((i+j)%2==0?1:-1)*minor(i, j);
        }
    }
    return result;
}

//A number multiplicates a matrix
CplxMatrix CplxMatrix::scalarMul(cplxnum num) const{
    CplxMatrix result(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            result.el(i,j) = el(i, j) * num;
        }
    }
    return result;
}

//To print the complex matrix in a formatted way:
//It first converts the complex number in to strings (the display of complex number is the same as the one above)
//and store them in a 2D string array. Then find the longest number in every column, padding the rest to the same
//length by spaces. This can make the matrix look better.
void CplxMatrix::printMatrix() const{
    std::string **output;
    output = new std::string*[r];
    for (int i = 0; i < r; i++) {
        output[i] = new std::string[c];
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            std::string realstr = patch::to_string(el(i,j).re);
            realstr.erase (realstr.find_last_not_of('0') + 1, std::string::npos );
            std::string imstr = patch::to_string(el(i, j).im);
            imstr.erase (imstr.find_last_not_of('0') + 1, std::string::npos );
            if (el(i, j).im!=0&&el(i, j).re!=0) {
                output[i][j] = realstr+((el(i, j).im<0)?"":"+")+imstr+"i"+" ";
            }else if(el(i, j).im==0&&el(i, j).re!=0){
                output[i][j] = realstr + " ";
            }else if(el(i, j).im!=0&&el(i, j).re==0){
                output[i][j] = imstr + "i ";
            }else{
                output[i][j] = "0.";
            }
        }
    }
    int maxlength = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (output[i][j].length() > maxlength) {
                maxlength = (int)output[i][j].length();
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            std::cout<< std::left << std::setw(maxlength) << std::setfill(' ')
            << output[i][j];
        }
        std::cout<<std::endl;
    }
    for (int i = 0; i < r; i++) {
        delete[] output[i];
    }
    delete[] output;
    output = 0;
}

//Element-wise plus
CplxMatrix CplxMatrix::plus(const CplxMatrix & op) const{
    if (!(r == op.r && c == op.c)) {
        std::cout<<"incompatible shapes"<<std::endl;
        CplxMatrix result;
        return result;
    }
    CplxMatrix result(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            result.el(i,j) = el(i, j) + op.el(i, j);
        }
    }
    return result;
}

//MatrixPower
CplxMatrix CplxMatrix::matpower(int power) const{
    if (r!=c) {
        std::cout<<"incompatible shapes"<<std::endl;
        CplxMatrix result;
        return result;
    }
    if (power < 0) {
        std::cout<<"invalid power specification"<<std::endl;
        CplxMatrix result;
        return result;
    }
    CplxMatrix result(r,c);
    if (power == 0) {
        for (int i = 0; i < r;i++ ) {
            for (int j = 0; j < c; j++) {
                result.el(i, j).re = (i == j)?1:0;
                result.el(i, j).im = 0;
            }
        }
        return result;
    }
    result = *this;
    for (int times = 1; times < power; times++) {
        result = result.mul(*this);
    }
    return result;
}


//Element-wise times
CplxMatrix CplxMatrix::times(const CplxMatrix & op) const{
    if (!(r == op.r && c == op.c)) {
        std::cout<<"incompatible shapes"<<std::endl;
        CplxMatrix result;
        return result;
    }
    CplxMatrix result(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            result.el(i,j) = el(i, j) * op.el(i, j);
        }
    }
    return result;
}

//Trace of a matrix
cplxnum CplxMatrix::trace() const{
    cplxnum result;
    int iter = (r>c)?c:r;
    for (int i = 0; i < iter; i++) {
        result = result+ el(i, i);
    }
    return result;
}

//Permenant of a matrix
cplxnum CplxMatrix::perm() const{
    if (r != c) {
        std::cout<<"incompatible shapes"<<std::endl;
        return cplxnum();
    }
    if (r == 0) return cplxnum();
    if (r == 1) return el(0,0);
    cplxnum result;
    for (int dem = 0; dem < r; dem++) {
        result = result + el(0,dem)*(subperm(0, dem));
    }
    return result;
}

//Returns the coefficients of the characteristic polynomial of a square matrix using a direct coefficient formula
//which avoid calculating the det symbolically
CplxMatrix CplxMatrix::CharacteristicPolynomialCoefficient() const{
    if (r != c) {
        std::cout<<"incompatible shapes"<<std::endl;
        CplxMatrix result;
        return result;
    }
    CplxMatrix result(1, r+1);
    result.el(0, 0).re = 1;
    result.el(0, 0).im = 0;
    for (int i =  1; i < r; i++) {
        result.el(0, i) = ((i%2==0)?1:-1)*diagonalMinor(r-i);
    }
    result.el(0, r) = ((r%2==0)?1:-1)*det();
    return result;
}

//A bad revursive implementation of diagnol minor, a better way could be using permutations/combinations to select the 
//rows/columns
cplxnum CplxMatrix::diagonalMinor(int level) const{
    cplxnum result;
    if (r != c) {
        std::cout<<"incompatible shapes"<<std::endl;
        return cplxnum();
    }
    if (level <= 0) {
        std::cout<<"invalid level specification"<<std::endl;
        return result;
    }
    if (level == 1) {
        for (int i = 0; i < r; i++) {
            result = result + minor(i, i);
        }
        return result;
    }
    for (int i = 0; i < r; i++) {
        result = result + (1/double(level))*minorMat(i, i).diagonalMinor(level - 1);
    }
    return result;
}

//returns a companion matrix of a matrix. Not a helper function of any others, nor did it appear in my demo
CplxMatrix CplxMatrix::companionMatrix()const{
    if (r!=1||c<3) {
        std::cout<<"incorrect size"<<std::endl;
        CplxMatrix r;
        return r;
    }
    CplxMatrix result(c-1,c-1);
    for (int i = 0; i < c-1; i++) {
        result.el(i, c-2) = 0-el(0, c-1-i);
    }
    for (int i = 1; i < c - 1; i++) {
        result.el(i, i-1).re = 1;
    }
    return result;
}

//hepler function to show steps for row reduce
CplxMatrix CplxMatrix::rowReduceShowSteps() const{
    return rowReduce(true);
}

//row reduce is implemented using the Gaussian elimination procedure:
//look at each row and find a non-zero as pivot, and eliminate others
//the show step function can demonstrate the algorithm better.
CplxMatrix CplxMatrix::rowReduce(bool showSteps) const{
    if (showSteps) {
        std::cout<<"Solution: "<<std::endl;
    }
    CplxMatrix result;
    result.assign(*this);
    result.chop(PRECISION);
    int currentlevel=0;//this variable is to record the current pivot level
    for (int i = 0; i < c; i++) {
        int j = currentlevel;
        while (j<r&&abs(result.el(j, i))==0) {//look down a column to see if it is all zeros
            j++;
        }
        if (j>=r){
            if (showSteps)
                std::cout<<"There is no pivot on the "<<i+1<<"th column."<<std::endl;
            continue;
        }
        if (showSteps) {
            std::cout<<"We found a non-zero number on row "<<j+1<<". Move this row to row "<<currentlevel+1<<" and divide all elements in this row by ";
            displayComplex(result.el(j, i));
            std::cout<<"We have"<<std::endl;
            result.printMatrix();
        }
        result.rowPivotlize(j, i);//make this pivot coeffieicnt 1
        result.chop(PRECISION);
        result.exchangeRow(j, currentlevel);//exchange this row to the current pivot place
        for (int k = 0; k < currentlevel; k++) {//this loop is to eliminate lines above the pivot
            if (abs(result.el(k, i))!=0) {
                result.eliminate(currentlevel, k, i);
                if (showSteps){
                    std::cout<<"Use row "<<currentlevel+1<<" to eliminate row "<<k+1<<", we have"<<std::endl;
                    result.printMatrix();
                }
                
            }
        }
        for (int k = currentlevel + 1; k < r; k++) {//this loop is to eliminate lines below the pivot
            if (abs(result.el(k, i))!=0) {
                result.eliminate(currentlevel, k, i);
                if (showSteps){
                    std::cout<<"Use row "<<currentlevel+1<<" to eliminate row "<<k+1<<", we have"<<std::endl;
                    result.printMatrix();
                }
                
            }
        }
        currentlevel++;
        if (currentlevel>=r) {
            break;//exit if all rows are pivot
        }
        result.chop(PRECISION);
    }
    result.chop(PRECISION);
    if (showSteps) {
        std::cout<<"So the result is"<<std::endl;
    }
    return result;
}

//this function exchange row a b in a matrix, this function CHANGES the matrix
void CplxMatrix::exchangeRow(int a, int b){
    if (a<0||a>=r||b<0||b>=c) {
        std::cout<<"invalid row specification"<<std::endl;
        return;
    }
    CplxMatrix temp(1, c);
    for (int i = 0; i < c ; i++) {
        temp.el(0, i) = el(a, i);
    }
    for (int i = 0; i < c ; i++) {
        el(a, i) = el(b, i);
    }
    for (int i = 0; i < c ; i++) {
        el(b, i) = temp.el(0, i);
    }
}

//this function does a row multiplication, making the disired pivot 1, this function CHANGES the matrix
void CplxMatrix::rowPivotlize(int row, int pivot){
    cplxnum ratio = el(row, pivot);
    for (int i = 0; i < c; i++) {
        el(row, i)  =  el(row, i)/ratio;
    }
}

//this function uses one row to eliminate another based on elimination requirement
void CplxMatrix::eliminate(int base, int target, int pivot){
    if (base<0||base>=r||target<0||target>=c||target<0||target>=c) {
        return;
    }
    if (abs(el(base, pivot))==0) {
        std::cout<<"wrong call"<<std::endl;
        return;
    }
    cplxnum ratio = el(target, pivot)/el(base, pivot);
    for (int i = 0; i < c; i++) {
        el(target, i) = el(target, i) - ratio * el(base, i);
    }
    
}

//This function replaces the number less than precision to 0. 
//It must exist, because double calculation is not exact. The "eliminated" row
//may have a number close to 0, which should be 0. In this case if no chop is 
//executed, it will be made pivot and become 1, and row reduce will give wrong result.
void CplxMatrix::chop(double delta){
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (el(i,j).re>0-delta&&el(i, j).re<delta) {
                el(i, j).re = 0;
            }
            if (el(i,j).im>0-delta&&el(i, j).im<delta) {
                el(i, j).im = 0;
            }
        }
    }
}

//calculates matrix rank
int CplxMatrix::matrixRank() const{
    return range().c;
}

//returns two column vectors linearly independent and spans the range space
CplxMatrix CplxMatrix::range() const{
    CplxMatrix toSolve = rowReduce();
    int *freePos = new int[c+1];
    int pivotCount = 0;
    for (int i = 0; i < c+1; i++) {
        freePos[i] = 0;
    }
    int tempindi = 0; int tempindj = 0;
    for (int i = 0; tempindi < r&&tempindj < c; i++) {//find the columns that have pivot
        if(toSolve.el(tempindi, tempindj).re==1&&toSolve.el(tempindi, tempindj).im==0){
            tempindi++;tempindj++;
            pivotCount++;
        }else{
            freePos[tempindj] = 1;
            tempindj++;
        }
    }
    CplxMatrix result(r, pivotCount);
    int writeInd = 0;
    for (int i = 0; i < c; i++) {//copy the original corresponding column to the result matrix
        if (freePos[i]==0) {
            for (int j = 0; j < r; j++) {
                result.el(j, writeInd) = el(j, i);
            }
            writeInd++;
        }
    }
    delete[] freePos;
    freePos = 0;
    return result;
}

//returns the column vectors independent and spans the null space
CplxMatrix CplxMatrix::kernel() const{
    CplxMatrix colofZero(r, 1);
    CplxMatrix toSolve;
    toSolve = concatenate(colofZero);
    CplxMatrix solution = toSolve.SolveLinearSystem();
    int *notZero = new int[solution.r];
    int notZeroCount = 0;
    for (int i = 0; i < solution.r; i++) {
        notZero[i]=0;
    }
    for (int i = 0; i < solution.r; i++) {//find the non-all-zero columns in solution
        for (int j = 0; j < solution.r; j++) {
            if (solution.el(j, i).re!=0||solution.el(j, i).im!=0) {
                notZero[i]=1;
                notZeroCount++;
                break;
            }
        }
    }
    int writeInd = 0;
    CplxMatrix result(solution.r, notZeroCount);
    for (int i = 0; i < solution.r; i++) {
        if (notZero[i]!=0) {
            for (int j = 0; j < solution.r; j++) {
                result.el(j, writeInd) = solution.el(j, i);
            }
            writeInd++;
        }
    }
    delete[] notZero;
    notZero = 0;
    return result;
}

//join two matrix left and right, for equation solving
CplxMatrix CplxMatrix::concatenate(const CplxMatrix & op) const{
    if (r!=op.r) {
        std::cout<<"incompatible shapes"<<std::endl;
        return CplxMatrix();
    }
    CplxMatrix result(r, c+ op.c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            result.el(i, j) = el(i, j);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = c; j < result.c; j++) {
            result.el(i, j) = op.el(i, j-c);
        }
    }
    return result;
}

//gives solution column vectors of a linear system
CplxMatrix CplxMatrix::SolveLinearSystem() const{
    CplxMatrix toSolve;
    toSolve = this->rowReduce();
    const int variables = toSolve.c - 1;
    int freeLine = 0;//record the rows are all zero (except the last row)
    for (int i = r-1; i > 0; i--) {
        cplxnum ZeroQ;
        for (int j = 0; j < c-1; j++) {
            ZeroQ = ZeroQ + toSolve.el(i, j)*toSolve.el(i, j);
        }
        if (abs(ZeroQ)==0) {
            freeLine++;
        }else{
            break;
        }
    }
    //const int pivot = r - freeLine;
    //const int freeVar = c-1-pivot;
    int freeVal = 0;
    for (int i = r-1; i > 0; i--) {
        if (abs(toSolve.el(i, c-1))==0) {
            freeVal++;
        }else{
            break;
        }
    }
    if (freeVal < freeLine) {//"a linear system has solution iff the last column is not pivot"
        std::cout<<"no solution"<<std::endl;
        CplxMatrix result;
        return result;
    }
    int *freePos = new int[c];
    for (int i = 0; i < c; i++) {
        freePos[i] = 0;
    }
    int tempindi = 0; int tempindj = 0;
    for (int i = 0; tempindi < r&&tempindj < c; i++) {//check the pivot places
        if(toSolve.el(tempindi, tempindj).re==1&&toSolve.el(tempindi, tempindj).im==0){
            tempindi++;tempindj++;
        }else{
            freePos[tempindj] = 1;
            tempindj++;
        }
    }
    CplxMatrix result(variables,variables+1);
    for (int j = 0; j < variables; j++) {
        if (freePos[j]==0) {//if pivot, all coefficient zero, not a free variable
            for (int i = 0; i < variables; i++) {
                result.el(i, j).re = 0;
                result.el(i, j).im = 0;
            }
        } else{
            for (int i = 0; i < r; i++) {//if not, copy the relation to other variables to the right
                result.el(i, j).re =  - toSolve.el(i, j).re;
                result.el(i, j).im =  - toSolve.el(i, j).im;
                
            }
            result.el(j, j).re = 1;//coefficient 1 for a free variable itself
        }
    }
    for (int i = 0; i < r; i++) {//no modifying the last column
        result.el(i, variables).re = toSolve.el(i, c-1).re;
        result.el(i, variables).im = toSolve.el(i, c-1).im;
    }
    delete[] freePos;
    freePos = 0;
    result.chop(PRECISION);
    return result;
}

//it takes a list(row=1 matrix) of polynomial coefficient, and gives all n complex roots 
CplxMatrix CplxMatrix::polynomialNumericalRoots() const{
    if (c==1) {//no variable case
        std::cout<<"no variable to solve"<<std::endl;
        CplxMatrix result;
        return result;
    }
    if (c==2) {//linear equation
        CplxMatrix result(1,1);
        result.el(0, 0) = 0-el(0, 1)/el(0, 0);
        return result;
    }
    //implement of Durand–Kerner method
    int degree = c-1;
    cplxnum *sol = new cplxnum[degree];//array for solutions
    //this is the initial guess of the roots, has to be complex and not the same
    sol[0].re = 0.1;
    sol[0].im = 0.2;
    for (int i = 1; i < degree; i++) {
        sol[i] = sol[i-1]* sol[i-1];
    }

    cplxnum *last = new cplxnum[degree];//array to store the last result in the previous iteration
    //will compare and see the error
    for (int iter = 0; iter < 10000; iter++) {//max iteration is 10000
        double delta = 0;
        for (int i = 0; i < degree; i++) {//store the previous values
            last[i] = sol[i];
        }
        for (int i = 0; i < degree; i++) {//the formula
            cplxnum denom;
            denom.re = 1; denom.im = 0;
            for (int j = 0; j < degree; j++) {
                if (i==j) {
                    continue;
                }
                denom = denom * (sol[i] - sol[j]);
            }
            cplxnum numer;
            numer.re = 0; numer.im = 0;
            for (int k = 0; k < c; k++) {
                numer = numer + el(0, k) * power(sol[i], degree-k);
            }
            sol[i] = sol[i] - (numer / denom);
            delta += abs(sol[i] - last[i]);
        }
        if (delta <= PRECISION)
            break;
        if (iter == 9999) {
            std::cout<<"did not converge when reached max recursion, solution may be wrong"<<std::endl;
        }
    }
    
    CplxMatrix result(degree, 1);
    for (int i = 0; i < degree; i++) {
        result.el(i, 0) = sol[i];
    }
    result.chop(PRECISION);
    delete[] sol;
    delete[] last;
    sol = 0;
    last = 0;
    return result;
}

//you can see the method in my function call.
CplxMatrix CplxMatrix::eigenvalues() const{
    CplxMatrix result;
    result = this->CharacteristicPolynomialCoefficient().polynomialNumericalRoots();
    return result;
}

//once eigenvalues are obtained, the remaining is to solve a linear system
CplxMatrix CplxMatrix::eigenvectors() const{
    CplxMatrix eigenVal;
    eigenVal.chop(PRECISION);
    eigenVal = eigenvalues();
    int degree = eigenVal.r;
    CplxMatrix result(c, degree);
    for (int i = 0; i < result.c; i++) {
        CplxMatrix temp(r,c+1);
        for (int k = 0; k < r; k++) {
            for (int j = 0; j < c; j++) {
                temp.el(k,j) = el(k,j);
            }
        }
        for (int k = 0; k < r; k++) {
            temp.el(k, k) = temp.el(k, k) - eigenVal.el(i, 0);
        }
        temp = temp.SolveLinearSystem();
        for (int j = 0; j < result.r; j++) {
            result.el(j,i) = temp.el(j, temp.c-2);
        }
    }
    return result;
}

//convert between two matrix types. Note I take the real part, instead of taking the abs part.
Matrix CplxMatrix::toReal() const{
    Matrix transfer(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            transfer.el(i,j) = el(i,j).re;
        }
    }
    return transfer;
}
