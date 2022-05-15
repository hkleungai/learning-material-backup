// CheckDate2.cpp
// uses Date2 and DayOfWeek classes

#include <iostream>    // Library file, so uses <>
#include "Date2.hpp"   // User-defined, so uses ""
#include "DayOfWeek.hpp"

using namespace std;

int main()
{
  Date2 today(13, 2, 2006);
  DayOfWeek dayofweek(1);

  cout << "today is ";
  dayofweek.print(Lang("en"));
  cout << " ";
  today.print(Lang("en"));
  cout << endl;

  cout << "jintian shi ";
  today.print(Lang("zh"));
  cout << " ";
  dayofweek.print(Lang("zh"));
  cout << endl;
}
