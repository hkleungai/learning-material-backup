//CheckBuilding.cpp
//uses building  Class

#include <iostream>  //Library file so uses <>
#include "building.h"      //User Defined so uses ""
#include <fstream>
using namespace std;

int main()
{
  building Mine(3, 3);
  building Yours(3, 5, "Lisa","333333");
  
  Mine.Identify_Writer();
  cout <<endl;
  cout <<"Number of vacancies in Mine is " << Mine.Vacancies() << endl;;
  
  Mine.Display(); 
  Mine.Put("Dora", "123456",0,2);
  Mine.Put("John", "234567", 0, 1);
  Mine.Put("Daisy","345678",1,2);
  cout <<"Number of vacancies in Mine is now " << Mine.Vacancies() << endl;
  
  cout << endl << "Display()" << endl;
  Mine.Display() ;
  
  cout << endl << "Display(0)" << endl;
  Mine.Display(0) ;
  
  cout << endl << "Display(1)" << endl;
  Mine.Display(1);
  
  cout << endl << "Display(2)" << endl;
  Mine.Display(2) ;
  
  cout << endl << "Put Jane" << endl;
  Mine.Put("Jane", "4567891", 0, 1);
  Mine.Display() ;

  cout << endl << "Put Maple" << endl;
  Mine.Put("Maple", "5678912", 3, 1);
  Mine.Display() ;

  Mine.AddFloor(2);
  cout << endl << "Put Maple Again" << endl;
  Mine.Put("Maple", "5678912", 3, 1);
  Mine.Display() ;

  Mine.RemoveRoom(1);
  cout << endl << "Remove Room 2 on Floor 1" << endl;
  Mine.Display() ;

  Mine.AddRoom(0);
  cout << endl << "Add Room 3 on Floor 0" << endl;
  Mine.Put("Beryl", "6789123", 0, 3);
  Mine.Display() ;
  
  cout << endl <<"Switching to Yours:" << endl;
  Yours.Display();
  cout << endl;
  Yours.Put("Harry", "543216",1,2);
  Yours.Put("Paul", "24987", 1, 1);
  Yours.Put("Bryce","876543",2,3);
  Yours.Display(); 

  cout << endl << "Names of all occupants of Yours: " << endl;
  cout << Yours;
}
