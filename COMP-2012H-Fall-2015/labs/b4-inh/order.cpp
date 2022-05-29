#include <iostream>
using namespace std;

class Color {
public:
    Color() { cout << this << " Color constructor" << endl; }
    ~Color() { cout << this << " Color destructor" << endl; }
private:
    int color;
};

class Offset {
public:
    Offset() { cout << this << " Offset constructor" << endl; }
    ~Offset() { cout << this << " Offset destructor" << endl; }
private:
    int x, y;
};

class Polygon {
public:
    Polygon() {
		cout << this << " Polygon default constructor" << endl;
	}
    Polygon(int w, int h) : width(w), height(h) {
		cout << this << " Polygon(int, int) overloaded constructor" << endl;
	}
    ~Polygon() {
		cout << this << " Polygon destructor" << endl;
	}
    void set_values (int w, int h) { width = w; height =h; }
protected:
    int width, height;
private:
    int num_of_edge;
};

class Rectangle: public Polygon {
public:
    Rectangle() { cout << this << " Rectangle empty constructor" << endl; }
    ~Rectangle() { cout << this << " Rectangle destructor" << endl; }
    int area (void) { return width * height; }
private:
    Color c;
    Offset o;
};

class Triangle: public Polygon {
public:
    Triangle(int w, int h): Polygon(w, h) {
		cout << this << " Triangle overloaded constructor" << endl;
	}
    ~Triangle() {
		cout << this << " Triangle destructor" << endl;
	}
	int area (void) { return width * height / 2; }
};

const char * const DASHLINE = "----------------------------";

int main () {
	Rectangle rect;
	cout << DASHLINE << endl;
	Triangle tri(4, 5);
	cout << DASHLINE << endl;
	return 0;
}
