/*
 * tester.cpp
 *
 *  Created on: 2015Äê10ÔÂ2ÈÕ
 *      Author: ThinkPad
 */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Matrix.h"
using namespace std;
int main(){
	srand(time(0));
	int row=3; int col=3;
	//1.construct a new matrix
	Matrix A(row,col);
	//6.element access
	//specific values for matrix A:
	for (int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			A.el(i,j) = (double) rand()/RAND_MAX*100;
		}
	}
	/*
	A.el(0,0)=2;A.el(0,1)=2;A.el(0,2)=3;//A.el(0,3)=7;//when exceed size it does not assign value
	A.el(1,0)=3;A.el(1,1)=2;A.el(1,2)=3;//A.el(1,3)=8;
	A.el(2,0)=8;A.el(2,1)=9;A.el(2,2)=10;//A.el(2,3)=12;
	//A.el(3,0)=7;A.el(3,1)=5;A.el(3,2)=5;A.el(3,3)=-4;
	*/
	//2.copy constructor
	Matrix AA(A);
	cout<<"Matrix AA is:"<<endl;
	AA.print();
	//4&5. inspector functions for row and column
	cout<<"no. of cols of AA: "<<AA.cols()<<", no. of rows of AA: "<<AA.rows()<<endl;
	Matrix to_be_assigned(0,0);
	//7.assign function
	cout<<"the assigned function is: "<<endl;
	to_be_assigned.assign(A);
	to_be_assigned.print();



	cout<<"A is: "<<endl;
	A.print();

	Matrix B(3,3);
	B.el(0,0)=6;	B.el(0,1)=5;	B.el(0,2)=4;
	B.el(1,0)=9;	B.el(1,1)=10;	B.el(1,2)=8;
	B.el(2,0)=8;	B.el(2,1)=7;	B.el(2,2)=9;
	cout<<"matrix B is"<<endl;
	B.print();
	cout<<"2*A+3*B = "<<endl;
	(A.add(B,2,3)).print();

	//8. matrix multiplication
	cout<<"A*B = "<<endl;
	(A.mul(B)).print();

	//9. transpose function
	cout<<"The transpose of A is:"<<endl;
	(A.transpose()).print();

	cout<<"the submatrix of A without the 2nd row and 1st column is:"<<endl;
	Matrix C(1,0,A);
	C.print();

	//calculate the power of A
	cout<<"A^(-2) = "<<endl;
	Matrix E = A.power(A,-2);
	E.print();
	//C.print();
	//B1.print();
	Matrix b(col,1);
	b.el(0,0)=1;
	b.el(1,0)=2;
	b.el(2,0)=3;
	//b.el(3,0)=;
	//calculate the solution of Ax=b
	cout<<"The solution of Ax = b is: "<<endl;
	(A.sol(b)).print();
	//calculate the rank of A
	cout<<"the rank of A is: "<<A.rank()<<endl;

	//transform A into row-echelon form
	A.ref(0);
	cout<<"REF of A is"<<endl;
	A.print();

	//calculate the trace of A
	cout<<"the trace of A is"<<endl;
	cout<<A.calTrace()<<endl;

	//calculate the determinant of A
	cout<<"Determinant of A is "<<endl;
	cout<<A.calDet(3)<<endl;

	//10.inverse function
	cout<<"the inverse of A is "<<endl;
	Matrix D = A.inverse();
	D.print();



	return 0;
}



