#include <iostream>
using namespace std;

class Polygon {
public:
    int get_width() { return width; }
    int get_height() { return height; }
    void set_values (int w, int h) { width=w; height=h; }
protected:
    int width, height;
};


class Rectangle: public Polygon {
public:
    int area (void) { return (width * height); }
};


class Triangle: public Polygon {
public:
    int area (void) { return (width * height / 2); }
};

//Polygon object
void print_width(Polygon polygon) {
	cout << "Width = " << polygon.get_width() << endl;
}

//Polygon reference
void print_height(Polygon& polygon) {
	cout << "Height = " << polygon.get_height() << endl;
}

//Polygon pointer
void print_width_height(Polygon* polygon) {
	cout << "Width * Height = " << polygon->get_width()
		<< " * " << polygon->get_height() << endl;
}

int main () {
	Polygon poly;
	Rectangle rect;
	Triangle trgl;
	
	poly.set_values (2,3);
	rect.set_values (4,5);
	trgl.set_values (6,7);
	
	cout << "poly: ";
	print_width(poly);
	cout << "rect: ";
	print_width(rect);
	cout << "trgl: ";
	print_height(trgl);
	cout << "rect: ";
	print_width_height(&rect);
	
	return 0;
}
