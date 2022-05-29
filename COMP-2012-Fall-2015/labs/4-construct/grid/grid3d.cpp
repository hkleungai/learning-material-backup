#include <iostream>
#include "grid3d.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////

// default constructor
// Remember to allocate the array data[]
// data[0], data[1] and data[2] represent x, y, z respectively
// It should also print "default constructor" (with newline) to cout

grid3d::grid3d ()
{
   // add your code here:
   // 

}


////////////////////////////////////////////////////////////////////////////////

// copy constructor
// You have to a deep copy, not shallow copy!
// It should also print "copy constructor" (with newline) to cout

grid3d::grid3d (const grid3d & g)
{
   // add your code here
   //

}

// assignment operator 
// You have to a deep copy, not shallow copy!
// It is similar to copy constructor
grid3d & grid3d::operator=(const grid3d & g)
{
   // add your code here
   //

   return (*this);
}


////////////////////////////////////////////////////////////////////////////////

// conversion constructor
// You can call it by "grid3d(2)", or by "grid3d x = 2;"
grid3d::grid3d(double X) {
   data    = new double[3];
   data[0] = X;
   data[1] = 0;
   data[2] = 0;
   cout << "conversion constructor" << endl;
}

////////////////////////////////////////////////////////////////////////////////
// Another constructor
grid3d::grid3d(double a, double b, double c) {
   data    = new double[3];
   data[0] = a;
   data[1] = b;
   data[2] = c;
   cout << "typical constructor" << endl;
}


////////////////////////////////////////////////////////////////////////////////

// destructor
// Remember to free all dynamically allocated objects here!
// It should also print "In destructor" (with newline) to cout

grid3d::~grid3d ()
{
   // add your code here
   //

}


////////////////////////////////////////////////////////////////////////////////
// This function prints the point in the form of (x, y, z)
void grid3d::print() const { 
   cout << "(" << data[0] << ", " << data[1] << ", " << data[2] << ")"; 
}

////////////////////////////////////////////////////////////////////////////////
// Overloaded the set function to reset the 
// x co-ordinate, y co-ordinate and z co-ordinate 

void grid3d::set(double x, double y, double z)
{
  data[0] = x;
  data[1] = y;
  data[2] = z;
}

// overload the set() to reset the x, y, and z coordinates given an double array in paramemter
// add your code here





////////////////////////////////////////////////////////////////////////////////
// The member functions getx(), gety() and getz() return 
// the x, y and z co-ordinates of the point.

double grid3d::getx () const
{
   // add your code here
   //

}

double grid3d::gety () const
{
   // add your code here
   //

}

double grid3d::getz () const
{
   // add your code here
   //

}


