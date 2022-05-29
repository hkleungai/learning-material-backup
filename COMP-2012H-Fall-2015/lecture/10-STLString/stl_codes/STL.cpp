#include<iostream>

#include<list>   // list STL
#include<queue>  // queue STL
#include<stack>  // stack STL

using namespace std;

int main() {
  int i;

  ////////////////////////
  ///List Demonstration///
  ////////////////////////
  
  typedef list<int> list_type;	//define a list type (a list of integer)
  list_type alist;              //define a list
  list_type::iterator list_itr;	//define an iterator
  
  cout << alist.empty() << endl;  //check is empty
  for(i=0;i<10;i++){
    //push the elements at the begin of the list
    alist.push_front(i);
  }
  for(i=10;i<20;i++){
    //push the elements at the end of the list
    alist.push_back(i);
  }
  cout << alist.empty() << endl;  //check is empty again

  //display the size of the list
  cout << alist.size() << endl;
  
  list_itr = alist.begin();  //set the iterator at
			  // the beginning of the list
  for(i=0;i<alist.size();i++){
    //display the elements one by one
    cout << *list_itr << ' ';
    list_itr++;
  }
  cout << endl;
  
  //sort the list
  alist.sort();
  list_itr = alist.begin();  //set the iterator at
			     // the beginning of the list
  for(i=0;i<alist.size();i++){
    //display the elements one by one
    cout << *list_itr << ' ';
    list_itr++;
  }
  cout << endl;
  
  //pop 4 elements from the tail of the list
  for(i=0;i<4;i++)
    alist.pop_back();
  //pop 2 elements from the head of the list
  for(i=0;i<2;i++)
    alist.pop_front();	
  list_itr = alist.begin();  //set the iterator at
			     // the beginning of the list
  for(i=0;i<alist.size();i++){
    //display the elements one by one
    cout << *list_itr << ' ';
    list_itr++;
  }
  cout << "\n\n\n";
  
  
  /////////////////////////
  ///Queue Demonstration///
  /////////////////////////
  typedef queue<double> queue_type;	//define a queue type
					// (a queue of double)
  queue_type aqueue;			//define a queue

  for(i=0;i<10;i++){
    //push the elements onto the queue
    aqueue.push(i*0.5);
  }
  //display the size of the queue
  cout << aqueue.size() << endl;
  while(!aqueue.empty()) {
    cout <<aqueue.front() << ' ';	//get the first element
    aqueue.pop();			//pop the first element
  }
  cout << "\n\n\n";
  
	
  
  /////////////////////////
  ///Stack Demonstration///
  /////////////////////////
  typedef stack<char> stack_type;  //define a stack type
				  // (a stack of double)
  stack_type astack;		//define a stack
  
  for(i=0;i<10;i++){
    //push the elements onto the stack
    astack.push(i+67);
  }
  //display the size of the stack
  cout << astack.size() << endl;
  while(!astack.empty()) {
    cout <<astack.top() << ' ';	 //get the top element
    astack.pop();		//pop the top element
  }
  cout << endl;

  return 1;
}


//by Simon Fall 2004
