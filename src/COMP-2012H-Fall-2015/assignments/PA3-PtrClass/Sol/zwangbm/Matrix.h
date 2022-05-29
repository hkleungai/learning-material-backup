/*
 * Matrix.h
 *
 *  Created on: 2015Äê10ÔÂ1ÈÕ
 *      Author: ThinkPad
 */

#ifndef MATRIX_H_
#define MATRIX_H_

class Matrix  {						//Matrix class
public:
	explicit Matrix (int rows = 0, int cols = 0);
									//constructor
	Matrix (const Matrix & mt);		//copy constructor
	~Matrix();						//destructor
	int rows() const;		//return the number of rows of the matrix
	int cols() const;		//return the number of columns of the matrix
	double & el(int i, int j);	//access (i,j)th element
	void assign(const Matrix & op);		//copy values from op
	Matrix mul(const Matrix & op) const;//multiplication of matrices
	Matrix transpose() const;			//the transpose of matrix
	Matrix inverse() const;				//the inverse of matrix
	//Add your public member functions, if any, in the following
	Matrix (int row, int col, const Matrix &);	//get the submatrix of the matrix without row th row and col th column
	void print () const;
	double calDet(int);
	Matrix add(const Matrix & op,double,double) const;//includes addition and substraction of matrices
														//e.g. A.add(B,2,3); ---> 2*A+3*B
	Matrix power(const Matrix & op,int) const;			//calculate the power of the matrix
	Matrix sol(const Matrix &) const; 	//calculate the solution of Ax = b;	Matrix x = A.sol(b);
	double calTrace() const;//	calculate the trace of a square matrix
	void ref (int); 		//	Ab.ref();
	int rank() const;		//	return the rank of the matrix    A.rank();
private:
	double **elm;						//matrix elements
	int r;								//number of rows
	int c;								//number of columns
	//Add your private data members and private member functions,
	//if any, in the following
};
#endif /* MATRIX_H_ */
