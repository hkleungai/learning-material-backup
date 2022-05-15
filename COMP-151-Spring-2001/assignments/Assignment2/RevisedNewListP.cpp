// *********************************************************
// Implementation file NewListP.cpp for the ADT list.
// Pointer-based implementation.
// Modified from Carrano Chapter 4
// Modfied again by Martin Law, Tue Apr 24, 2001
// To fix memory leakage in operator=
// *********************************************************
#include "NewListP.h"   // header file
#include <stddef.h>  // for NULL
#include <iostream.h>  

struct listNode    // a node on the list
{  listItemType Item;  // a data item on the list
   ptrType      Next;  // pointer to next node
};  // end struct


listClass::listClass()
{ Size = 0;
  Head = NULL;
}  // end default constructor


listClass::listClass(const listClass& L)
{  Size = L.Size;
   if (L.Head == NULL)
      Head = NULL;  // original list is empty

   else
   {   // copy first node
       Head = new listNode;
       Head->Item = L.Head->Item;
       // copy rest of list
       ptrType NewPrev = Head;  // new list pointer
       for (ptrType OrigCur = L.Head->Next; 
                   OrigCur != NULL; 
                   OrigCur = OrigCur->Next)
       { NewPrev->Next = new listNode;
         NewPrev = NewPrev->Next;
         NewPrev->Item = OrigCur->Item;
       }  // end for

       NewPrev->Next = NULL;

   }  // end if
}  // end copy constructor



void listClass::operator=(const listClass& L)
// ---------------------------------------------------
// Redefined assignment operator
// Makes deep copies
// ---------------------------------------------------
{
   bool Success;

   while (!ListIsEmpty())
      ListDelete(1, Success);

   Size = L.Size;
   if (L.Head == NULL)
      Head = NULL;  // original list is empty

   else
   {   // copy first node
       Head = new listNode;
       Head->Item = L.Head->Item;
       // copy rest of list
       ptrType NewPrev = Head;  // new list pointer
       for (ptrType OrigCur = L.Head->Next; 
                   OrigCur != NULL; 
                   OrigCur = OrigCur->Next)
       { NewPrev->Next = new listNode;
         NewPrev = NewPrev->Next;
         NewPrev->Item = OrigCur->Item;
       }  // end for

       NewPrev->Next = NULL;

   }  // end if
}  // end assignment operator


listClass::~listClass()
{
   bool Success;

   while (!ListIsEmpty())
      ListDelete(1, Success);
} // end destructor



bool listClass::ListIsEmpty()
{
   return bool(Size == 0);
}  // end ListIsEmpty

int listClass::ListLength()
{
   return Size;
}  // end ListLength



ptrType listClass::PtrTo(int Position)
// ---------------------------------------------------
// Locates a specified node on a list.
// Precondition: Position is the number of the 
// desired node.
// Postcondition: Returns a pointer to the node at 
// position Position. If Position < 1 or Position > 
// the number of nodes on the list, returns NULL.
// ---------------------------------------------------
{
   if ( (Position < 1) || (Position > ListLength()) )
     return NULL;

   else  // count from the beginning of the list
   {  ptrType Trav = Head;
      for (int Skip = 1; Skip < Position; ++Skip)
         Trav = Trav->Next;
      return Trav;
   }
}  // end PtrTo

void listClass::ListRetrieve(int Position,
                             listItemType& DataItem, 
                             bool& Success)
// ---------------------------------------------------
// Returns the DataItem at position number Position
// on the list.  If Position does not exist Success
// is set to false;  otherwise Success is true.
// ---------------------------------------------------

{
   Success = bool( (Position >= 1) &&
		      (Position <= ListLength()) );

   if (Success)
   {  // get pointer to node, then data in node
      ptrType Cur = PtrTo(Position);
      DataItem = Cur->Item;
   }
} // end ListRetrieve


void listClass::ListInsert(int NewPosition,
                           listItemType NewItem, 
                           bool& Success)
// ---------------------------------------------------
// Inserts a new item with value NewItem at position 
// NewPosition in list. Success is set to false if
// New Position does not exist or a memory allocation
// problem was encountered.  Otherwise Success is true.
// ---------------------------------------------------
{
   int NewLength = ListLength() + 1;

   Success = bool( (NewPosition >= 1) &&
                      (NewPosition <= NewLength) );

   if (Success)
   {  Size = NewLength;

      // create new node and place NewItem in it
      ptrType NewPtr = new listNode;
      Success = bool(NewPtr != NULL);
      if (Success)
      {  NewPtr->Item = NewItem;

         // attach new node to list
         if (NewPosition == 1)
	 {  // insert new node at beginning of list
            NewPtr->Next = Head;
            Head = NewPtr;
         }

         else
         {  ptrType Prev = PtrTo(NewPosition-1);
            // insert new node after node 
            // to which Prev points
            NewPtr->Next = Prev->Next;
	    Prev->Next = NewPtr;
         }  // end if
      }  // end if
   }  // end  if          
} // end ListInsert


void listClass::ListDelete(int Position,
                           bool& Success)
// ---------------------------------------------------
// Deletes item at position Position in the list
// Success is set to false if New Position does not 
// Otherwise Success is true.
// ---------------------------------------------------
{
   ptrType Cur;

   Success = bool( (Position >= 1) && 
		      (Position <= ListLength()) );

   if (Success)
   {  --Size;
      if (Position == 1)
      {  // delete the first node from the list
         Cur = Head;  // save pointer to node
         Head = Head->Next;
      }

      else
      {  ptrType Prev = PtrTo(Position-1);
         // delete the node after the
         // node to which Prev points
         Cur = Prev->Next;  // save pointer to node
         Prev->Next = Cur->Next;
      }  // end if

      // return node to system
      Cur->Next = NULL;
      delete Cur;
      Cur = NULL;
   }  // end if
}  // end ListDelete


void listClass::DisplayList()
// --------------------------------------------------------------
// Displays the data in the linked list.
// List is unchanged
// --------------------------------------------------------------
{
   // Loop invariant: Cur points to the next node to be displayed
   for (ptrType Cur = Head; Cur != NULL; Cur = Cur->Next)
   cout << Cur->Item << "\n";
} // end DisplayList



