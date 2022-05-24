// derive.cpp
// derived classes
#include <iostream>
using namespace std;

class CPolygon {
private:
  int num_of_edge;
protected:
  int width, height;
public:
  void set_values(int a, int b) {
    width=a;
    height=b;
  };
};

class CRectangle: public CPolygon {
public:
  int area (void) {
    return (width * height);
  };
};

class CTriangle: public CPolygon {
public:
  int area (void) {
    return (width * height / 2);
  };
};
  
class CSquare : public CRectangle {
public:
  void set_values(int a) {
    width = a;
    height = a;
  };
};

int main () {
  CRectangle rect;
  CTriangle trgl;
  CSquare square;

  rect.set_values (4,5);
  trgl.set_values (4,5);
  square.set_values (3); 

  cout << rect.area() << endl;
  cout << trgl.area() << endl;
  cout << square.area() << endl;

  return 0;
};
