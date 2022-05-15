// Date.cpp
// Implementation file for the Date class

#include <iostream>    // Library file, so uses <>
#include "Date.hpp"    // User-defined, so uses ""

using namespace std;

Date::Date(int m, int d, int y)
{
  month = m;  day = d; year = y;
}

Date::Date()
{}

void Date::set(int m, int d, int y)
{ month = m;  day = d; year = y;}

void Date::print()
{
  cout << day << "/";
  cout << month << "/" <<year << endl;
}
