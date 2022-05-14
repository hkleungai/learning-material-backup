//--------------------------------------------------
// rational.cpp
#include <iostream>
using namespace std;

//--------------------------------------------------

class Rational{
	public:
			// default-value constructor
		Rational();
			// explicit-value constructor
		Rational(int numer, int denom = 1);
			// arithmetic functions
		Rational Add(const Rational r) const;
		Rational Subtract(const Rational r) const;
		Rational Multiply(const Rational r) const;
		Rational Divide(const Rational r) const;
			// relational functions
		bool Equal(const Rational r) const;
		bool LessThan(const Rational r) const;
			// i/o functions
		void Display() const;
		void Get();
	private:	// data members
		int Numerator;
		int Denominator;
};

//--------------------------------------------------

// default-value constructor
Rational::Rational(){         
	Numerator = 0;
	Denominator = 1;
}

// explicit-value constructor
Rational::Rational(int numer, int denom){
	Numerator = numer; 
	Denominator = denom;
	if(Denominator == 0){
		cout << "Illegal denominator of zero, "
		     << "using 1 instead" << endl;
		Denominator = 1;
	}
}

Rational Rational::Add(const Rational r) const{
	int a = Numerator;
	int b = Denominator;
	int c = r.Numerator;
	int d = r.Denominator;
	Rational result(a*d + b*c, b*d);
	return result;
}

Rational Rational::Subtract(const Rational r) const{
	int a = Numerator;
	int b = Denominator;
	int c = r.Numerator;
	int d = r.Denominator;
	Rational result(a*d - b*c, b*d);
	return result;
}

Rational Rational::Multiply(const Rational r) const{
	int a = Numerator;
	int b = Denominator;
	int c = r.Numerator;
	int d = r.Denominator;
	Rational result(a*c, b*d);
	return result;
}

Rational Rational::Divide(const Rational r) const{
	int a = Numerator;
	int b = Denominator;
	int c = r.Numerator;
	if(c == 0){
		cout << "Illegal denominator of zero, "
		     << "using 1 instead" << endl;
		c = 1;
	}
	int d = r.Denominator;
	Rational result(a*d, b*c);
	return result;
}

bool Rational::Equal(const Rational r) const{
	double a, b;
	a = double(Numerator)/Denominator;
	b = double(r.Numerator)/r.Denominator;
	if(a == b)
		return true;
	else
		return false;
}

bool Rational::LessThan(const Rational r) const{
	double a, b;
	a = double(Numerator)/Denominator;
	b = double(r.Numerator)/r.Denominator;
	if(a < b)
		return true;
	else
		return false;
}

void Rational::Display() const{
	cout << Numerator << '/' << Denominator;
}

void Rational::Get(){
	char slash;
	cin >> Numerator >> slash >> Denominator;
	if(Denominator == 0){
		cout << "Illegal denominator of zero, "
		     << "using 1 instead" << endl;
		Denominator = 1;
	}
}


//--------------------------------------------------

void main(){
	Rational r;
	Rational s;

	cout << "Enter two rationals(a/b): ";
	r.Get(); 
	s.Get();
	Rational t(r);	// copies r to t

	Rational sum = r.Add(s);
	r.Display();
	cout << " + ";
	s.Display();
	cout << " = ";
	sum.Display();	
	cout << endl;

	Rational diff = r.Subtract(s);
	r.Display();
	cout << " - ";
	s.Display();
	cout << " = ";
	diff.Display();	
	cout << endl;

	Rational product = r.Multiply(s);
	r.Display();
	cout << " * ";
	s.Display();
	cout << " = ";
	product.Display();	
	cout << endl;

	Rational div = r.Divide(s);
	r.Display();
	cout << " / ";
	s.Display();
	cout << " = ";
	div.Display();	
	cout << endl;

	if(r.Equal(s))
		cout << "They are the same!" << endl;
	if(r.LessThan(s))
		cout << "The first is less than the second!" << endl;

} 
