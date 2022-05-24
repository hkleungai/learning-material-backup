//order.cpp
//order
#include <iostream>
using namespace std;

class Color {
  private:
    int color;
  public:
    Color() { cout << this << " color constructor\n"; }
    ~Color() { cout << this << " color destructor\n"; }
};

class Offset {
  private:
    int x, y;
  public:
    Offset() { cout << this << " offset constructor\n"; }
    ~Offset() { cout << this << " offset destructor\n"; }
  };

class CPolygon {
  private:
    int num_of_edge;
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b;}
    CPolygon()
      { cout << this 
             << " polygon default constructor\n"; }
    CPolygon(int w, int h) : width(w),height(h)
      { cout << this
             << " polygon overloaded constructor\n"; }
    ~CPolygon()
      { cout << this
             << " polygon destructor\n\n"; }
  };

class CRectangle: public CPolygon {
  private:
    Color c;
    Offset o;
  public:
    int area (void)
      { return (width * height); }
    CRectangle()
      { cout << this
             << " rectangle empty constructor\n"; }
    ~CRectangle()
      { cout << this << " rectangle destructor\n"; }
  };

class CTriangle: public CPolygon {
  public:
    int area (void)
      { return (width * height / 2); }
    CTriangle(int w, int h) : CPolygon(w, h)
      { cout << this
          << " triangle overloaded constructor\n"; }
    ~CTriangle()
      { cout << this
             << " triangle destructor\n"; }
  };

int main () {
  CRectangle rect;
  cout << endl;
  CTriangle tri(4, 5);
  cout << endl;
  return 0;
}
