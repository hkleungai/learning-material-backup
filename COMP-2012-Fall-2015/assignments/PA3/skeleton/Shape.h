#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <cstdlib>
#include "Point.h"

using namespace std;

#ifndef _SHAPE
#define _SHAPE

// Shape class : an abstract class
template <class T>
class Shape {
  public:
    Shape(): color(""), filled(false) { };
    Shape(string c, bool f=false): color(c), filled(f) { };
    void setColor(string c) { color = c; };
    string getColor() const { return color; };  
    bool isFilled() const { return filled; };
    void setFilled(bool f) { filled = f; };
    virtual T getPerimeter() const = 0;
    virtual void read(istream&) = 0;
    virtual void print(ostream&) const = 0; 

  protected:
    string color;
    bool filled;
};

// input/output operators
template <class T>
istream& operator>>(istream& is, Shape<T>& s)
{
  s.read(is);
  return (is);
}

template <class T>
ostream& operator<<(ostream& os, const Shape<T>& s)
{
  s.print(os);
  return (os);
}

#endif
