// *********************************************************
// Header file NewListP.h for the ADT list.
// Pointer-based implementation.
// Modified from Carrano page 165+
// *********************************************************
typedef int listItemType;  // desired-type-of-list-item

struct listNode;  // defined in implementation file
typedef listNode* ptrType;  // pointer to node

//#include "bool.h"

class listClass
{
public:
// constructors and destructor:
   listClass(); 
   listClass(const listClass& L);
   ~listClass();


// list operations:
   void listClass::operator=(const listClass& L);
   bool ListIsEmpty();
   int ListLength();
   void ListInsert(int NewPosition, listItemType NewItem,
                   bool& Success);
   void ListDelete(int Position, bool& Success);
   void ListRetrieve(int Position, listItemType& DataItem, 
                     bool& Success);
   void DisplayList();

private:
   ptrType PtrTo(int Position);

   int     Size;
   ptrType Head;
}; // end class
// End of header file.





