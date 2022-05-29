#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <cstdlib>

using namespace std;

#ifndef _POINT
#define _POINT

bool compare(double a, double b);
bool compare(int a, int b);

// Point class : for storing x and y coordinates
template <class T>
class Point {
  public:
    Point(): x(0), y(0) {};
    Point(T a, T b): x(a), y(b) { };
    Point(const Point& p) {
      this->x = p.x; this->y = p.y;  
    };
    void operator=(const Point& p) { 
      if (this != &p) { this->x = p.x; this->y = p.y; } 
    };
    bool operator==(const Point& p) const { 
     return (compare(this->x, p.x) && compare(this->y, p.y)); 
    };
    void set(T a, T b) { x=a; y=b; };
    T getX() const { return x; };
    T getY() const { return y; };
    T findDistance(const Point& p) const { 
      T dx = (x - p.x); T dy = (y - p.y); return sqrt(pow(dx, 2) + pow(dy, 2)); 
    };
  protected: 
    T x;
    T y;
};

bool compare(double a, double b)
{
  if (abs(a-b) < 0.001)
    return true;
  else 
    return false;

  return (a==b);
}

bool compare(int a, int b)
{
  return (a == b);
}

#endif
