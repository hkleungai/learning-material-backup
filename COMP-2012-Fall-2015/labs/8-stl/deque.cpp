#include <iostream>
#include <deque>

using namespace std;

typedef deque < int > INTDEQUE;
void printcontents (INTDEQUE deque);

int main () {
	INTDEQUE dequetest;

	dequetest.push_back (1);
	dequetest.push_back (2);
	dequetest.push_back (3);

	printcontents (dequetest);

	dequetest.pop_back ();

	printcontents (dequetest);

	dequetest.pop_back ();

	printcontents (dequetest);

	return 0;
}

//function to print the contents of deque
void printcontents (INTDEQUE deque) {
	INTDEQUE::iterator pdeque;

	cout << "The output is:" << endl;

	for (pdeque = deque.begin (); pdeque != deque.end (); pdeque++) {
		cout << *pdeque << endl;
	}
}
