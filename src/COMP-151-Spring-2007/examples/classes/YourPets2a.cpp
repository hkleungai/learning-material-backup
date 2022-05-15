// modified by dekai from C03:YourPets2.cpp
#include <iostream>
using namespace std;

int dog, cat, bird, fish;

void f(int i) {
  cout << "pet id number: " << i << endl;
}

int main() {
  int i, j, k;
  cout << "f(): " << (unsigned int)&f << endl;
  cout << "dog: " << (unsigned int)&dog << endl;
  cout << "cat: " << (unsigned int)&cat << endl;
  cout << "bird: " << (unsigned int)&bird << endl;
  cout << "fish: " << (unsigned int)&fish << endl;
  cout << "i: " << (unsigned int)&i << endl;
  cout << "j: " << (unsigned int)&j << endl;
  cout << "k: " << (unsigned int)&k << endl;
}
