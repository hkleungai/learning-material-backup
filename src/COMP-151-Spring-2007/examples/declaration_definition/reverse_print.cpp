/* reverse_print.cpp */ 

#include <iostream> 
#include <string> 

using namespace std;

int global_var = 23; 		// global variable definition 

void reverse_print(const char* s) 	// function definition 
{ 
  for (int j = strlen(s) - 1; j >= 0; --j) {
    cout << s[j];
  }
  cout << endl; 
} 
