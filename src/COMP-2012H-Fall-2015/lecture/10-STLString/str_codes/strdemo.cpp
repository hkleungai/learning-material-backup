#include <iostream>
#include <string>

using namespace std;

int main(){

  // constructors
  string s0;			 // default constructor
  string s1 = "COMP104H";	 // assignment
  string s2 ("Programming");	// constructor
  string s3 (20, '$');		// another constructor
  string s4 (s3);	       	// copy constructor

  // empty
  if(s0.empty()){		// check if s0 has an empty string
    cout << "s0 is empty!" << endl;
  }
  else{
    cout << "s0 is NOT empty!" << endl;
   }
  cout << "s0.length() : " << s0.length() << endl;  // returns the length of the string

  // data, c_str
  const char* cptr1 = s1.c_str();		    // returns the pointer to where the string stores
  const char* cptr2 = s1.data();		    // same as above
  cout << "s1.c_str() : " << cptr1 << endl;
  cout << "s1.data() : " << cptr2 << endl;
  cout << "pointer values: s1.c_str() = " << (void *) cptr1 << endl; // (void *) is needed to print out the address;
  cout << "pointer values: s1.data() = " << (void *)cptr2 << endl;   // otherwise, the string will be printed
  if(cptr1 == cptr2){
    cout << "Both c_str() and data() point to the same address!" << endl;
  }

  // size, resize, length, capacity, max_size, reserve
  cout << "s1.size() : " << s1.size() << endl;	       // returns the length of the string
  cout << "s1.length() : " << s1.length() << endl;	// size() == length() in the implementation
  s1.resize(10, '*');	// change the size of the string, and fill with the character if the size is bigger than before
  cout << "s1.size() after s1.resize(10,'*') : " << s1.size() << endl;
  cout << "s1 = " << s1 << endl;
  cout << "s1.capacity() : " << s1.capacity() << endl;	// returns the memory space reserved for storing the string
  
  int numReserve = 200;
  s1.reserve(numReserve);		// changes the amount of space reserved for storing the string
  cout << "s1.capacity() after s1.reserve(" << numReserve << ") : " << s1.capacity() << endl;
  cout << "s1.max_size() : " << s1.max_size() << endl;	// returns the max. size of a string

  // assign, =
  s0 = "Methodology";
  cout << "s0 = " << s0 << endl;
  cout << "s1 = " << s1 << endl;
  s1.assign(s0, 0, 6);	// assigns to s1 part of s0, starts at 0 with length 6
  cout << "After s1.assign(s0,0,6), s1 = " << s1 << endl;

  // append, +=, +
  s1.append(s0, 6, 4);	// append to s1 part of s0, starts at 6 with length 4
  cout << "After s1.append(s0,6,4), s1 = " << s1 << endl;
  cout << "s2 = " << s2 << endl;
  cout << "s2 + s1 = " << s2 + s1 << endl;		// concatenate
  s1 += s2;				// concatenate and then assign
  cout << "After s1+=s2, s1 = " << s1 << endl;

  // compare, ==
  // s.compare(t) returns 1 if s>t; 0 if s==t; -1 if s<t
  s1 = "ABC";
  s2 = "abc";
  cout << "s1 = " << s1 << " s2 = " << s2 << endl;
  cout << "s1.compare(s2) : " << s1.compare(s2) << endl;
  s1 = "ABC";
  s2 = "ABC";
  cout << "s1 = " << s1 << " s2 = " << s2 << endl;
  cout << "s1.compare(s2) : " << s1.compare(s2) << endl;
  if(s1 == s2){
    cout << "s1 == s2 is true!" << endl;
  }

  s1 = "ABC";
  s2 = "ABCD";
  cout << "s1 = " << s1 << " s2 = " << s2 << endl;
  cout << "s1.compare(s2) : " << s1.compare(s2) << endl;
  s1 = "ABC";
  s2 = "ABB";
  cout << "s1 = " << s1 << " s2 = " << s2 << endl;
  cout << "s1.compare(s2) : " << s1.compare(s2) << endl;

  // swap the content of two strings
  s1 = "ABC";
  s2 = "DEF";
  cout << "s1 = " << s1 << " s2 = " << s2 << endl;
  s1.swap(s2);
  cout << "After s1.swap(s2), s1 = " << s1 << " s2 = " << s2 << endl;

  // at, [] -- character accessors
  s0 = "Programming and Methodology";
  cout << "s0 = " << s0 << endl;
  cout << "Characters at position 3,5,4,26: " << s0.at(3) << s0.at(5) << s0[4] << s0[26] << endl;

  // insert, erase, replace, substr, copy
  s0.insert(7, "COMP104H");		// insert "COMP104H" into s0 at position 7
  cout << "After s0.insert(7,\"COMP104H\"), s0 = " << s0 << endl;

  s0.erase(7,4); // erase from s0 start at position 7 with length 4 characters
  cout << "After s0.erase(7,4), s0 = " << s0 << endl;

  s0.replace(7,3, "171H");				// replace 3 char. start at pos. 7 in s0 with "171H"
  cout << "After s0.replace(7,3,\"171H\"), s0 = " << s0 << endl;

  cout << "s0.substr(3) : " << s0.substr(3) << endl;		// returns the substring starts at 3 to the end of the string
  cout << "s0.substr(3,7) : " << s0.substr(3,7) << endl;	// returns the substring from position 3 to 7

  s1 = "ABCDEFGHIJ";
  char s[10] = "12345678";
  cout << "s1 = " << s1 << " s = " << s << endl;
  s1.copy(s, 3, 5);		// copy a substring in s1 from position 3 to 5, to the char* s
  cout << "After s1.copy(s, 3, 5), s1 = " << s1 << " s = " << s << endl;

  // find, rfind, find_first_of, find_last_of, find_first_not_of, find_last_not_of
  s1 = "COMP104H - Programming and Programming";
  cout << "s1 = " << s1 << endl;

  cout << "s1.find(\"gram\") : " << s1.find("gram") << endl;			// find "gram"
  cout << "s1.rfind(\"gram\") : " << s1.rfind("gram") << endl;			// find "gram start from the end
  cout << "s1.find_first_of(\"m\") : " << s1.find_first_of("m") << endl;	// find 1st occurrence of "m"
  cout << "s1.find_last_of(\"m\") : " << s1.find_last_of("m") << endl;	// find last occurrence of "m"
  cout << "s1.find_first_not_of(\"ing\") : " << s1.find_first_not_of("ing") << endl;	// find 1st position not equals to "ing"
  cout << "s1.find_last_not_of(\"ing\") : " << s1.find_last_not_of("ing") << endl;	// find last position not equals to "ing"

  return 0;
}
