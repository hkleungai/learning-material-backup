#include<iostream>
using namespace std;

class foo{
public:
  foo():value(){
    printf("%s\n","default constructor is called.");
  }

  foo(int v):value(v)	{
    printf("%s\n","constructor with integal input is called.");
  }

  // must have const keyword for copy constructor
  foo(const foo& a_foo)	{
    value=a_foo.value;
    printf("%s\n","copy constructor is called.");
  }

  const foo & operator=( const foo & f ){
    value = f.value;
    printf("%s\n","assignment is called.");
  }

private:
  int value;
};

int main(){

  foo c=foo();// ONLY default constructor is called
  // Does NOT call copy constructor or assignment

  foo d;//Default constructor is called
  d = foo(); // default constructor and assignment are called
	
  foo a(); //No syntax error, nothing is printed . A function pototype;
  foo b(void);//No syntax error, nothing is printed. A function pototype;
  int x(); // No error; function prototype
  
  return 0;
}
