/*
 * Lab 5: Container Class and Operator Overloading
 */

#include <iostream>
#include "grid3d_ovrld.h"

using namespace std;

// grid3d: a class to represent a grid point (x, y, z) in 3-dimensional
//         space, where x is the x co-ordinate, y is the y co-ordinate, and
//         z is the z co-ordinate.
//         x is represented by data[0]
//         y is represented by data[1]
//         z is represented by data[2]

// default constructor
grid3d::grid3d ()
{
  data = new double[3];
  data[0] = data[1] = data[2] = 0.0;
}

// copy constructor
grid3d::grid3d (const grid3d & g)
{
  data = new double[3];
  for (int i=0; i<3; i++)
     data[i] = g.data[i];
}

// assignment operator 
grid3d & grid3d::operator=(const grid3d & g)
{
  if (this != &g)
  {
    data = new double[3];
    for (int i=0; i<3; i++)
      data[i] = g.data[i];
  }
  return (*this);
}

// conversion constructor
grid3d::grid3d(double X) {
   data    = new double[3];
   data[0] = X;
   data[1] = 0;
   data[2] = 0;
}

// Another constructor
grid3d::grid3d(double a, double b, double c) {
   data    = new double[3];
   data[0] = a;
   data[1] = b;
   data[2] = c;
}

// destructor
grid3d::~grid3d ()
{
  delete[] data;
}


// This function prints the point in the form of (x, y, z)
void grid3d::print() const { 
   cout << "(" << data[0] << ", " << data[1] << ", " << data[2] << ")"; 
}

// The member functions getx(), gety() and getz() return 
// the x, y and z co-ordinates of the point.
double grid3d::getx () const
{
   return data[0];
}

double grid3d::gety () const
{
   return data[1];
}

double grid3d::getz () const
{
   return data[2];
}

// Overloaded the set function to reset the 
// x co-ordinate, y co-ordinate and z co-ordinate 
void grid3d::set(double x, double y, double z)
{
  data[0] = x;
  data[1] = y;
  data[2] = z;
}

void grid3d::set(double d[])
{
  for (int i=0; i<3; i++)
    data[i] = d[i];
}

// Equal-to operator
// Return true if all three double numbers are the same, otherwise, return false
bool grid3d::operator==(const grid3d& other) const
{
   // add your code

}

// Addition assignment operator
// Add the passed grid3d object to itself
// i.e. the new x is the sum of the two x-coordinates, the new y is the sum of the two y-coordinates, the new z is the sum of the two z-coordinates
grid3d& grid3d::operator+=(const grid3d& other)
{
   // add your code

}

// Subscript operators
// return the nthe element in the data array, i.e. when index is 0, return x; return y when index is 1 and return z when index is 2.
const double& grid3d::operator[](int n) const
{
   // add your code

}

double& grid3d::operator[](int n)
{
   // add your code

}

// Addition operator: non-member function
grid3d operator+(const grid3d& a, const grid3d& b)
{
   // add your code

}

// Overloaded operator >> to read from the input stream 
// Three double numbers, x co-ordinate, y co-ordinate and z co-ordinate are read
// and then put to grid3d
istream& operator>>(istream& is, grid3d& g) 
{
   // add your code

}


