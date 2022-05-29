// Fig. 11.9: String.h
// String class definition with operator overloading.
#ifndef STRING_H
#define STRING_H

#include <iostream>
using std::ostream;
using std::istream;

class String
{
  friend ostream &operator<<( ostream &, const String & ); // global I/O functions
  friend istream &operator>>( istream &, String & );
public:
  String( const char * = "" ); // conversion/default constructor
  String( const String & ); // copy constructor
  ~String(); // destructor

  const String &operator=( const String & ); // assignment operator: s1 = s2 = s3;
  const String &operator+=( const String & ); // concatenation operator: s1 += s2 += s3;

  bool operator!() const;                  // is String empty?
  bool operator==( const String & ) const; // test s1 == s2
  bool operator<( const String & ) const;  // test s1 < s2

  // test s1 != s2
  bool operator!=( const String &right ) const
   { 
     return !( *this == right ); 
   } // end function operator!=

   // test s1 > s2
  bool operator>( const String &right ) const
   { 
     return right < *this;  // use the implemented < operator
   } // end function operator>
  
   // test s1 <= s2
  bool operator<=( const String &right ) const
   { 
     return !( right < *this );  // use the implemented < operator
   } // end function operator <=

   // test s1 >= s2
   bool operator>=( const String &right ) const
   { 
      return !( *this < right ); // use the implemented < operator
   } // end function operator>=

   char &operator[]( int );      // subscript operator (modifiable lvalue)
   char operator[]( int ) const; // subscript operator (rvalue)

// return a substring.  
// s(4, 5) returns the substring including and from s[4] for 5 characters
// s(4) returns the right part of the string
   String operator()( int, int = 0 ) const; 

   int getLength() const; // return string length
private:
   int length; // string length (not counting null terminator)
   char *sPtr; // pointer to start of pointer-based string

   void setString( const char * ); // utility function
}; // end class String

#endif

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
