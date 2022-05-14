#include <iostream>
#include <cctype>
using namespace std;


class Temperature{
	public:
		Temperature();
		Temperature(double initialDegree, char initialScale);
		double getDegree() const;
		char getScale() const;
		void set(double newDegree, char newScale);
		void read();
		void print() const;
		void printAll();
		void Fahrenheit();
		void Celsius();
		void Kelvin();
	private:
		double degree;
		char scale;
};

Temperature::Temperature(){
	degree = 0.0;
	scale = 'C';
}

Temperature::Temperature(double d, char s){
	degree = d;
	scale = toupper(s);
	if(scale!='C' && scale!='F' && scale!='K'){
		cout << "Bad Temperature scale: " << scale << endl;
		exit(1);
	}
}

double Temperature::getDegree() const {
	return degree;
}

char Temperature::getScale() const {
	return scale;
}

void Temperature::set(double d, char s){
	degree = d;
	scale = toupper(s);
	if(scale!='C' && scale!='F' && scale!='K'){
		cout << "Bad Temperature scale: " << scale << endl;
		exit(1);
	}

}

void Temperature::read(){
	cin >> degree >> scale;
	scale = toupper(scale);
	if(scale!='C' && scale!='F' && scale!='K'){
		cout << "Bad Temperature scale: " << scale << endl;
		exit(1);
	}
}

void Temperature::Fahrenheit(){
	if(scale == 'C')
		degree = degree*1.8+32.0;
	else if(scale == 'K')
		degree = (degree-273.15)*1.8 + 32.0;
	scale = 'F';
}

void Temperature::Celsius(){
	if(scale == 'F')
		degree = (degree-32.0)/1.8;
	else if(scale == 'K')
		degree = degree - 273.15;
	scale = 'C';
}

void Temperature::Kelvin(){
	if(scale == 'F')
		degree = (degree-32.0)/1.8 + 273.15;
	else if(scale == 'C')
		degree = degree + 273.15;
	scale = 'K';
}

void Temperature::print() const{
	cout << degree << " " << scale;
}

void Temperature::printAll(){
	// prints temperature in all scales
	double d = degree;	// save initial degree and scale
	char s = scale;
	cout << "-->";
	// calls member function Fahrenheit() on the same Temperature object
	Fahrenheit(); 
	// calls member function print() on the same Temperature object
	print();
	cout << " = ";
	Celsius();
	print();
	cout << " = ";
	Kelvin();
	print();
	degree = d;	// restore initial degree and scale
	scale = s;
}


void main(){
	char resp;
	Temperature temp;

	do{
		cout << "Enter temperature (e.g., 98.6 F): "; 
		temp.read();
		temp.printAll(); 	// prints temperature in F, C, K
		cout << endl << endl;
		cout << "Another temperature to convert? ";
		cin >> resp;
	}while(resp == 'y' || resp == 'Y');

	cout << "Example of other member functions: " << endl;
	Temperature t, tC;	// default value: 0 C
	t.Fahrenheit();
	Temperature tF = t;
	Temperature tK(100, 'K');
	tC.set(33, 'C');
	double d = tC.getDegree();
	char s = tC.getScale();
	t.set(d, s);

	cout << "t: ";
	t.print();
	cout << endl << "tF: ";
	tF.print(); 
	cout << endl << "tC: ";
	tC.print();
	cout << endl << "tK: ";
	tK.print();
	cout << endl;

} 


