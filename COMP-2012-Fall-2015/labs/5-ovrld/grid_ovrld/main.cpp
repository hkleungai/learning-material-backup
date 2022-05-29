#include <math.h>
#include "grid3d_ovrld.h"

int main(int argc, char *argv[]) {
   
   grid3d ptA;
   cout << "Creating Point A:\n";
   cout << "Input 3 numbers (separated by space):";
   cin >> ptA;
   cout << "Point A is ";
   ptA.print(); 
   cout << endl << endl;

   grid3d ptB, ptC;
   cout << "Creating Point B and Point C:\n";
   cout << "Input 6 numbers (separated by space):";
   cin >> ptB >> ptC;
   cout << "Point B is ";
   ptB.print(); 
   cout << endl;
   cout << "Point C is ";
   ptC.print(); 
   cout << endl << endl;

   if (ptA == ptB)
     cout << "Point A is equal to point B.";
   else
     cout << "Point A is not equal to point B.";
   cout << endl << endl;

   if (ptB == ptC)
     cout << "Point B is equal to point C.";
   else
     cout << "Point B is not equal to point C.";
   cout << endl << endl;

   cout << "Sum of Point A and Point B is:";
   grid3d ptD = ptA + ptB;
   ptD.print();
   cout << endl << endl;
   
   cout << "Increment Point A by Point B, Point A becomes ";
   ptA.print(); 
   cout << endl << endl;

   cout << "Input a number:";
   double tempNum=0.0; 
   cin >> tempNum;
   cout << "Add Point B to " << tempNum << ", the sum becomes ";
   grid3d ptE = tempNum + ptB;
   ptE.print(); 
   cout << endl << endl;

   cout << "Reversing the coordinates of PtA, Point A becomes:";
   double tempNum2 = ptA[0];
   ptA[0] = ptA[2];
   ptA[2] = tempNum2; 
   ptA.print();
   cout << endl << endl;
      
   return 0;
}
