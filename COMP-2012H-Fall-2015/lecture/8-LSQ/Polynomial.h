#ifndef POLYNOMIAL
#define POLYNOMIAL

class Node; // class prototype for typedef Node *

typedef int CoefType;
typedef Node *  NodePointer; 

class Polynomial{

 private:
  /*** Term class  ***/
  class Term  {
  public:  // cannot be private as they are accessed by Node class
    /*** Data members ***/
    CoefType coef;
    unsigned int expo;
  }; // end class Term

  /*** Node Class ***/
  class Node {
  private:
    Term data;
    NodePointer next;
    
  public:
    // -- Node constructor
    // creates a node with given initial values
    Node (CoefType co = 0, int x = 0, NodePointer ptr = 0) {
      data.coef = co;
      data.expo = x;
      next = ptr;
    }
  }; // end of Node class

 public:
  /*** Function members ***/
  // operations on polynomials

 private:
  /*** Data members ***/
  int myDegree;
  NodePointer myTerms; // a linked list with head node;
  // its ElementType is Term
}; // end of Polynomial class template
#endif
