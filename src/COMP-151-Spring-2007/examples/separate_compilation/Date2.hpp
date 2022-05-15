// Date2.hpp
// Header File for Date2

#include "Lang.hpp"

class Date2
{ 
public:
  // Basic constructor
  // sets date to be d/m/y
  Date2(int m, int d, int y);
  
  // Default constructor
  Date2();

  // Set date
  // sets date to be d/m/y
  void set(int m, int d, int y);

  // Print date
  void print(Lang l);

 private:
  int month;
  int day;
  int year;
};
