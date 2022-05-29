/* BST.h contains the declaration of class template BST.
   Basic operations:
   Constructor: Constructs an empty BST
     empty:       Checks if a BST is empty
     search:      Search a BST for an item
     insert:      Inserts a value into a BST
     remove:      Removes a value from a BST
     inorder:     Inorder traversal of a BST -- output the data values
     graph:       Output a grapical representation of a BST
   Private utility helper operations:
     search2:     Used by delete
     inorderAux:  Used by inorder
     graphAux:    Used by graph
   Other operations described in the exercises:
     destructor
     copy constructor
     assignment operator
     preorder, postorder, and level-by-level traversals
     level finder
   Note: Execution terminates if memory isn't available for a new BST node.
---------------------------------------------------------------------------*/

#include <iostream>

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

template <typename DataType>
class BST
{
 public:
  /***** Function Members *****/
  BST();
  /*------------------------------------------------------------------------
    Construct a BST object.

    Precondition:  None.
    Postcondition: An empty BST has been constructed.
   -----------------------------------------------------------------------*/

  bool empty() const;
  /*------------------------------------------------------------------------
    Check if BST is empty.

    Precondition:  None.
    Postcondition: Returns true if BST is empty and false otherwise.
   -----------------------------------------------------------------------*/

  bool search(const DataType & item) const; 
  /*------------------------------------------------------------------------
    Search the BST for item.

    Precondition:  None.
    Postcondition: Returns true if item found, and false otherwise.
   -----------------------------------------------------------------------*/
   
  void insert(const DataType & item);
  /*------------------------------------------------------------------------
    Insert item into BST.

    Precondition:  None.
    Postcondition: BST has been modified with item inserted at proper 
        position to maintain BST property. 
  ------------------------------------------------------------------------*/
  
  void remove(const DataType & item);
  /*------------------------------------------------------------------------
    Remove item from BST.

    Precondition:  None.
    Postcondition: BST has been modified with item removed (if present);
        BST property is maintained.
    Note: remove uses auxiliary function search2() to locate the node
          containing item and its parent.
 ------------------------------------------------------------------------*/
 
  void inorder(ostream & out) const;
  /*------------------------------------------------------------------------
    Inorder traversal of BST.

    Precondition:  ostream out is open.
    Postcondition: BST has been inorder traversed and values in nodes 
        have been output to out.
    Note: inorder uses private auxiliary function inorderAux().
 ------------------------------------------------------------------------*/
 
  void graph(ostream & out) const;
  /*------------------------------------------------------------------------
    Graphic output of BST.

    Precondition:  ostream out is open.
    Postcondition: Graphical representation of BST has been output to out.
    Note: graph() uses private auxiliary function graphAux().
 ------------------------------------------------------------------------*/
 
 private:
  /***** Binary node class *****/
  class BinNode 
  {
  public:
    DataType data;
    BinNode * left;
    BinNode * right;

    // BinNode constructors
    // Default -- data part is default DataType value; both links are null.
    BinNode() : left(0), right(0) {}
      
    // Explicit Value -- data part contains item; both links are null.
    BinNode(DataType item): data(item), left(0), right(0){}
	
  };// end of class BinNode declaration

  typedef BinNode *BinNodePointer;
  
  /***** Private Function Members *****/
  void search2(const DataType & item, bool & found,
               BinNodePointer & locptr, BinNodePointer & parent) const;
 /*------------------------------------------------------------------------
   Locate a node containing item and its parent.
 
   Precondition:  None.
   Postcondition: locptr points to node containing item or is null if 
   not found, and parent points to its parent.
 ------------------------------------------------------------------------*/
 
  void inorderAux(ostream & out, 
                  typename BST<DataType>::BinNodePointer subtreePtr) const;
  /*------------------------------------------------------------------------
    Inorder traversal auxiliary function.

    Precondition:  ostream out is open; subtreePtr points to the starting root 
        of a subtree of this BST.
    Postcondition: Subtree with root pointed to by subtreePtr has been
        output to out.
 ------------------------------------------------------------------------*/
 
  void graphAux(ostream & out, int indent,
                      typename BST<DataType>::BinNodePointer subtreeRoot) const;
  /*------------------------------------------------------------------------
    Graph auxiliary function.

    Precondition:  ostream out is open; subtreePtr points to the root of a subtree 
        of this BST.
    Postcondition: Graphical representation of subtree with root pointed 
        to by subtreePtr has been output to out, indented indent spaces.
 ------------------------------------------------------------------------*/
 
 /***** Data Members *****/
  BinNodePointer myRoot;   // the root of the binary search tree

}; // end of class template declaration

//--- Definition of constructor
template <typename DataType>
inline BST<DataType>::BST()
: myRoot(0)
{}

//--- Definition of empty()
template <typename DataType>
inline bool BST<DataType>::empty() const
{ return myRoot == 0; }

