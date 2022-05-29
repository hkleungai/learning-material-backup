#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H

#include <string>
#include "List.h"

using namespace std;

/* Polynomial class:
   providing operations on polynomial(s)
   e.g. ==, +, -, *, (), +=, -+, *=
 */ 
class Polynomial
{
   public:
     // Default constructor 
     Polynomial();
     // Constructor for constant polynomial
     Polynomial(int c);
     // Convert constructor to create a polynomial from a string 
     Polynomial(const string& s);
     // Copy constructor
     Polynomial(const Polynomial& other);
     // Destructor
     ~Polynomial();

     // print the polynomial a in decreasing order of exponent
     void printPoly(ostream& os) const;

     // read and create a polynomial from a string  
     void readPoly(const string& s);
     
     // sort poly
     void sortPoly();
     // derivative of x
     Polynomial& dx();
     // Equal to operator
     bool operator==(const Polynomial& other) const;

     // Assignment operator
     Polynomial& operator=(const Polynomial& other); 
     // Addition assignment operator
     Polynomial& operator+=(const Polynomial& other); 
     // Subtraction assignment operator
     Polynomial& operator-=(const Polynomial& other); 
     // Multiplication assignment operator
     Polynomial& operator*=(const Polynomial& other); 
 
     // Evaluate the polynomial a at value of x 
     long operator()(int x, int y) const;

   private:
     PolyList polyList;

   // Addition operator
   friend Polynomial operator+(const Polynomial& b, const Polynomial& a);
   // Subtraction operator
   friend Polynomial operator-(const Polynomial& b, const Polynomial& a);
   // Multiplication operator
   friend Polynomial operator*(const Polynomial& b, const Polynomial& a);


   // Output operator
   friend ostream & operator<<(ostream& os, const Polynomial& a);

   // Input operator
   friend istream & operator>>(istream& is, Polynomial& a);
     
};


// Operators as Global functions 
// Addition operator
Polynomial operator+(const Polynomial& b, const Polynomial& a);

// Subtraction operator
Polynomial operator-(const Polynomial& b, const Polynomial& a);

// Multiplication operator
Polynomial operator*(const Polynomial& b, const Polynomial& a);

// Output operator
ostream & operator<<(ostream& os, const Polynomial& a);

// Input operator
istream & operator>>(istream& is, Polynomial& a);


#endif
