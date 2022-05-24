//IntStack.h
//Simple integer stack

#include <iostream>
#include <assert.h>
using namespace std;

class IntStack 
{
private:
  enum { ssize = 100 };
  int stack[ssize];
  int top;
public:
  IntStack() : top(0) {}
  void push(int i) 
  {
    assert(top<ssize);
    stack[top++] = i;
  }
  int pop() 
  {
    assert(top > 0);
    return stack[--top];
  }
};


