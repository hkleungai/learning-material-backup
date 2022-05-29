// COMP2012H Lab 7

#include <iostream>
using namespace std;

class Date {
public:
  Date(int day, int month, int year);
  Date();

private:
  int day;
  int month;
  int year;
};

Date::Date(int d, int m, int y) {
  day = d;
  month = m;
  year = y;
};

Date::Date() {
};

void Date::set(int d, int m, int y) {
  day = d;
  month = m;
  year = y;
}

void Date::print() {
  cout << day << "/" << month << "/" << year << endl;
}

int main() {
  cout << "Enter today's date (day month year): ";
  //TODO: create new Date objects "today" according to the input

  //TODO: display the date of today

  //TODO: create new Date object "deadline". the deadline is Oct 15, 2015.

  //TODO: print the date of today and the assignment's deadline, as well as whether the assginment is due.

  return 0;
};
