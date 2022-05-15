//CheckPoly.cpp
//tests out polyClass
#include <iostream.h>    //Library file so uses <>
#include "Poly.h"        //User Defined so uses ""
 
void main()
{ polyClass P1(1,1), P2(1,3), P3(4,0), P4(-3,1);
  polyClass Q1, Q2, Q, Q3;
  
  cout << "P1 = "; P1.Display(); cout << endl;
  cout << "P2 = ";  P2.Display(); cout << endl;
  cout << "P3 = ";  P3.Display(); cout << endl;
  cout << "P4 = ";  P4.Display(); cout << endl;
  cout << "Q  = ";  Q.Display(); cout << endl << endl;


  Q1= P1 + P2;
  cout << "Q1 = P1 + P2" << endl;
  cout << "Q1 = ";  Q1.Display(); cout << endl << endl;

  Q2 = Q1 + P3;
  cout << "Q2 = Q1 + P3" << endl;
  cout << "Q2 = ";  Q2.Display(); cout << endl << endl;

  Q = Q1 + Q2;
  cout << "Q  = Q1 + Q2" << endl;
  cout << "Q  = ";  Q.Display(); cout << endl << endl;
 
  Q = Q + P1;
  cout << "Q  = Q + P1" << endl;
  cout << "Q  = ";  Q.Display(); cout << endl << endl;

  Q = Q + P4;
  cout << "Q  = Q + P4" << endl;
  cout << "Q  = ";  Q.Display(); cout << endl << endl;

  Q = Q + P4 + Q1;
  cout << "Q  = Q + P4 + Q1" << endl;
  cout << "Q  = ";  Q.Display(); cout << endl << endl;


  Q3 = Q2 -Q1;
  cout << "Q3 = Q2 - Q1" << endl;
  cout << "Q3 = ";  Q3.Display(); cout << endl << endl;

  Q3 = Q2 -Q2;
  cout << "Q3 = Q2 - Q2" << endl;
  cout << "Q3 = ";  Q3.Display(); cout << endl << endl;

}




  
