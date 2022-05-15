// Date.hpp
// Header File for Date

class Date
{ 
public:
  // Basic constructor
  // sets date to be d/m/y
  Date(int m, int d, int y);
  
  // Default constructor
  Date();

  // Set date
  // sets date to be d/m/y
  void set(int m, int d, int y);

  // Print date
  void print();

 private:
  int month;
  int day;
  int year;
};
