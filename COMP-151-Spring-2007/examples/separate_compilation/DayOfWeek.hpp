// DayOfWeek.hpp
// Header File for DayOfWeek

#include "Lang.hpp"

class DayOfWeek
{ 
public:
  // Basic constructor
  // sets day of week to be w
  DayOfWeek(int w);
  
  // Default constructor
  DayOfWeek();

  // Set day of week
  // sets day of week to be w
  void set(int w);

  // Print date
  void print(Lang l);

 private:
  int dayofweek;
};
