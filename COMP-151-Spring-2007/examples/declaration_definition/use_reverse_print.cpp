/* use_reverse_print.cpp */ 

#include <iostream> 

using namespace std;

extern int global_var;		  // external variable declaration 
extern void reverse_print(const char* s); // external function declaration 

int main(int argc, const char* argv[]) 
{ 
  float local_var;			  // local variable definition 
  local_var = 987.654; 

  cout << "global var = " << global_var << endl; 
  cout << "local var = " << local_var << endl; 
  cout << "input string backwards = "; 
  reverse_print(argv[1]); 
} 
