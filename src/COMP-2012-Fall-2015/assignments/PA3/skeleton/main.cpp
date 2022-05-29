#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <cstdlib>

#include "Circle.h"
#include "Rectangle.h"

using namespace std;

int main(void)
{
  /*
  Point<double> pt1(1.2, 2.53);
  cout << "pt1: " << pt1.getX() << ", " << pt1.getY() << endl;
  Point<double> pt2(2.2, 3.53);
  cout << "pt2: " << pt2.getX() << ", " << pt2.getY() << endl;
 
  cout << "testing Point::operator==()" << endl; 
  if (pt1 == pt2)
    cout << "pt1 is equal to pt2" << endl;

  cout << "The distance between pt1 and pt2: "; 
  cout << pt1.findDistance(pt2) << endl;
  */ 

  cout << "~~~ Testing the Circle Class ~~~" << endl;  
  cout << "Creating a Circle with radius in int type (with convert constructor):" << endl;  
  Circle<int> c1("red", false, 10, 20, 30);

  cout << "Creating a Circle with data in double type:" << endl;  
  Circle<double> c2("green", true, 2.4, 3.6, 4.8);

  cout << "Testing the output operator:" << endl;
  cout << "c1 " << c1 << endl;
  cout << "c2 " << c2 << endl;

  cout << "Testing Circle copy constructor:" << endl;
  Circle<double> c3(c2);  
  cout << "c3 " << c3 << endl; 

  cout << "Testing the input operator:" << endl;
  cout << "Input the data (format: color filled x y radius; e.g. blue 0 5.5 6.5 7.5):";  
  cin >> c3;
  
  cout << "Testing Circle::operator==()" << endl; 
  if (c2 == c3)
    cout << "c2 is equal to c3" << endl;
  else
    cout << "c2 is not equal to c3" << endl;

  Circle<int> c4("red", true, 20, 10, 5);
  c1=c4;
  cout << "c1 " << c1 << endl;

  cout << "~~~ Testing the Polygon Class ~~~" << endl;  
  vector< Point<double> > pts;
  pts.push_back(Point<double>(6.2, 5.9)); 
  pts.push_back(Point<double>(7.12, 3.556)); 
  pts.push_back(Point<double>(6.2, 1.9)); 
  pts.push_back(Point<double>(3.512, 1.2)); 
  pts.push_back(Point<double>(1, 3.5)); 
  cout << "Testing the convert constructor:" << endl;
  Polygon<double> p1(pts);
  cout << "Testing the output operator:" << endl;
  cout << "p1 " << p1 << endl;
  cout << "Testing the copy constructor:" << endl;
  Polygon<double> p2(p1);
  cout << "p2 " << p2 << endl;
  cout << "Testing the input operator:" << endl;
  cout << "Input the data (format: color filled #pts x1 y1 x2 y2 ...;  e.g. blue 0 3 5.5 6.5 0 0 -5.5 6.5):";  
  cin >> p2;
  cout << "p2 " << p2 << endl;

  cout << "Testing Polygon::operator==()" << endl; 
  if (p1 == p2)
    cout << "p1 is equal to p2" << endl;
  else
    cout << "p1 is not equal to p2" << endl;
 
  Point<double> pt1(0, 9.2); 
  cout << "Testing Polygon::operator+=()" << endl; 
  p2+=pt1;
  cout << "After adding (0, 9.2), p2 " << p2 << endl;

  cout << "Testing Polygon::operator-=()" << endl; 
  p2-=1;
  cout << "After removing the point (index=1), p2 " << p2 << endl;
    
  vector< Point<double> > pts2;
  pts2.push_back(Point<double>(6.2, 5.9)); 
  pts2.push_back(Point<double>(6.2, 9.2)); 
  pts2.push_back(Point<double>(10, 9.2)); 
  pts2.push_back(Point<double>(10, 5.9)); 
  pts2.push_back(Point<double>(1, 3.5)); 
  cout << "~~~ Testing the Rectangle Class ~~~" << endl;  
  cout << "Testing the convert constructor:" << endl;
  Rectangle<double> r1(pts2);
  cout << "Testing the output operator:" << endl;
  cout << "r1 " << r1 << endl;
  cout << "Testing the copy constructor:" << endl;
  Polygon<double>* r2 = new Rectangle<double>(r1);
  cout << "r2 " << *r2 << endl;
  cout << "Testing the input operator:" << endl;
  cout << "Input the data (format: color filled x1 y1 x2 y2 x3 y3 x4 y4; e.g. blue 0 2 0 2 4 6 4 6 0):";

  cin >> *r2;
  cout << "r2 " << *r2 << endl;

  cout << "Testing operator==()" << endl; 
  if (r1 == *r2)
    cout << "r1 is equal to r2" << endl;
  else
    cout << "r1 is not equal to r2" << endl;

  cout << "============== Testing all print() ============" << endl;
  Shape<double>* shapes[3];
  shapes[0] = &c2;
  shapes[1] = &p1;
  shapes[2] = r2;

  for (int i=0; i<3; i++)
    cout << *(shapes[i]);

  return 0;
}
