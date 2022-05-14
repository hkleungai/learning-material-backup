#include <iostream>
using namespace std;

class IntArray {
	public:
		// constructors
		IntArray(int size=1, int val=0);
		IntArray(const int A[], int size);
		IntArray(const IntArray &A);
		// destructor
		~IntArray();
		// inspector for size of the list
		int Size() const;
		// inspector for elements
		int getElement(int i) const;
		// mutator for elements
		void setElement(int i, int value);	
		// for adding a new element to the end of the array
		void addElement(int value);	
		// mutator to copy whole array
		void copy(const IntArray &A);
		void print() const;	// print the list
	private:
		// data members
		int *Values;      // pointer to elements
		int NumberValues; // size of list
};

IntArray::IntArray(int size, int val){
	if(size<=0){
		cout << "Bad size for array!" << endl;
		exit(0);
	}
	NumberValues = size;
	Values = new int [size];
	for(int i=0; i<size; i++)
		Values[i] = val;
}

IntArray::IntArray(const int A[], int size) {
	if(size<=0){
		cout << "Bad size for array!" << endl;
		exit(0);
	}
	NumberValues = size;
	Values = new int [size];
	for (int i=0; i<size; i++)
		Values[i] = A[i];
}

IntArray::IntArray(const IntArray &A){
	NumberValues = A.Size();
	Values = new int [A.Size()];
	if(Values==0){
		cout << "Memory allocation error for Values!" << endl;
		exit(0);
	}
	for(int i=0; i<A.Size(); i++)
		Values[i] = A.getElement(i);
}

IntArray::~IntArray() {
	delete [] Values;
}

IntArray::Size() const {
	return NumberValues;
}

int IntArray::getElement(int i) const {
	if(i<0 || i>=Size()){
		cout << "Illegal subscript!" << endl; exit(0); }
	return Values[i];
}

void IntArray::setElement(int i, int value) {
	if(i<0 || i>=Size()){
		cout << "Illegal subscript!" << endl; exit(0); }
	Values[i] = value;
}

// for adding a new element to end of array
void IntArray::addElement(int value){
	int *oldValues = Values;
	Values = new int [NumberValues+1];
	if(Values==0){
		cout << "Memory allocation error for addElement!" << endl;
		exit(0);
	}
	if(NumberValues){	// copy and delete old array
		for(int i=0; i<NumberValues; i++)
			Values[i] = oldValues[i];
		delete [] oldValues;
	}
	Values[NumberValues] = value;
	NumberValues++;
}

// mutator to copy whole array
void IntArray::copy(const IntArray &A){
	if(NumberValues)	// delete old array first
		 delete [] Values;
	NumberValues = A.Size();
	Values = new int [A.Size()];
	if(Values==0){
		cout << "Memory allocation error for Values!" << endl;
		exit(0);
	}
	for(int i=0; i<A.Size(); i++)
		Values[i] = A.getElement(i);
}

void IntArray::print() const{
	cout << "[ ";
	for(int i=0; i<NumberValues; i++)
		cout << Values[i] << " ";
	cout << "]" << endl;
}


void main(){

	IntArray A(5, 1);	// sets A to: [ 1 1 1 1 1 ]
	IntArray B(10, 2);	// sets B to array of 10 2’s
	IntArray C(5, 4);	// sets C to: [ 4 4 4 4 4 ]
	for(int i=0; i<A.Size(); i++)	// set A = C
		A.setElement(i, B.getElement(i));	
	A.print();			// [ 2 2 2 2 2 ]
	A.copy(C);
	A.print();			// [ 4 4 4 4 4 ]
	IntArray D(C);		// sets D to: [ 4 4 4 4 4 ]
	D.setElement(0, 5);
	D.addElement(6);	// add 6 to end of current array
	D.print();			// [ 5 4 4 4 4 6 ]
	IntArray E;
	E.print();			// [ 0 ]
	E.setElement(0, 1);
	E.print();			// [ 1 ]
	E.addElement(2);
	E.print();			// [ 1 2 ]
	E.addElement(3);
	E.print();			// [ 1 2 3 ]
	E.addElement(4);
	E.print();			// [ 1 2 3 4 ]
}
