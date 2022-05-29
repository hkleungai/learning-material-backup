/*--------------------------------------------------------------------------
   Convert infix expressions to postfix.
 
   Input:  An infix expression and user responses
   Output: The postfix expression
--------------------------------------------------------------------------*/

#include <iostream>         // <<, >>, cout, cin
#include <string>           // string, ==, find, npos
#include <cassert>          // assert()
#include <cctype>           // alnum()

using namespace std;

#include "Stack.h"         // Stack class with StackElement = char

string postfix(string exp); // prototype of postfix() function

int main()
{
  string infixExp;         // infix expression
  cout << "NOTE: Enter # for infix expression to stop.\n";
  for (;;) {
    cout << "\nInfix expression? ";
    getline(cin, infixExp);

    if (infixExp == "#")
      break;
    
    cout << "Postfix expression is " << postfix(infixExp) << endl;
  }
}

string postfix(string exp)
/*-------------------------------------------------------------------------
   Function to convert an infix expression exp to postfix.

   Precondition:  None
   Postcondition: Postfix expression corresponding to exp is returned
       or an error message displayed if exp is not well-formed.
-------------------------------------------------------------------------*/
{
  char token,                // character in exp
    topToken;                // token on top of opStack
  Stack opStack;             // stack of operators
  string postfixExp;         // converted postfix expression
  const string BLANK = " ";
  
  for (int i = 0; i < exp.length(); i++)
    {
      token = exp[i];  // get the ith character
      switch(token)
	{
	case ' ' : break;       // do nothing -- skip blanks
	case '(' : opStack.push(token); // always push '('
	  break;
	case ')' :
	  for (;;) { // keep popping till '('
	    assert (!opStack.empty());  // exit if stack is empty
	    topToken = opStack.top(); 
	    opStack.pop();
	    if (topToken == '(')
	      break;  // break out from the forever loop
	    postfixExp.append(BLANK + topToken); //add the token into postfix
	  }
	  break;
	case '+' : case '-' :
	case '*' : case '/': case'%':
	  for (;;) {
	    if (opStack.empty() ||
		opStack.top() == '(' ||
		((token == '*' || token == '/' || token == '%') &&
		 (opStack.top() == '+' || opStack.top() == '-')))
	      { // directly push into the stack
		opStack.push(token);
		break;
	      }
	    else
	      { //pop the top character from the stack 
		topToken = opStack.top();
		opStack.pop();  
		postfixExp.append(BLANK + topToken);
	      }
	  }
	  break;
	default :  // operand, which maybe like A3B (multi-character)
	  postfixExp.append(BLANK + token);
	  for(;;) // get the remainder of the name of the operand 
	    {
	      if ( !isalnum(exp[i+1]) )
		break; // end of identifier
	      i++;  //get the full operand name
	      token = exp[i];
	      postfixExp.append(1, token); // append token 1 time at the end of the string
	    }
	}
    }

  // end of expression
  // Pop remaining operators on the stack
  for (;;)
    {
      if (opStack.empty()) break;
      topToken = opStack.top();
      opStack.pop();
      if (topToken != '(')
	{
	  postfixExp.append(BLANK + topToken);
	}
      else
	{ // topToken is '(' -- parenthesis mismatch
	  cout << " *** Error in infix expression ***\n";
	  break;
	}
    }
  return postfixExp;
}
