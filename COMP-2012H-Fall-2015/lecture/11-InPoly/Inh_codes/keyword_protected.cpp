// keyword_protected.cpp

#include <iostream>

using namespace std;
class X {
public:
  void setProtMemb( int i ) { m_protMemb = i; }
  void Display() { cout << m_protMemb << endl; }
protected:
  int  m_protMemb;
  void Protfunc() { cout << "\nAccess allowed\n"; }
} x;

class Y : public X {
public:
  void useProtfunc() { Protfunc(); }
} y;

int main() {
  // x.m_protMemb;         error, m_protMemb is protected
  x.setProtMemb( 0 );   // OK, uses public access function
  x.Display();          // cout 0
  y.setProtMemb( 5 );   // OK, uses public access function
  y.Display();          // cout 5
  // x.Protfunc();         error, Protfunc() is protected
  y.useProtfunc();      // OK, uses public access function
                        // in derived class
                        // cout Access allowed
}
