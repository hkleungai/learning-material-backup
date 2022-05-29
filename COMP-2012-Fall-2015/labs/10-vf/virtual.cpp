#include <iostream>
using namespace std;

class Polygon {
public:
	void set_values (int w, int h) {
		width = w;
		height = h;
	};

	virtual int area(void) {
		return -1;
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

int main () {
	// an array of Polygon pointers
	const int size = 3;
	Polygon* polygons[size];

	polygons[0] = new Rectangle;
	polygons[0]->set_values (4, 5);

	polygons[1] = new Triangle;
	polygons[1]->set_values (4, 5);
	
	polygons[2] = new Polygon;
	polygons[2]->set_values(10, 10);

	for (int i = 0; i < size; ++i) {
		cout << i << ": " << polygons[i]->area() << endl;
		delete polygons[i];
	};

	return 0;
};
