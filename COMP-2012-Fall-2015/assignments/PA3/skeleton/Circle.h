#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <cstdlib>
#include "Shape.h"

using namespace std;

const double PI = 3.14;

#ifndef _CIRCLE
#define _CIRCLE

template <class T>
class Circle: public Shape<T> {
  public:
    Circle();
    Circle(string c, bool f, T x, T y, T r);
    Circle(const Circle& other);
    Circle& operator=(const Circle& other);
    bool operator==(const Circle& other) const;
    T getArea() const;
    T getPerimeter() const;
    virtual void read(istream& is);
    virtual void print(ostream& os) const;
  private:
    Point<T> center;
    T radius;
};

/********** Add your implementation of the above members functions below *********/

#endif
