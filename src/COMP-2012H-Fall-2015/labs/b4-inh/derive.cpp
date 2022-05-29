#include <iostream>
using namespace std;

class Polygon {
public:
	void set_values (int w, int h) {
		width = w;
		height = h;
	};
protected:
	int width, height;
private:
	int num_of_edge;
};

class Rectangle: public Polygon {
public:
	int area (void) {
		return width * height;
	};
};

class Triangle: public Polygon {
public:
	int area (void)	{
		return width * height / 2;
	};
};

class Square {
public:
	void set_values (int w) {
		s.set_values (w, w);
	};
	
	int area (void)	{
		return (s.width * s.height);
		// return s.area();
	};

private:
	Polygon s;
	// Rectangle s;
};

int main () {
	Rectangle rect;
	Triangle trgl;
	Square square;
	
	rect.set_values (4, 5);
	trgl.set_values (4, 5);
	square.set_values (3);
	
	cout << rect.area () << endl;
	cout << trgl.area () << endl;
	cout << square.area () << endl;
	
	return 0;
};