#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef map < int, string, less < int > > INT2STRING;

int main () {
	// 1. Create a map of ints to strings
	INT2STRING theMap;
	INT2STRING::iterator theIterator;
	string theString = "";

	// Fill it with the digits 0 - 9, each mapped to its string counterpart
	// Note: value_type is a pair for maps...
	theMap.insert (INT2STRING::value_type (0, "Zero"));
	theMap.insert (INT2STRING::value_type (1, "One"));
	theMap.insert (INT2STRING::value_type (2, "Two"));
	theMap.insert (INT2STRING::value_type (3, "Three"));
	theMap.insert (INT2STRING::value_type (4, "Four"));
	theMap.insert (INT2STRING::value_type (5, "Five"));
	theMap.insert (INT2STRING::value_type (6, "Six"));
	theMap.insert (INT2STRING::value_type (7, "Seven"));
	theMap.insert (INT2STRING::value_type (8, "Eight"));
	theMap.insert (INT2STRING::value_type (9, "Nine"));

	// Read a Number from the user and print it back as words
	while (true) {
	  cout << "Enter \"q\" to quit, or enter a Number: ";
	  cin >> theString;

	  if (theString == "q") { break; }
	  // extract each digit from the string, find its corresponding
	  // entry in the map (the word equivalent) and print it
	  int index = 0;
		for (index = 0; index < theString.length (); index++) {
			theIterator = theMap.find (theString[index] - '0');
			if (theIterator != theMap.end () ) {	// is 0 - 9
				cout << (*theIterator).second << " ";
			}
			else {			// some character other than 0 - 9
				cout << "[err] ";
			}
		}
		cout << endl;
	}
	return 0;
}
