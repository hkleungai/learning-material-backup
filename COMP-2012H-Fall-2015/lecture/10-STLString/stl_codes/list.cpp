// Fig. 22.17: Fig22_17.cpp
// Standard library list class template test program.
#include <iostream>
#include <list>		// list class-template definition
#include <stdlib.h>
using namespace std;

// prototype for function template printList
template < typename T > void printList( const list<T> & );

int main()
{ 
  list< int > values; // create list of ints

  // insert items in values
  values.push_front( 1 );
  values.push_front( 2 );
  values.push_back( 4 );
  values.push_back( 3 );
  values.push_back( 1 );

  cout << "values contains: ";
  printList( values );

  values.sort(); // sort values
  cout << "\nvalues after sorting contains: ";
  printList( values );

  values.unique(); // remove duplicate elements
  cout << "\nAfter unique, values contains: ";
  printList( values );   

  values.remove( 4 ); // remove all 4s
  cout << "\nAfter remove( 4 ), values contains: ";
  printList( values );
  cout << endl;
  return 0;
} // end main

// printList function template definition; uses 
// iterators to output list elements
template <typename T>
void printList( const list<T> &listRef )
{
  if ( listRef.empty() ) // list is empty
    cout << "List is empty";
  else
    {
      for (typename list<T>::const_iterator it = listRef.begin();
	   it != listRef.end();
	   ++it)
	cout << *it << "  ";
      cout << endl;
    } // end else
} // end function printList

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

