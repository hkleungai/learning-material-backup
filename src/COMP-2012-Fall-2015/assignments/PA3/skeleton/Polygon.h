#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <cstdlib>
#include "Shape.h"

using namespace std;

#ifndef _POLYGON
#define _POLYGON

// class Polygon: abstract base class
template <class T>
class Polygon: public Shape<T> {
  public:
    Polygon();
    Polygon(const vector< Point<T> > ptsVector); 
    Polygon(const Polygon& other);
    Polygon& operator=(const Polygon& other);
    bool operator==(const Polygon& other) const;
    Polygon& operator+=(const Point<T>& pt);
    Polygon& operator-=(int index);
    void printPts(ostream& os) const;
    virtual T getPerimeter() const;
    virtual void read(istream& is);
    virtual void print(ostream& os) const;
        
  protected:
    list< Point<T> > points;
    int numOfPoints;
};

/********** Add your implementation of the above members functions below *********/

#endif
