/*
 * Matrix.cpp
 *
 *  Created on: 2015Äê10ÔÂ1ÈÕ
 *      Author: ThinkPad
 */
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Matrix.h"
using namespace std;
//1.constructor
Matrix::Matrix(int rows, int cols){
	r = rows, c = cols;
	elm = new double  *[r];
	for (int i =0; i<r; i++){
		elm[i] = new double [c];
	}
	for (int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			elm[i][j]=0;
		}
	}
}

//2.copy constructor
Matrix::Matrix (const Matrix & mt){
	r = mt.r, c = mt.c;
	//create a new array with corresponding size
	elm = new double *[r];
	for (int i=0; i< r; i++){
		elm[i] = new double [c];
	}
	//copy the items one by one
	for (int i=0; i<r; i++){
		//array[i] = mt.array[i];
		for (int j=0; j<c; j++){
			elm[i][j] = mt.elm[i][j];
		}
	}
}
//print the matrix out
void Matrix::print() const{
	cout<<endl;
	for (int i=0; i< r; i++){
		for (int j=0; j<c; j++){
			cout<<elm[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
}

//3.destructor
Matrix::~Matrix(){
	for (int i=0; i<r; i++){
		delete[] elm[i];
	}
	delete [] elm;
	elm = NULL;
}

//4.inspector function for row
int Matrix::rows() const{
	return r;
}
//5.inspector function for column
int Matrix::cols() const{
	return c;
}

//6.element access
double &Matrix::el(int i, int j){ //why position of & ?
	if(i<=r && j<=c){
		return elm[i][j];
	}
	else{
		cout<<"There's no such element in the array."<<endl;
		exit(0);
	}
}

//7.assignment function
void Matrix::assign(const Matrix & op){
	//delete the previous one
	for (int i=0; i<r; i++){
		delete[] elm[i];
	}
	delete [] elm;
	elm = NULL;
	//construct a new one with the same size
	r = op.r;
	c = op.c;
	elm = new double *[r];
	for (int i=0; i< op.r; i++){
		elm[i] = new double [c];
	}
	//copy the items one by one
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			elm[i][j] = op.elm[i][j];
		}
	}
}
//8.matrix multiplication
Matrix Matrix::mul(const Matrix & op) const{ //the position of &?
	//check if the multiplication is valid
	if(c==op.r){
		//create a new constructor
		Matrix mul_matrix(r,op.c);
		//do the multiplication
		for (int i = 0; i<mul_matrix.r;i++){
			for (int j=0; j<mul_matrix.c; j++){
				for (int k=0; k<c;k++){
					mul_matrix.elm[i][j]+=elm[i][k]*op.elm[k][j];
				}
			}
		}
		return (mul_matrix);
	}
	else{
		cout<<"Invalid multiplication."<<endl;
		Matrix mul_matrix(0,0);
		return (mul_matrix);

	}
}
//9.transpose operation
Matrix Matrix::transpose() const{ 	//just modify the input matrix?
	//create a new constructor
	Matrix tran_matrix(c,r);
	//do the transposition
	for (int i = 0; i<r;i++){
		for (int j=0; j<c; j++){
			tran_matrix.elm[j][i]=elm[i][j];
		}
	}
	return (tran_matrix);
}
//10.inverse

//define the submatrix of matrix without row_el th row and col_el th column
Matrix::Matrix(int row_el, int col_el, const Matrix &ui){
	//check whether n*n ?
	r=(ui.r)-1;
	c=r;
	elm = new double *[r];
	for(int q=0; q<r; q++){
		elm[q] = new double [c];
	}
	int m=0,n=0;
	for (int i=0; i<ui.r;i++){
		if(i!=row_el){
			for (int j=0; j<ui.c; j++){
				if(j!=col_el){
					elm[m][n] = ui.elm[i][j];
					n++;
				}
			}
			n=0;	//next row , col starts from 0
			m++;
		}
	}
}

//calculate the determinant of n*n matrix

double Matrix::calDet(int side){
	if(r != c){
		cout<<"This is not a square matrix."<<endl;
		exit(0);
	}
	//check the size of the sub-matrix
	double det = 0;		//make it local
	if(side==1){
		return elm[0][0];
	}
	else{
		for (int i=0; i<side; i++){
			//create new matrix
			Matrix sub (0,i,*this);
			det +=pow(-1,i)*elm[0][i]*sub.calDet(side-1);
		}
	}
	return det;
}

// get the inverse matrix of the input one
Matrix Matrix::inverse() const{
	//copy this to matrix copy_matrix
	Matrix copy_matrix(*this);
	//there is no inverse if determinant is 0 or it is not a square matrix
	if(copy_matrix.calDet(r) == 0 || copy_matrix.r != copy_matrix.c){
		cout<<"There is no inverse of the input matrix."<<endl;
		Matrix zero_matrix(0,0);
		return zero_matrix;
	}
	//initialize the matrix temp_matrix (i.e. (1/detA)*(cofactor matrix of A))
	Matrix temp_matrix(r,c);
	//get the determinant of the matrix
	double determinant = copy_matrix.calDet(r);
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			//ij_sub is the submatrix of copy_matrix without ith row and jth column
			Matrix ij_sub (i,j,copy_matrix);
			temp_matrix.elm[i][j]=pow(-1,i+j)*ij_sub.calDet(r-1)/determinant; //calculate
		}
	}
	Matrix inverse_matrix = temp_matrix.transpose(); //do the transposition
	return inverse_matrix;				//inverse_matrix is the inverse matrix
}
//operation: qA+pB (q and p are constants ; A and B are matrices)
Matrix Matrix::add(const Matrix & op, double q, double p) const{ //the position of &?
	//check if the numbers of columns and rows are the same correspondingly
	if(c==op.c && r == op.r){
		//create a new constructor
		Matrix add_matrix(r,c);
		//do the addition
		for (int i=0; i<r; i++){
			for (int j=0; j<c; j++){
				add_matrix.elm[i][j] = q*elm[i][j] + p*op.elm[i][j];
			}
		}

		return (add_matrix);
	}
	else{
		cout<<"Invalid addition."<<endl;
		Matrix add_matrix(0,0);
		return (add_matrix);

	}
}
//operation: A^k
Matrix Matrix::power(const Matrix & op, int k) const{
	if (c == r){
		Matrix I_matrix(c,r);
		// create matrix I_matrix as I
		for (int i=0; i<r; i++){
			for (int j=0; j<c; j++){
				if(i==j){I_matrix.elm[i][j] = 1;}
				else{I_matrix.elm[i][j] = 0;}
			}
		}
		if(k>0){
			return (I_matrix.power(op, k-1)).mul(op);
		}
		if(k==0){return I_matrix;}
		if(k<0){
			Matrix inverse_op = op.inverse();
			k=-k;
			return (I_matrix.power(inverse_op,k-1)).mul(inverse_op);
		}
	}
	else{
		cout<<"The size of the matrix is not correct."<<endl;
		Matrix zero_matrix(0,0);
		return zero_matrix;
	}
}
//operation: solve Ax=b
// lhs is A and rhs is b
Matrix Matrix::sol(const Matrix & rhs) const{
	//check the rows and columns of A and b
	Matrix lhs(*this);
	if(lhs.r == rhs.r && rhs.c == 1 && lhs.r==lhs.c){
		if(lhs.calDet(lhs.r) == 0){
			cout<<"There isn't any unique solution to this equation."<<endl;
			Matrix sol_matrix(0);
			return sol_matrix;
		}
		else{
			Matrix sol_matrix = (lhs.inverse()).mul(rhs);
			return (sol_matrix);
		}
	}
	else{
		cout<<"The form of A or b is not correct (Reminder: Please enter a square matrix for A)."<<endl;
		Matrix sol_matrix(0,0);
		return sol_matrix;

	}
}
//========Row-echelon Form
void Matrix::ref(int current_num_of_row = 0){
	if(current_num_of_row < r){
		for (int i = 0; i < current_num_of_row; i++){
			//find the pivot
			int pivot_col_1 = 0;
			for (int j=0; j<c; j++){
				if (elm[i][j]){
					pivot_col_1 = j;
					break;
				}
			}
			//for each row, change the elements in each column accordingly
			for (int j = c-1; j>=0; j--){		//in order to change elm[current_num_of_row][i] at last
				if(elm[i][pivot_col_1]){
					elm[current_num_of_row][j] -= (elm[i][j]/elm[i][pivot_col_1])* elm[current_num_of_row][pivot_col_1];
				}
			}
		}
		//always keep the property of the REF matrix
		//check where the pivot of the (current_num_of_row) th row
		int pivot_col_2 = c;
		for (int j=0; j<c; j++){
			if (elm[current_num_of_row][j]){
				pivot_col_2 = j;
				break;
			}
		}
		int change_row = current_num_of_row;
		for (int i=current_num_of_row-1; i>=0; i--){
			int num_of_zero = 0;
			//check where the pivot is of the i th row
			for (int j=0; j<c; j++){
				if (elm[i][j] &&  pivot_col_2 <= i){
					change_row = i-1;
					break;
				}
				//the whole row is zeros
				if(!elm[i][j]){num_of_zero ++;}
				if(num_of_zero == c){
					change_row = i-1;
					break;
				}
			}
			if (change_row != current_num_of_row){break;}
		}
		//function as insert the row into a proper location
		for (int k=current_num_of_row; k>=change_row+2; k--){
			swap(elm[k],elm[k-1]);
		}
		Matrix::ref(current_num_of_row + 1);
	}
	// to avoid the case where "-0" appears due to double type
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			if(elm[i][j] == 0){
				elm[i][j] = 0;
			}
		}
	}
}
//calculate the rank
int Matrix::rank() const{
	Matrix temp (*this);
	temp.ref(0);
	//number of rows of which all elements are 0s
	int num_of_zero_row = 0;
	for (int i=0; i<temp.r; i++){
		//number of elements in a row that are 0s
		int num_of_zero = 0;
		for (int j=0; j<temp.c; j++){
			if(!temp.elm[i][j]){
				num_of_zero ++;
			}
			if(num_of_zero == c){
				num_of_zero_row ++;
			}
		}
	}
	return temp.r - num_of_zero_row;
}


//====================
//calculate Trace
double Matrix::calTrace() const{
	//check whether the matrix is a square one
	if(r != c){
		cout<<"It is not a square matrix!"<<endl;
		exit (0);
	}
	else{
		double trace = 0;
		for (int i = 0; i<r; i++){
			trace += elm[i][i];
		}
		return trace;
	}
}

