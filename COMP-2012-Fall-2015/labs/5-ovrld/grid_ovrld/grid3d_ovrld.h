/*
 * Lab 5: Container Class and Operator Overloading 
 * File: grid3d_ovld.h
 */

#include <iostream>

using namespace std;

// grid3d: a class to represent a grid point (x, y, z) in 3-dimensional
//         space, where x is the x co-ordinate, y is the y co-ordinate, and
//         z is the z co-ordinate.
//         x is represented by data[0]
//         y is represented by data[1]
//         z is represented by data[2]

class grid3d {

public:
   // default constructor. It creates a point (0,0,0)
   grid3d();

   // copy constructor
   grid3d(const grid3d&);

   // conversion constructor that can convert an double to a grid3d object
   grid3d(double);

   // another constructor
   grid3d(double, double, double);
 
   // destructor;
   ~grid3d();

   // assignment operator
   grid3d & operator=(const grid3d & );

   // function for output. 
   void print() const;

   // set the x, y, and z coordinates by 3 double numbers
   void set(double, double, double);

   // overload the set function to accept a double array
   void set(double []);

   // Three functions to return the co-ordinates of the grid point
   // getx() returns the integer x co-ordinate
   // gety() returns the integer y co-ordinate
   // getz() returns the integer z co-ordinate
   double getx() const;
   double gety() const;
   double getz() const;

   // More operators

   // Equal-to operator 
   bool operator==(const grid3d &) const;

   // addition assignment operator
   grid3d& operator+=(const grid3d &); 

   // subscripting operator 
   const double& operator[](int) const; 
   double& operator[](int); 

   // fried functions: non-member functions

   // addition operator
   friend grid3d operator+(const grid3d &, const grid3d &);

   // input operator
   friend istream& operator>>(istream& is, grid3d&);

private:
   double *data;
};

// non-member addition operator
grid3d operator+(const grid3d&, const grid3d&);

// input operator 
istream& operator>>(istream&, grid3d&);

