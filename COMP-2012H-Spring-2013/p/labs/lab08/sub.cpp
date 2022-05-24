//substitution.h
#include <iostream>
using namespace std;

class CPolygon {
  protected:
    int width, height;
  public:
    int get_width()
      { return width; }
    int get_height()
      { return height; }
    void set_values (int a, int b)
      { width=a; height=b;}
  };

class CRectangle: public CPolygon {
  public:
    int area (void)
      { return (width * height); }
  };

class CTriangle: public CPolygon {
  public:
    int area (void)
      { return (width * height / 2); }
  };

//CPolygon object
void print_width(CPolygon polygon) {
  cout << "Width is: "
       << polygon.get_width()
       << endl;
}
//CPolygon reference
void print_height(CPolygon& polygon) {
  cout << "Height is: "
       << polygon.get_height()
       << endl;
}
//CPolygon pointer
void print_width_height(CPolygon* polygon) {
  cout << "Width*Height: "
       << polygon->get_width()
       << "*"
       << polygon->get_height()
       << endl;
}
  
int main () {
  CPolygon poly;
  CRectangle rect;
  CTriangle trgl;

  poly.set_values (2,3);
  rect.set_values (4,5);
  trgl.set_values (6,7);

  cout << "poly: ";
  print_width(poly);  //CPolygon object
  cout << "rect: ";
  print_width(rect);  //rect. is a polygon
  cout << "trgl: ";
  print_height(trgl); //call by reference
  cout << "rect: ";
  print_width_height(&rect);  //by pointer
  return 0;
}

