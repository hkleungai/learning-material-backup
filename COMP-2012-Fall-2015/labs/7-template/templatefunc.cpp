
#include <iostream>
using namespace std;
 

// template function
template<typename T> T minimum(const T& t1, const T& t2) {
  return t1 < t2? t1: t2;
};

// main program
int main() {
   int i;
   double d;

   // instantiate template function with int
   i = minimum(10, 20);
   cout << i << endl;
   // instantiate template function with double
   d = minimum(10.0, 20.0); 
   cout << d << endl;

   // instantiate template function with int and double
   // d = minimum(4.5, 5);  // error
   // cout << d << endl;

   // instantiate template function explicitly 
   d = minimum<double>(4.5, 5);
   cout << d << endl;

   return 0;
};

