#ifndef _LIST_H
#define _LIST_H

#include <string>

using namespace std;

/* PolyNode class: the list node of a linked list 
       representing a term in a polynomial list
       member variables: coef & expon
 */
class PolyNode
{
  public:
    // constructors
    PolyNode() { next=NULL; prev=NULL; };
    PolyNode(int c, int ex, int ey): coef(c), expx(ex), expy(ey) { next=NULL; prev=NULL; };
    PolyNode(int c, int ex, int ey, PolyNode* p, PolyNode* n): coef(c), expx(ex), expy(ey) { next=n; prev=p; };

    // destructor
    ~PolyNode() { next=NULL; prev=NULL; };

    // equal-to operator    
    bool operator==(const PolyNode& other) const { 
      return ((coef==other.coef)&&(expx==other.expx)&&(expy==other.expy));
    };

    // member variables
    int coef;
    int expx;
    int expy;

    PolyNode* prev;
    PolyNode* next;
};

/* PolyList class: a linked list
   representing a polynomial
 */
class PolyList
{
  public:
    // constructor
    PolyList();
    // copy constructor
    PolyList(const PolyList& a);
    // destructor
    ~PolyList();

    // If the linked list is empty, return true, else false
    bool empty() const;

    // returns the number of node in the linked list
    int length() const;

    // add a node to the end of the linked list
    void attachNode(PolyNode*);

    // delete the first node in the linked list
    void deleteHead();

    // Assignment operator
    PolyList& operator=(const PolyList& a);

    // Equal-to operator
    bool operator==(const PolyList& a) const;

    // find and return the n-th node in the linked list
    PolyNode* operator[](int n) const;
    
  private:
    PolyNode *head;
    PolyNode *tail;
};

#endif
