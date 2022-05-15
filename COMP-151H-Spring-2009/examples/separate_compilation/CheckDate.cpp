// CheckDate.cpp
// uses Date Class

#include <iostream>    // Library file, so uses <>
#include "Date.hpp"    // User-defined, so uses ""

using namespace std;

int main()
{ Date today(10, 2, 2006), someday;

  cout << "today is "; today.print();

  someday.set(14, 2, 2006);
  cout << "someday is "; someday.print();
}


