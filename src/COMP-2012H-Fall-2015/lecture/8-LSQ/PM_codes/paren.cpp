// match parentheses

#include <iostream>
#include <string>
#include <stdio.h>
#include "stack.h"

const int MaxLength = 100; // max expression length

void PrintMatchedPairs(char *expr)
{// Parenthesis matching.
  Stack<int> s(MaxLength);  // a stack of integer holding the position of left parenthesis (ranging from 1 onwards)
  int j, length = strlen(expr);  //strlen excludes the '\0'

  // scan expression expr for ( and )
  for (int i = 1; i <= length; i++) {
    if (expr[i - 1] == '(')
      s.Add(i);  // push the position of ( into stack
    else if (expr[i - 1] == ')')
      try { //catch exception thrown by s.Delete(), if any
	s.Delete(j);  // throw exception if popping from an empty stack
	cout << j << ' ' << i << endl; // matched pair of parentheses
      } 
      catch (OutOfBounds){ // processing the exception 
	cout << "No match for right parenthesis"
	     << " at " << i << endl;
      }
  }

  // remaining ( in stack are unmatched
  while (!s.IsEmpty()) {  
    s.Delete(j); // popping the unmatched left parentheses
    cout << "No match for left parenthesis at "
	 << j << endl;}
}

int main(void)
{
  char expr[MaxLength];
  cout << "Type an expression of length at most "
       << MaxLength << endl;
  cin.getline(expr, MaxLength);
  cout <<"The pairs of matching parentheses in" << endl;
  puts(expr);  // print the expression
  cout <<"are" << endl;
  
  PrintMatchedPairs(expr);
   
  return 0;
}
