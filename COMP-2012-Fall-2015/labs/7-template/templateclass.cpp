#include<iostream>
using namespace std;

template <class T, int N>
class Stack {
public:
  Stack() { top = -1; }
  virtual ~Stack(){ }

  inline void Push(T var);
  T Pop(){
    cout << "Popping " << st[top] << " from ";
    cout << "top = " << top << endl << flush;
    return st[top--];
  }

protected:
  T st[N];
  int top;
};

//Definition of a function external to the class
template <class T, int N>
void Stack<T, N>::Push(T var){
  cout << "Pushing " << var << " at ";
  cout << "top = " << top+1 << endl << flush;
  st[++top] = var;
}

int main() {
  Stack<float, 3> floatStack;
  floatStack.Push(10.0);
  floatStack.Push(20.0);
  floatStack.Push(40.0);
  floatStack.Pop();
  floatStack.Pop();
  floatStack.Pop();
  return 0;
}
