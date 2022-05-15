// modified by dekai from C03:YourPets2.cpp
#include <iostream>
using namespace std;

int dog, cat, bird, fish;

class c
{
public:
  c(int i) {
    age = -1;
    id = i;
  }
  void f() {
    cout << "pet id number: " << id << endl;
  }
public: // should normally be private!
  int age;
  int id;
};

int main() {
  c i(1);
  c j(2);
  c k(3);
  // cout << "c::f(): " << (unsigned long)&c::f << endl; // can't do this
  cout << "dog: " << (unsigned long)&dog << endl;
  cout << "cat: " << (unsigned long)&cat << endl;
  cout << "bird: " << (unsigned long)&bird << endl;
  cout << "fish: " << (unsigned long)&fish << endl;
  cout << "i: " << (unsigned long)&i << endl;
  cout << "j: " << (unsigned long)&j << endl;
  cout << "k: " << (unsigned long)&k << endl;
  // cout << "i.f(): " << (unsigned long)&i.f << endl; // can't do this
  cout << "i.age: " << (unsigned long)&i.age << endl;
  cout << "i.id: " << (unsigned long)&i.id << endl;
  // cout << "j.f(): " << (unsigned long)&j.f << endl; // can't do this
  cout << "j.age: " << (unsigned long)&j.age << endl;
  cout << "j.id: " << (unsigned long)&j.id << endl;
  // cout << "k.f(): " << (unsigned long)&k.f << endl; // can't do this
  cout << "k.age: " << (unsigned long)&k.age << endl;
  cout << "k.id: " << (unsigned long)&k.id << endl;
}
