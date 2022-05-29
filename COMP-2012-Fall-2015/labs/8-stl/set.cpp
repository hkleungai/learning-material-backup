#include <iostream>
#include <set>
#include <string>

using namespace std;

typedef set < string > SET;
//typedef multiset<string> SET;

int main () {
	SET myset;
	SET::const_iterator it;

	myset.insert ("Networking");
	myset.insert ("Networking");
	myset.insert ("Database");
	myset.insert ("Algorithm");

	it = myset.find ("Networking");
	if ( it == myset.end () ) {
		cout << "NOT FOUND" << endl;
	}
	else {
		cout << *it << " FOUND!" << endl;
	}

	it = myset.find ("Graphics");
	if ( it == myset.end () ) {
		cout << "NOT FOUND" << endl;
	}
	else {
		cout << *it << " FOUND!" << endl;
	}

	cout << "Count: " << myset.size () << endl;
	cout << "Count(Networking): " << myset.count ("Networking") << endl;
	cout << "Count(Algorithm): " << myset.count ("Algorithm") << endl;
	cout << "Count(Graphics): " << myset.count ("Graphics") << endl;

	return 0;
}
