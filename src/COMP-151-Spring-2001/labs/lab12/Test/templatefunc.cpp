#include <iostream>
using namespace std;

// template function
template<typename T> T min(const T& t1, const T& t2) {
  return t1 < t2? t1: t2;
};

// A dummy class
class Dummy {
private:
  int non_sense;
public:
  Dummy(int i): non_sense(i) {};
  friend ostream& operator<<(ostream& os, const Dummy& dummy);
};

// Print function for the class Dummy
ostream& operator<<(ostream& os, const Dummy& dummy) {
  os << dummy.non_sense;
  return os;
};

// main program
int main() {
  cout << "min(10, 20) = " << min(10, 20) << endl
    << "min(1.00, 3.14) = " << min(1.00, 3.14) << endl
    << "min<double>(5, 7.50) = " << min<double>(5, 7.50) << endl;

/*
  cout << "min(Dummy(10), Dummy(20)) = "
    << min(Dummy(10), Dummy(20)) << endl;
*/
  return 0;
};

