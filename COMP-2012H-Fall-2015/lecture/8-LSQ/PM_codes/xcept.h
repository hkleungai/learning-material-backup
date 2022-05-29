// exception classes for various error types

#ifndef Xcept_
#define Xcept_

#include <new>
using namespace std;

// bad initializers
class BadInitializers {
 public:
  BadInitializers() {
    // codes to do something for this exception are put here, e.g.,
    // cout << "Out of Bounds\n";  // print something out
  }
};

// insufficient memory
class NoMem {
 public:
  NoMem() {}
};

// change new to throw NoMem instead of xalloc
void my_new_handler()
{
  throw NoMem();
};

new_handler Old_Handler_ = set_new_handler(my_new_handler);

// improper array, find, insert, or delete index
// or deletion from empty structure
class OutOfBounds {
 public:
  OutOfBounds() {}
};

// use when operands should have matching size
class SizeMismatch {
 public:
  SizeMismatch() {}
};

// use when zero was expected
class MustBeZero {
 public:
  MustBeZero() {}
};

// use when zero was expected
class BadInput {
 public:
  BadInput() {}
};

#endif
