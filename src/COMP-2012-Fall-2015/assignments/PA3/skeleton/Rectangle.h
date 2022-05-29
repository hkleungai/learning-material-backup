#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <cstdlib>
#include "Polygon.h"

using namespace std;

#ifndef _RECTANGLE
#define _RECTANGLE

template <class T>
class Rectangle: public Polygon<T> {
  public:
    Rectangle();
    Rectangle(const vector< Point<T> >& pts);
    Rectangle(const Rectangle& other);
    T getArea() const; 
    void read(istream& is);
    void print(ostream& os) const;
    T getWidth() const;
    T getHeight() const;
};

/********** Add your implementation of the above members functions below *********/

#endif
