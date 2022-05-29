//
//  matrix.h
//  PA3
//
//  Created by Felix Zhao on 8/10/2015.
//  Copyright © 2015 Felix Zhao. All rights reserved.
//

#ifndef matrix_h
#define matrix_h
struct cplxnum{
    double re=0;
    double im=0;
};
class CplxMatrix;

void displayComplex(cplxnum c);

class Matrix {                          // Matrix class
public:
    explicit Matrix(int rows = 0, int cols = 0);
    // constructor
    Matrix( const Matrix & mt);           // copy constructor
    ~Matrix();
    int rows() const;
    int cols() const;
    double & el(int i, int j) const;           // access (i, j)th element
    void assign(const Matrix & op);       // copy values from op
    void operator=(const Matrix & op);
    Matrix mul(const Matrix & op) const;  // multiplication of matrices
    Matrix transpose() const;             // the transpose of matrix
    Matrix inverse() const;             // the inverse of matrix
    // Add your public member functions, if any, in the following
    double det() const;
    double minor(int row, int col) const;
    Matrix minorMat(int row, int col) const;
    Matrix cofactorMatrix() const;
    Matrix scalarMul(double num) const;
    void printMatrix() const;
    Matrix plus(const Matrix & op) const;
    Matrix matpower(int power) const;
    Matrix times(const Matrix & op) const;
    double trace() const;
    double perm() const;
    Matrix CharacteristicPolynomialCoefficient() const;
    double diagonalMinor(int level) const;
    Matrix companionMatrix() const;
    Matrix rowReduce(bool showSteps = false) const;
    Matrix rowReduceShowSteps() const;
    int matrixRank() const;
    Matrix range() const;
    Matrix kernel() const;
    Matrix concatenate(const Matrix & op) const;
    Matrix SolveLinearSystem() const;
    Matrix polynomialNumericalRoots() const;
    CplxMatrix eigenvalues() const;
    CplxMatrix eigenvectors() const;
    CplxMatrix toCplx() const;
private:
    double **elm;
    int r;
    int c;
};
class CplxMatrix{
public:
    explicit CplxMatrix(int rows = 0, int cols = 0);
    // constructor
    CplxMatrix( const CplxMatrix & mt);           // copy constructor
    ~CplxMatrix();
    int rows() const;
    int cols() const;
    cplxnum & el(int i, int j) const;           // access (i, j)th element
    void assign(const CplxMatrix & op);       // copy values from op
    void operator=(const CplxMatrix & op);
    CplxMatrix mul(const CplxMatrix & op) const;  // multiplication of matrices
    CplxMatrix transpose() const;             // the transpose of matrix
    CplxMatrix ConjugateTranspose() const;
    CplxMatrix inverse() const;             // the inverse of matrix
    // Add your public member functions, if any, in the following
    cplxnum det() const;
    cplxnum minor(int row, int col) const;
    CplxMatrix minorMat(int row, int col) const;
    CplxMatrix cofactorMatrix() const;
    CplxMatrix scalarMul(cplxnum num) const;
    void printMatrix() const;
    CplxMatrix plus(const CplxMatrix & op) const;
    CplxMatrix matpower(int power) const;
    CplxMatrix times(const CplxMatrix & op) const;
    cplxnum trace() const;
    cplxnum perm() const;
    cplxnum subperm(int row, int col) const;
    CplxMatrix CharacteristicPolynomialCoefficient() const;
    cplxnum diagonalMinor(int level) const;
    CplxMatrix companionMatrix() const;
    CplxMatrix rowReduce(bool showSteps = false) const;
    CplxMatrix rowReduceShowSteps() const;
    int matrixRank() const;
    CplxMatrix range() const;
    CplxMatrix kernel() const;
    CplxMatrix concatenate(const CplxMatrix & op) const;
    void exchangeRow(int a, int b);
    void rowPivotlize(int row, int pivot);
    void eliminate(int base, int target, int pivot);
    void chop(double delta);
    CplxMatrix SolveLinearSystem() const;
    CplxMatrix polynomialNumericalRoots() const;
    CplxMatrix eigenvalues() const;
    CplxMatrix eigenvectors() const;
    Matrix toReal() const;
private:
    cplxnum **elm;
    int r;
    int c;
};

#endif
