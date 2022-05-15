#include <iostream.h>  //Library file so uses <>


class Date {
public:
 Date(int x, int y, int z); 
      Date();
      void set(int m, int d, int y);
      void print();
private:
int month;
int day;
int year;
}; 



Date::Date(int m, int d, int y)
{ month =m;  day =d; year =y;}

Date::Date()
{}

void Date::set(int m, int d, int y)
{ month =m;  day =d; year =y;}

void Date::print()
{cout << day << "/";
 cout << month << "/" <<year << endl;
}


//uses Date Class

void main()
{ 
	
	Date  Today(2,4,2001), When;

  cout << "Today is "; Today.print();

  When.set(6,1,2002);
  cout << "When is "; When.print();
}
