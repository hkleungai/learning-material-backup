#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

using namespace std;

int main () {
	const int MAX_ELEMENTS = 8;

	// Define a template class vector of int
	typedef vector < int > IntVector;

	//Define an iterator for template class vector of ints
	typedef IntVector::iterator IntVectorIt;

	IntVector NumbersVector (MAX_ELEMENTS);

	IntVectorIt startv, endv, itv;

	// Define a template class list of int
	typedef list < int >IntList;

	//Define an iterator for template class list of ints
	typedef IntList::iterator IntListIt;

	IntList NumbersList;

	IntListIt first, last, itl;

	// Define a template class deque of int
	typedef deque < int > IntDeque;

	//Define an iterator for template class deque of ints
	typedef IntDeque::iterator IntDequeIt;

	IntDeque NumbersDeque (2 * MAX_ELEMENTS);

	IntDequeIt itd;

	// Initialize vector NumbersVector
	NumbersVector[0] = 4;
	NumbersVector[1] = 10;
	NumbersVector[2] = 70;
	NumbersVector[3] = 10;
	NumbersVector[4] = 30;
	NumbersVector[5] = 69;
	NumbersVector[6] = 96;
	NumbersVector[7] = 100;

	startv = NumbersVector.begin ();	// location of first
	// element of NumbersVector

	endv = NumbersVector.end ();	// one past the location
	// last element of NumbersVector

	// sort NumbersVector, merge requires the sequences
	// to be sorted
	sort (startv, endv);

	// print content of NumbersVector
	cout << "NumbersVector { ";
	for (itv = startv; itv != endv; itv++) {
		cout << *itv << " ";
	}
	cout << " }\n" << endl;

	// Initialize vector NumbersList
	for (int i = 0; i < MAX_ELEMENTS; i++) {
		NumbersList.push_back (i);
	}

	first = NumbersList.begin ();	// location of first
	// element of NumbersList

	last = NumbersList.end ();	// one past the location
	// last element of NumbersList

	// print content of NumbersList
	cout << "NumbersList { ";
	for (itl = first; itl != last; itl++) {
		cout << *itl << " ";
	}
	cout << " }\n" << endl;

	// merge the elements of NumbersVector
	// and NumbersList and place the
	// results in NumbersDeque
	merge (startv, endv, first, last, NumbersDeque.begin() );

	cout << "After calling merge\n" << endl;

	// print content of NumbersDeque
	cout << "NumbersDeque { ";
	for (itd = NumbersDeque.begin (); itd != NumbersDeque.end (); itd++) {
		cout << *itd << " ";
	}
	cout << " }\n" << endl;

	return 0;
}
