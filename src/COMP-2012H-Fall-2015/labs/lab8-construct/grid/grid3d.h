// DO NOT MODIFY THIS FILE

#include <iostream>

using namespace std;

// grid3d: a class to represent a grid point (x, y, z) in 3-dimensional space, where x is the x co-ordinate, y is the y co-ordinate, and z is the z co-ordinate.
// x is represented by data[0]
// y is represented by data[1]
// z is represented by data[2]

class grid3d {

public:
   // default constructor. It creates a point (0,0,0)
   grid3d();

   // copy constructor
   grid3d(const grid3d&);

   // conversion constructor that can convert an integer to a grid3d object
   grid3d(int);

   // another constructor
   grid3d(int, int, int);
 
   // destructor;
   ~grid3d();

   // assignment operator
   grid3d & operator=(const grid3d&);

   // function for output. 
   void print() const;

   // Three functions to return the co-ordinates of the grid point
   // getx() returns the integer x co-ordinate
   // gety() returns the integer y co-ordinate
   // getz() returns the integer z co-ordinate
   int getx() const;
   int gety() const;
   int getz() const;

   // Overload the operator ">>" such that if PT is of type grid3d, cin >> PT   asks the user for three integers: x co-ordinate, y co-ordinate and z co-ordinate.
   friend istream& operator>>(istream&, grid3d&);

private:
   int* data;
} ;