//--- Definition of search()
template <typename DataType>
bool BST<DataType>::search(const DataType & item) const
{
  //   typename BST<DataType>::BinNodePointer locptr = myRoot;
  BinNodePointer locptr = myRoot;  // same as above

  bool found = false;

  // the following codes may be replaced by recursion
  while (!found && locptr != 0)
    {
      if (item < locptr->data)       // descend left
	locptr = locptr->left;
      else if (locptr->data < item)  // descend right
	locptr = locptr->right;
      else                           // item found
	found = true;
    }
  return found;
}

//--- Definition of insert()
template <typename DataType>
inline void BST<DataType>::insert(const DataType & item)
{
  //  typename BST<DataType>::BinNodePointer 
  BinNodePointer       // same as above
    locptr = myRoot,   // search pointer
    parent = 0;        // pointer to parent of current node
  
  bool found = false;     // indicates if item already in BST

  // first find the element
  while (!found && locptr != 0)
    {
      parent = locptr;
      if (item < locptr->data)       // descend left
	locptr = locptr->left;
      else if (locptr->data < item)  // descend right
	locptr = locptr->right;
      else                           // item found
	found = true;
    }

  if (!found)
    {                                 // construct node containing item
      //      locptr = new typename BST<DataType>::BinNode(item);  
      locptr = new class BST<DataType>::BinNode(item);  // same as above

      if (parent == 0)               // empty tree
	myRoot = locptr;
      else if (item < parent->data )  // insert to left of parent
	parent->left = locptr;
      else                           // insert to right of parent
	parent->right = locptr;
   }
   else
      cout << "Item already in the tree\n";
}

//--- Definition of remove()
template <typename DataType>
void BST<DataType>::remove(const DataType & item)
{
   bool found;                      // signals if item is found
   typename BST<DataType>::BinNodePointer 
     x,                            // points to node to be deleted
     parent;                       //    "    " parent of x and xSucc

   search2(item, found, x, parent);

   if (!found)
     {
       cout << "Item not in the BST\n";
       return;
     }

   //else
   if (x->left != 0 && x->right != 0)
     {// node has 2 non-NULL children
      // Find x's inorder successor and its parent
      typename BST<DataType>::BinNodePointer xSucc = x->right;
      parent = x;
      while (xSucc->left != 0)       // descend left
	{
	  parent = xSucc;
	  xSucc = xSucc->left;
	}

      // Move contents of xSucc to x and change x 
      // to point to successor, which will be removed.
      x->data = xSucc->data;  // copy data over
      x = xSucc;              // move x to the node to be deleted
   } // end if node has 2 children
   
   // Now proceed with case where node has 0 or 1 child
   typename BST<DataType>::BinNodePointer 
     subtree = x->left;             // pointer to a subtree of x
   if (subtree == 0)
     subtree = x->right;            // subtree is pointing to the non-NULL subtree, if any

   if (parent == 0)                 // root with 0 or 1 subtree being removed
     myRoot = subtree;
   else if (parent->left == x)      // left child of parent
     parent->left = subtree;        // parent adoption
   else                             // right child of parent
     parent->right = subtree;       // parent adoption
   delete x;
}

//--- Definition of inorder()
template <typename DataType>
inline void BST<DataType>::inorder(ostream & out) const
{ 
  inorderAux(out, myRoot); 
}

//--- Definition of graph()
template <typename DataType>
inline void BST<DataType>::graph(ostream & out) const
{ graphAux(out, 0, myRoot); }

//--- Definition of search2()
template <typename DataType>
void BST<DataType>::search2(const DataType & item, bool & found,
                            typename BST<DataType>::BinNodePointer & locptr, 
                            typename BST<DataType>::BinNodePointer & parent) const
{
  locptr = myRoot;
  parent = 0;       // by definition, the root's parent is NULL
  found = false;
  while (!found && locptr != 0)
    {
      if (item < locptr->data)       // descend left
	{
	  parent = locptr;
	  locptr = locptr->left;
	}
      else if (locptr->data < item)  // descend right
	{
	  parent = locptr;
	  locptr = locptr->right;
	}
      else                           // item found
	found = true;
    }
}

//--- Definition of inorderAux()
template <typename DataType>
void BST<DataType>::inorderAux(ostream & out, 
                               typename BST<DataType>::BinNodePointer subtreeRoot) const
{
  if (subtreeRoot != 0)
    {
      inorderAux(out, subtreeRoot->left);    // L operation
      out << subtreeRoot->data << "  ";      // V operation
      inorderAux(out, subtreeRoot->right);   // R operation
    }
}

//--- Definition of graphAux()
#include <iomanip>

// Draw a "lateral" tree: draw right, then self, draw left
template <typename DataType>
void BST<DataType>::graphAux(ostream & out, int indent, 
                             typename BST<DataType>::BinNodePointer subtreeRoot) const
{
  if (subtreeRoot != 0)
    {
      graphAux(out, indent + 8, subtreeRoot->right);
      out << setw(indent) << " " << subtreeRoot->data << endl;
      graphAux(out, indent + 8, subtreeRoot->left);
    }
}

#endif
