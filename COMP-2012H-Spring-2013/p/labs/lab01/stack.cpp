#include <iostream.h>

class stack
{
 public:
        stack();
	~stack();
	int empty ();
	void push(int );
	int pop();

 private:
	struct node
	{
  		int item;
  		node *next;
	};
	node *top, *bottom;

};

stack::stack()
{
  bottom = new node;
  bottom->next = NULL;
  top = bottom;
}


stack::~stack()
{
  node *ptr;

  while (bottom != NULL)
  {
    ptr = bottom;
    bottom = bottom->next;
    delete ptr;
  }
}

int stack::empty()
{
  if (top == bottom)
	return 1;
  else
	return 0;
}


void stack::push(int elem)
{
  node *ptr;

  ptr = top;
  top = new node;
  top->item = elem;
  top->next = NULL;
  ptr->next = top;
}


int stack::pop()
{
  int value;
  node *ptr;

  if (top == bottom)
  {
	cerr << "Stack empty" << endl;
	return -999;
  }
  else
  {
     ptr = bottom;
     while (ptr->next != top)
     	ptr = ptr->next;
     value = top->item;
     delete top;
     top = ptr;
     top->next = NULL;
     return value;
  }
}


void main()
{
  stack s;

  s.push(1);
  cout << s.pop() << endl;
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  s.push(6);
  s.push(7);
  s.push(8);
  s.push(9);
  s.push(10);
  s.push(20);
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  
  /* ToDo:
   *  Implement a class method
   * that computes the summation of the numbers in the stack
   * or print "Stack Empty" for empty stack
   * without changing the number of items, value of the items in the stack
   */
  //cout << "The sum of the numbers in the stack is:" << endl;
  //cout << "=======================" << endl;
  //s.sum();
  //cout << "=======================" << endl;

}

