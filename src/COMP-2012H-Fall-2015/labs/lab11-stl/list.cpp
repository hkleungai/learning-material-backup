#include <list>
#include <iostream>

using namespace std;

typedef list < int > LISTINT;

int main () {
	int rgTest1[] = {5, 6, 7};
	int rgTest2[] = {10, 11, 12};

	LISTINT listInt;
	LISTINT listAnother;
	LISTINT::iterator i;

	// Insert one at a time
	listInt.insert (listInt.begin (), 2);
	listInt.insert (listInt.begin (), 1);
	listInt.insert (listInt.end (), 3);

	// 1 2 3
	for (i = listInt.begin (); i != listInt.end (); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	// Insert 3 fours
	listInt.insert (listInt.end (), 3, 4);

	// 1 2 3 4 4 4
	for (i = listInt.begin (); i != listInt.end (); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	// Insert an array in there
	listInt.insert (listInt.end (), rgTest1, rgTest1 + 3);

	// 1 2 3 4 4 4 5 6 7
	for (i = listInt.begin (); i != listInt.end (); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	// Insert another LISTINT
	listAnother.insert (listAnother.begin (), rgTest2, rgTest2 + 3);
	listInt.insert (listInt.end (), listAnother.begin (), listAnother.end ());

	// 1 2 3 4 4 4 5 6 7 10 11 12
	for (i = listInt.begin (); i != listInt.end (); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	return 0;
}

/*
   Program Output is:

   1 2 3
   1 2 3 4 4 4
   1 2 3 4 4 4 5 6 7
   1 2 3 4 4 4 5 6 7 10 11 12
 */
