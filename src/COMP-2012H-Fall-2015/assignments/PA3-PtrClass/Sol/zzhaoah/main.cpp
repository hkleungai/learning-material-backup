//
//  main.cpp
//  PA3
//
//  Created by Felix Zhao on 13/10/2015.
//  Copyright © 2015 Felix Zhao. All rights reserved.
//

#include <iostream>
#include "matrix.h"

//#include "ExpressionTree.h"
//#include "Symbol.h"
//std::cout<<""<<std::endl;

int main(int argc, const char * argv[]) {
    //for(;;){
    std::cout<<"---------PA3 Demo---------"<<std::endl;
    std::cout<<"1. Matrix Creation"<<std::endl;
    std::cout<<"   1.1 Real Matrix"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"In[1]:=mat1 = {{2,4,0},{3,5,5}}"<<std::endl;
    Matrix mat1(2,3);
    mat1.el(0, 0) = 2; mat1.el(0, 1) = 4; mat1.el(0, 2) = 0;
    mat1.el(1, 0) = 3; mat1.el(1, 1) = 5; mat1.el(1, 2) = 5;
    std::cout<<"Out[1]="<<std::endl;
    mat1.printMatrix();
    std::cout<<""<<std::endl;
    std::cout<<"   1.2 Complex Matrix"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"In[2]:=mat2 = {{2,4+2I,3I},{3+I,5,5+0.35I},{2,0,1}}"<<std::endl;
    CplxMatrix mat2(3,3);
    mat2.el(0, 0).re = 2; mat2.el(0, 1).re = 4; mat2.el(0, 2).re = 0;
    mat2.el(1, 0).re = 3; mat2.el(1, 1).re = 5; mat2.el(1, 2).re = 5;
    mat2.el(2, 0).re = 2; mat2.el(2, 1).re = 0; mat2.el(2, 2).re = 1;
    mat2.el(0, 1).im = 2; mat2.el(0, 2).im = 3;
    mat2.el(1, 0).im = 1; mat2.el(1, 2).im = 0.35;
    std::cout<<"Out[2]="<<std::endl;
    mat2.printMatrix();
    std::cout<<""<<std::endl;
    
    std::cout<<"2. Element-wise Operations"<<std::endl;
    std::cout<<"   2.1 Element-wise Plus"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"In[3]:= mat3 = mat1 + mat1"<<std::endl;
    Matrix mat3 = mat1.plus(mat1);
    std::cout<<"Out[3]="<<std::endl;
    mat3.printMatrix();
    std::cout<<""<<std::endl;
    std::cout<<"   2.2 Element-wise Times"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"In[4]:= mat4 = mat1 * mat3"<<std::endl;
    Matrix mat4 = mat1.times(mat3);
    std::cout<<"Out[4]="<<std::endl;
    mat4.printMatrix();
    std::cout<<""<<std::endl;
    
    std::cout<<"3. Basic Matrix Calculations"<<std::endl;
    std::cout<<"   3.1.1 Dot Product"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"In[5]:= Dot[mat1,{{2,5},{5,3},{6,4}}]"<<std::endl;
    Matrix mat31(3,2);
    mat31.el(0, 0) = 2;mat31.el(0, 1) = 5;
    mat31.el(1, 0) = 5;mat31.el(1, 1) = 3;
    mat31.el(2, 0) = 6;mat31.el(2, 1) = 4;
    Matrix out5 = mat1.mul(mat31);
    std::cout<<"Out[5]="<<std::endl;
    out5.printMatrix();
    std::cout<<""<<std::endl;
    std::cout<<"   3.1.2 Complex Dot Product"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"In[6]:= Dot[mat2,{{2,5+I},{5,3},{6+3I,4I}}]"<<std::endl;
    CplxMatrix mat31c(3,2);
    mat31c.el(0, 0).re = 2;mat31c.el(0, 1).re = 5;
    mat31c.el(1, 0).re = 5;mat31c.el(1, 1).re = 3;
    mat31c.el(2, 0).re = 6;mat31c.el(2, 1).re = 0;
    mat31c.el(0, 1).im = 1;mat31c.el(2, 0).im = 3;
    mat31c.el(2, 1).im = 4;
    
    CplxMatrix out6 = mat2.mul(mat31c);
    std::cout<<"Out[6]="<<std::endl;
    out6.printMatrix();
    std::cout<<""<<std::endl;
    
    std::cout<<"   3.2.1 Inverse"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"In[7]:= Inverse[{{4,2,6},{3,5,2},{1,3,1.5}}]"<<std::endl;
    Matrix mat321(3,3);
    mat321.el(0, 0) = 4; mat321.el(0, 1) = 2; mat321.el(0, 2) = 6;
    mat321.el(1, 0) = 3; mat321.el(1, 1) = 5; mat321.el(1, 2) = 2;
    mat321.el(2, 0) = 1; mat321.el(2, 1) = 3; mat321.el(2, 2) = 1.5;
    Matrix out7 = mat321.inverse();
    std::cout<<"Out[7]="<<std::endl;
    out7.printMatrix();
    std::cout<<""<<std::endl;
    
    std::cout<<"   3.2.2 Complex Inverse"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"In[8]:= Inverse[{{4+I,2,6},{3,5-I,2},{I,3,1.5}}]"<<std::endl;
    CplxMatrix mat322(3,3);
    mat322.el(0, 0).re = 4; mat322.el(0, 1).re = 2; mat322.el(0, 2).re = 6;
    mat322.el(1, 0).re = 3; mat322.el(1, 1).re = 5; mat322.el(1, 2).re = 2;
    mat322.el(2, 0).re = 0; mat322.el(2, 1).re = 3; mat322.el(2, 2).re = 1.5;
    mat322.el(0, 0).im = 1; mat322.el(1, 1).im = -1;mat322.el(2, 0).im = 1;
    CplxMatrix out8 = mat322.inverse();
    std::cout<<"Out[8]="<<std::endl;
    out8.printMatrix();
    std::cout<<""<<std::endl;
    
    std::cout<<"4. Basic Matrix Operations"<<std::endl;
    std::cout<<"   4.1 Transpose"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"In[9]:= Transpose[mat1]"<<std::endl;
    std::cout<<"Out[9]="<<std::endl;
    mat1.transpose().printMatrix();
    std::cout<<""<<std::endl;
    std::cout<<"   4.2 Conjugate Transpose"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"In[10]:= ConjugateTranspose[mat2]"<<std::endl;
    std::cout<<"Out[10]="<<std::endl;
    mat2.ConjugateTranspose().printMatrix();
    std::cout<<""<<std::endl;
    std::cout<<"   4.3 Trace"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"In[11]:= Tr[mat2]"<<std::endl;
    std::cout<<"Out[11]="<<std::endl;
    displayComplex(mat2.trace());
    std::cout<<""<<std::endl;
    std::cout<<"   4.4 Determinant"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"In[12]:= Det[mat2]"<<std::endl;
    std::cout<<"Out[12]="<<std::endl;
    displayComplex(mat2.det());
    std::cout<<""<<std::endl;
    std::cout<<"   4.5 Permanent"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"In[13]:= Permanent[mat2]"<<std::endl;
    std::cout<<"Out[13]="<<std::endl;
    displayComplex(mat2.perm());
    std::cout<<""<<std::endl;
    
    std::cout<<"5. Matrix Functions"<<std::endl;
    std::cout<<"   5.1 Matrix Power"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"In[14]:= MatrixPower[{{1,2},{3,4}},5]"<<std::endl;
    Matrix mat41(2,2);
    mat41.el(0, 0) = 1; mat41.el(0, 1) = 2;
    mat41.el(1, 0) = 3; mat41.el(1, 1) = 4;
    std::cout<<"Out[14]="<<std::endl;
    mat41.matpower(5).printMatrix();
    std::cout<<""<<std::endl;
    std::cout<<"In[15]:= MatrixPower[mat2,10]"<<std::endl;
    std::cout<<"Out[15]="<<std::endl;
    mat2.matpower(10).printMatrix();
    std::cout<<""<<std::endl;
    
    std::cout<<"6. Linear Systems"<<std::endl;
    std::cout<<"   6.1 Solve a Linear System"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"In[16]:=Solve[x1 + 2 x2 + 3 x3 + 4 x4 == 4 && 2 x1 + 3 x2 + 4 x3 + 5 x4 == 3 &&3 x1 + 4 x2 + 5 x3 + 6 x4 == 2, {x1, x2}]"<<std::endl;
    Matrix mat51(3, 5);
    mat51.el(0, 0) = 1; mat51.el(0, 1) = 2; mat51.el(0, 2) = 3; mat51.el(0, 3) = 4; mat51.el(0, 4) = 4;
    mat51.el(1, 0) = 2; mat51.el(1, 1) = 3; mat51.el(1, 2) = 4; mat51.el(1, 3) = 5; mat51.el(1, 4) = 3;
    mat51.el(2, 0) = 3; mat51.el(2, 1) = 4; mat51.el(2, 2) = 5; mat51.el(2, 3) = 6; mat51.el(2, 4) = 2;
    std::cout<<"Out[16]="<<std::endl;
    mat51.SolveLinearSystem().printMatrix();
    std::cout<<"The solution is displayed as a variable * variable+1 matrix formed by column vectors which is the coeffcient of each variable, and the last column is the constant part."<<std::endl;
    std::cout<<"In this problem, the result matrix can be intepreted as x1 -> -6 + x3 + 2 x4, x2 -> 5 - 2 x3 - 3 x4"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"   6.2 Null Space (Kernel)"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"In[17]:=NullSpace[{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}]"<<std::endl;
    Matrix mat52(3, 3);
    mat52.el(0, 0) = 1; mat52.el(0, 1) = 2; mat52.el(0, 2) = 3;
    mat52.el(1, 0) = 4; mat52.el(1, 1) = 5; mat52.el(1, 2) = 6;
    mat52.el(2, 0) = 7; mat52.el(2, 1) = 8; mat52.el(2, 2) = 9;
    std::cout<<"Out[17]="<<std::endl;
    mat52.kernel().printMatrix();
    std::cout<<""<<std::endl;
    std::cout<<"   6.3 Range "<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"*****Note that this function is not implemented in Mathematica"<<std::endl;
    std::cout<<"In[18]:=MatrixRange[{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}]"<<std::endl;
    std::cout<<"Out[18]="<<std::endl;
    mat52.range().printMatrix();
    std::cout<<""<<std::endl;
    std::cout<<"   6.4 Rank "<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"In[19]:=MatrixRank[{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}]"<<std::endl;
    std::cout<<"Out[19]="<<std::endl;
    std::cout<<mat52.matrixRank()<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"   6.5.1 RowReduce "<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"In[20]:=RowReduce[mat2]"<<std::endl;
    std::cout<<"Out[20]="<<std::endl;
    mat2.rowReduce().printMatrix();
    std::cout<<""<<std::endl;
    std::cout<<"In[21]:=RowReduce[{{1,2,3,4},{2,3,4,5},{3,4,5,6}}]"<<std::endl;
    std::cout<<"Out[21]="<<std::endl;
    Matrix mat55(3, 4);
    mat55.el(0, 0) = 1; mat55.el(0, 1) = 2; mat55.el(0, 2) = 3; mat55.el(0, 3) = 4;
    mat55.el(1, 0) = 2; mat55.el(1, 1) = 3; mat55.el(1, 2) = 4; mat55.el(1, 3) = 5;
    mat55.el(2, 0) = 3; mat55.el(2, 1) = 4; mat55.el(2, 2) = 5; mat55.el(2, 3) = 6;
    mat55.rowReduce().printMatrix();
    std::cout<<"   6.5.2 RowReduce with Step-by-step Solution"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"*****Note that this function is not implemented in Mathematica"<<std::endl;
    std::cout<<"In[22]:=RowReduce[{{1,2,3,4},{2,3,4,5},{3,4,5,6}}, ShowSteps->True]"<<std::endl;
    std::cout<<"Out[22]="<<std::endl;
    mat55.rowReduceShowSteps().printMatrix();
    std::cout<<""<<std::endl;
    std::cout<<"7. Advanced Matrix Operations"<<std::endl;
    std::cout<<"   These functions can find all eigenvalues and eigenvectors for arbitrary dimension square complex matrix"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"***Please note that the order of the eigenvalues/eigenvectors may be different from Mathematica"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"***Since eigenvectors can be multiplicated by a scalar, a modification was made in the verification Mathematica code to ensure the last component of the vector is 1"<<std::endl;
    std::cout<<"   7.1 Eigenvalues"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"In[23]:=mat61 = {{5, 2, 5, 6, 3}, {4, 3.5, 10, 6, 9}, {1.7, 1, 5.5, 3, 2}, {6, -2, 5, 4, 6}, {1, 4, 3.2, 1, 0}};"<<std::endl;
    Matrix mat61(5,5);
    mat61.el(0, 0) = 5; mat61.el(0, 1) = 2; mat61.el(0, 2) = 5; mat61.el(0, 3) = 6; mat61.el(0, 4) = 3;
    mat61.el(1, 0) = 4; mat61.el(1, 1) = 3.5; mat61.el(1, 2) = 10; mat61.el(1, 3) = 6; mat61.el(1, 4) = 9;
    mat61.el(2, 0) = 1.7; mat61.el(2, 1) = 1; mat61.el(2, 2) = 5.5; mat61.el(2, 3) = 3; mat61.el(2, 4) = 2;
    mat61.el(3, 0) = 6; mat61.el(3, 1) = -2; mat61.el(3, 2) = 5; mat61.el(3, 3) = 4; mat61.el(3, 4) = 6;
    mat61.el(4, 0) = 1; mat61.el(4, 1) = 4; mat61.el(4, 2) = 3.2; mat61.el(4, 3) = 1; mat61.el(4, 4) = 0;
    std::cout<<""<<std::endl;
    std::cout<<"In[24]:=Eigenvalues[mat61]"<<std::endl;
    std::cout<<"Out[24]="<<std::endl;
    mat61.eigenvalues().printMatrix();
    std::cout<<""<<std::endl;
    std::cout<<"In[25]:=mat62 = {{1 + I, 2, 3}, {3 I, 2, 5}, {4 + 2.5 I, 3 I, 7 + 5 I}};"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"In[26]:=Eigenvalues[mat62]"<<std::endl;
    CplxMatrix mat62(3,3);
    mat62.el(0, 0).re = 1; mat62.el(0, 1).re = 2; mat62.el(0, 2).re = 3;
    mat62.el(1, 0).re = 0; mat62.el(1, 1).re = 2; mat62.el(1, 2).re = 5;
    mat62.el(2, 0).re = 4; mat62.el(2, 1).re = 0; mat62.el(2, 2).re = 7;
    mat62.el(0, 0).im = 1; mat62.el(1, 0).im = 3; mat62.el(2, 0).im = 2.5;
    mat62.el(2, 1).im = 3; mat62.el(2, 2).im = 5;
    std::cout<<"Out[26]="<<std::endl;
    mat62.eigenvalues().printMatrix();
    std::cout<<""<<std::endl;
    std::cout<<"   7.2 Eigenvetors"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"In[27]:=Eigenvectors[mat61]"<<std::endl;
    std::cout<<"Out[27]="<<std::endl;
    mat61.eigenvectors().printMatrix();
    std::cout<<""<<std::endl;
    std::cout<<"In[28]:=Eigenvectors[mat62]"<<std::endl;
    std::cout<<"Out[28]="<<std::endl;
    mat62.eigenvectors().printMatrix();
    //}
    return 0;
}