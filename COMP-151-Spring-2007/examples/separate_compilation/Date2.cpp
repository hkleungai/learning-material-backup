// Date2.cpp
// Implementation file for the Date2 class

#include <iostream>    // Library file, so uses <>
#include "Date2.hpp"    // User-defined, so uses ""

using namespace std;

Date2::Date2(int m, int d, int y)
{
  month = m;  day = d; year = y;
}

Date2::Date2()
{}

void Date2::set(int m, int d, int y)
{ month = m;  day = d; year = y;}

void Date2::print(Lang l)
{
  if (l.isChinese()) {
    cout << year << "." << month << "." << day;
  } else {
    cout << month << "/" << day << "/" << year;
  }
}
