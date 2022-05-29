/*--- LQueue.cpp ----------------------------------------------------------
             This file implements LQueue member functions.
-------------------------------------------------------------------------*/
 
#include <new>
using namespace std;

#include "LQueue.h"

//--- Definition of Queue constructor
Queue::Queue()
  : myFront(0), myBack(0)
{}

//--- Definition of Queue copy constructor
Queue::Queue(const Queue & original)
{
  myFront = myBack = 0;
  if (!original.empty())
    {
      // Copy first node
      myFront = myBack = new Node(original.front());

      // Set pointer to run through original's linked list
      NodePointer origPtr = original.myFront->next;
      while (origPtr != 0)
	{
	  myBack->next = new Node(origPtr->data);
	  myBack = myBack->next;
	  origPtr = origPtr->next;
	} //while
    } //if
}

void Queue::delete_q( void ){
  // Set pointer to run through the queue
  NodePointer prev = myFront, // node to be released/deleted
    ptr; // points to the front node
  
  while (prev != 0)
    {
      ptr = prev->next;
      delete prev;
      prev = ptr;
    }
}

//--- Definition of Queue destructor
// delete queue from the front
Queue::~Queue()
{ 
  delete_q();
}

//--- Definition of assignment operator
const Queue & Queue::operator=(const Queue & rightHandSide)
{
  if (this != &rightHandSide)         // check that not q = q
    {
      this->delete_q();               // destroy current linked list
      
      if (rightHandSide.empty())       // empty queue
	myFront = myBack = 0;
      else
	{                                // copy rightHandSide's list
	  // Copy first node
	  myFront = myBack = new Node(rightHandSide.front());

	  // Set pointer to run through rightHandSide's linked list
	  NodePointer rhsPtr = rightHandSide.myFront->next;
	  while (rhsPtr != 0)
	    {
	      myBack->next = new Node(rhsPtr->data);
	      myBack = myBack->next;
	      rhsPtr = rhsPtr->next;
	    }
	}
    }
  return *this;
}

//--- Definition of empty()
bool Queue::empty() const
{ 
  return (myFront == 0); 
}

//--- Definition of enqueue()
void Queue::enqueue(const QueueElement & value)
{
   NodePointer newptr = new Node(value);

   if (empty())
     myFront = myBack = newptr;
   else
     {
       myBack->next = newptr;
       myBack = newptr;
     }
}

//--- Definition of display()
void Queue::display(ostream & out) const
{
  NodePointer ptr;
  
  for (ptr = myFront; ptr != 0; ptr = ptr->next)
    out << ptr->data << "  ";
  out << endl;
}

//--- Definition of front()
// Peep the first element of the queue
QueueElement Queue::front() const
{
  if (!empty())
    return (myFront->data);
  else
    {
      cerr << "*** Queue is empty "
	" -- returning garbage ***\n";
      QueueElement * temp = new(QueueElement);  
      QueueElement garbage = *temp;     // "Garbage" value
      delete temp;
      return garbage;
    }
}

//--- Definition of dequeue()
// simply decrement the queue
void Queue::dequeue()
{
  if (!empty())
    {
      NodePointer ptr = myFront;
      myFront = myFront->next;
      delete ptr;
      if (myFront == 0)     // queue is now empty
	myBack = 0;
    }   
  else
    cerr << "*** Queue is empty -- can't remove a value ***\n";
}
