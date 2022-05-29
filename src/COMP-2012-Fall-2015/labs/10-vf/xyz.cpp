#include <iostream>

class X {
public:
	virtual int g() = 0;
	virtual double h() = 0;
	virtual char l() const = 0;
};

class Y: public X {
public:
	virtual int g() { cout << "In Y::g()" << endl; return 0; }
};

class Z: public Y {
public:
	virtual int g() { cout << "In Z::g()" << endl; return 1; }
	virtual double h() { cout << "In Z::h()" << endl; return 1.2; }
	virtual char l() { cout << "In Z::l()" << endl; return 'a'; }
};
   
int main() {
	Y* y = new Z();
	cout << y->g() << " " << y->h() << endl;
	return 0;
}
