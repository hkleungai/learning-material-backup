// Fig. 18.9: Fig18_09.cpp
// Converting to C-style strings.
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
  string string1( "STRINGS" ); // string constructor with char* arg
  int length = string1.length();
  const char *ptr1 = 0;        // initialize *ptr1

  cout << "string string1 is " << string1
       << "\nstring1 converted to a C-Style string is "
       << string1.c_str();

  // Assign to pointer ptr1 the const char * returned by
  // function data().
  // NOTE: this is a potentially dangerous assignment.
  // If string1 is subsequently modified, pointer ptr1 can
  // become invalid.
  // suggestion: use strcpy or s.copy to make duplication on the string
  ptr1 = string1.data();  

  cout << "\nptr1 is ";  
  // output each character using pointer (may also use iterator)
  // Because ptr1 may not be NULL-terminated, we need to print out the
  // string using the string length, so as not to print out trailing
  // characters in the string
  for ( int i = 0; i < length; i++ )
    cout << *( ptr1 + i ); // use pointer arithmetic so as not to print garbage

  char *ptr2 = new char[ length + 1 ]; // need to include null
   
  // copy characters from string1 into allocated memory
  string1.copy( ptr2, length, 0 ); // copy string1 to ptr2 starting at 0
  ptr2[ length ] = '\0';           // add null terminator
  // another way is to replace the above 2 statements by C-style command:
  // strcpy (ptr2, string1.c_str());

  cout << "\nptr2 is " << ptr2 << endl;
  delete [] ptr2; // reclaim dynamically allocated memory

  // convert a C-style string to C++ string
  char * cptr = "ABC\0"; // cptr points to char array ABC\0 in read-only
                       //static memory segment; equivalent to
                       // const char * cptr = "ABC";
  string s = cptr;     // construct s from cptr; s gets ABC
  // cptr[ 1 ] = 'X';  // segmentation fault as "ABC" is a literal (const) string
  char cptr2[] = "DEF\0"; // same as char cptr[]={'D', 'E', 'F', '\0'};
  s = cptr2;            //copy cptr2 to s; s get DEF
  cptr2[ 1 ] = 'X';     // ok; cptr2 now points to EXF\0
  
  return 0;
} // end main

/**************************************************************************
 * (C) Copyright 1992-2008 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
