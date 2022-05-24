//CheckBuilding.cpp
//uses building  Class

#include <iostream>  //Library file so uses <>
#include "building.h"      //User Defined so uses ""
using namespace std;

void main()
{
  building Mine, Yours;
  
  Mine.Identify_Writer();
  cout <<endl;
  cout <<"Number of vacancies in Mine is " << Mine.Vacancies() << endl;;
  
  Mine.Display(); 
  Mine.Put("Golin", "123456",0,2);
  Mine.Put("Arya", "234567", 0, 1);
  Mine.Put("Cheng","345678",1,2);
  cout <<"Number of vacancies in Mine is " << Mine.Vacancies() << endl;;
  
  cout << endl << "Display()" << endl;
  Mine.Display() ;
  
  cout << endl << "Display(0)" << endl;
  Mine.Display(0) ;
  
  cout << endl << "Display(1)" << endl;
  Mine.Display(1);
  
  cout << endl << "Display(2)" << endl;
  Mine.Display(2) ;
  
  Mine.Put("Beat", "4567891", 0, 1);
  Mine.Display() ;
  
  cout << endl <<endl <<"Switching to Yours:" << endl;
  Yours.Display();
  Yours.Put("Italiano", "543216",1,2);
  Yours.Put("Chin", "24987", 1, 1);
  Yours.Put("Choeng","876543",2,3);
  Yours.Display(); 
}
