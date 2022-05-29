#include <iostream>
#include <map>
// map and multimap are also included in the <map> library
#include <string>

using namespace std;

class Dummy {
public:
	Dummy ()	{
		_string = "";
	}
	void Set (string s) {
		_string = s;
	}
	string Get () {
		return _string;
	}
private:
		string _string;
};

typedef Dummy *DummyPtr;

int main () {
	cout << "*** Map ***" << endl;
	map < string, DummyPtr, less < string > > occu;

	DummyPtr d1 = new Dummy ();
	DummyPtr d2 = new Dummy ();
	DummyPtr d3 = new Dummy ();
	d1->Set ("111");
	d2->Set ("222");
	d3->Set ("333");

	occu["One"] = d1;
	cout << "One: " << occu["One"]->Get () << endl;

	occu["One"] = d2;
	cout << "One: " << occu["One"]->Get () << endl;

	occu["Two"] = d3;
	cout << "Two: " << occu["Two"]->Get () << endl;

	map < string, DummyPtr, less < string > >::const_iterator it;
	pair < string, DummyPtr > curPair;

	for (it = occu.begin (); it != occu.end (); ++it) {
	  curPair = *it;
	  cout << curPair.first << " , " << curPair.second->Get () << endl;
	}

	if (it == occu.end ()) {
		cout << "END!" << endl;
	}


	cout << "*** multi-map ***" << endl;
	typedef multimap < int, int, less < int > > mmap;
	typedef multimap < int, int, less < int > >::value_type mmapvalue;
	typedef multimap < int, int, less < int > >::const_iterator mmapit;
	pair < int, int >intPair;

	mmap M;

	M.insert (mmapvalue (1, 6));
	M.insert (mmapvalue (1, 2));
	M.insert (mmapvalue (1, 8));
	M.insert (mmapvalue (1, 6));
	M.insert (mmapvalue (2, 6));
	M.insert (mmapvalue (2, 9));

	mmapit Mit;

	for (Mit = M.begin (); Mit != M.end (); ++Mit) {
		intPair = *Mit;
		cout << intPair.first << " , " << intPair.second << endl;
	}

	delete d1;
	delete d2;
	delete d3;
	return 0;
	}
