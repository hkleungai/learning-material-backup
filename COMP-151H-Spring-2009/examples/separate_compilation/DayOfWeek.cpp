// DayOfWeek.cpp
// Implementation file for the DayOfWeek class

#include <iostream>
#include "DayOfWeek.hpp"

using namespace std;

char* en_dayofweek_names[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

char* zh_dayofweek_names[] = {"xingqi yi", "xingqi er", "xingqi san",
			      "xingqi si", "xingqi wu", "xingqi liu",
			      "xingqi qi"};

DayOfWeek::DayOfWeek(int w)
{
  dayofweek = w;
}

DayOfWeek::DayOfWeek()
{}

void DayOfWeek::set(int w)
{
  dayofweek = w;
}

void DayOfWeek::print(Lang l)
{
  if (l.isChinese()) {
    cout << zh_dayofweek_names[dayofweek];
  } else {
    cout << en_dayofweek_names[dayofweek];
  }
}
