# include <iostream>
using namespace std;

int & bar(){
  int i = 10;
  return i;  // warning from compiler:
             // reference to local variable `i' returned
}

class foo{
public:
  foo(){ cout << "constructor\n"; }
  foo( const foo & f ){ cout << "copy constructor\n"; }
};

// return the value of f
foo ret_foo(){
  foo f;
  return f;
}

// Meaningless, as returning a value can never be lvalue
const foo ret_cfoo(){
  foo f;
  return f;
}

// must be rvalue
// returning a permanent space and hence can be a reference
const foo & ret_cfoor( foo & f){
  return f;
}

//can be rvalue or lvalue
foo & ret_foor( foo & f ){
  return f;  
}

int main(){

  int j = 1;
  j = bar();
  cout << j  << endl;
  
  foo f,g;
  
  cout << "\nreturn foo\n";
  ret_foo() = f;      // No compilation error but does nothing

  cout << "\nreturn const foo\n";
  f = ret_cfoo();     // ret_cfoo() = f is error
  
  cout << "\nreturn foo & \n";
  f = ret_foor( g );  // ret_foor() = f is error

  cout << "\nreturn const foo & \n";
  f = ret_cfoor( g ); // ret_cfoor() = f is error
  
  return 0;
}
  

  
