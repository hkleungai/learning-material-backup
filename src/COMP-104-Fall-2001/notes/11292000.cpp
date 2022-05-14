// the program:
//---------------------------------------------------------------------------------
#include <iostream.h>

class foo {
  private: int *x;
  public : foo() { x = new int; *x = -1; } 
           // your copy constructor -- default is overriden
           foo (const foo &a) { x = new int; *x = a.get(); }   // <- (1)
           // your destructor -- default is overriden
	   ~foo () { *x = 9999; delete x; x = NULL; }
	   void set (int inx) { *x = inx; }                    // <- (2)
	   int get() const { return *x; }
           void display(const char *str) const { 
             cout << str << ": ";
             if (*x==9999) cout << "undefined" << endl; 
             else cout << *x << endl;
           }
};

// void func (foo g)             // pass by value
void func (foo &g)         // pass by reference
// void func (const foo &g)   // use & and const modifier to simulate passing by value
{
  g.set(2); 
  g.display("func");
}

int main()
{
  foo f;
  f.set(1);
  f.display("main");
  func(f);
  f.display("main");
  return 0;
}
/* 8 cases
-----------------------------------------------------------------------------------
parameter your copy constructor  your destructor  output  	    remark
========= =====================  ===============  ======  	    ======
value		yes			yes 	  main:1  	    okay 
						  func:2  
						  main:1   

value		no (default)		yes	  main:1	    dangling pointer
						  func:2	    (figure 1)              
						  main:undefined                 
						  (or a strange                         
                                                  number is printed                  
                                                  before the 
                                                  program crashes)

value		yes			no 	  main:1	    okay, but memory
					(default) func:2	    leak: f.x in func()
						  main:1	    may not be deleted
								    properly (figure 2)

value		no			no	  main:1	    you are like doing
		(default)		(default) func:2 	    pass by reference.
						  main:2
------------------------------------------------------------------------------------------------
1. In passing by value, copy constructor and destructor are called, regardless of
   whether they are default or customized. 
2. Note that memory leak does not have immediate run time error.  
3. However, accessing dangling pointer crashes on VC. On other compiler, like 
   g++ on Unix, the value is undefined (or whatever left behind). 
------------------------------------------------------------------------------------------------
reference	yes/no			yes/no	  main:1	  copy constructor
						  func:2	  and destructor
						  func:2	  are not called 	
								  when in passing
 								  parameters by reference
								  (only memory locations
								   are copied)
*/
