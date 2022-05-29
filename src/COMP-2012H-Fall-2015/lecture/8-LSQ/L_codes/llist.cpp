// test formula based linear list class

#include <iostream>
#include "llist.h"
#include "xcept.h"

int main(void)
{
  try {
    LinearList<int> L(5);
    cout << "Length = " << L.Length() << endl;
    cout << "IsEmpty = " << L.IsEmpty() << endl;
    L.Insert(0,2).Insert(1,6);
    cout << "List is " << L << endl;
    cout << "IsEmpty = " << L.IsEmpty() << endl;
    int z;
    L.Find(1,z);
    cout << "First element is " << z << endl;
    cout << "Length = " << L.Length() << endl;
    L.Delete(1,z);
    cout << "Deleted element is " << z << endl;
    cout << "List is " << L << endl;
  }
  catch (...) {
    cerr << "An exception has occurred" << endl;
  }
  return 0;
}
