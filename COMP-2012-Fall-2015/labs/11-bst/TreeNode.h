// Definition of class template TreeNode.
#ifndef TREENODE_H
#define TREENODE_H

template< typename T > class Tree; // forward declaration

template< typename NODETYPE >
class TreeNode 
{
   friend class Tree< NODETYPE >;
public:
   TreeNode( const NODETYPE & ); // constructor
   NODETYPE getData() const; // return data

   // return a leftPtr
   TreeNode *getLeftPtr() const 
   { 
      return leftPtr; 
   } // end getLeftPtr function
   
   // return a rightPtr
   TreeNode *getRightPtr() const 
   { 
      return rightPtr; 
   } // end function getRightPtr

   // set value for leftPtr
   void setLeftPtr( TreeNode *ptr ) 
   { 
      leftPtr = ptr; 
   } // end setLeftPtr function
   
   // set value for rightPtr
   void setRightPtr( TreeNode *ptr ) 
   { 
      rightPtr = ptr; 
   } // end function setRightPtr
private:
   TreeNode *leftPtr; // pointer to left subtree
   NODETYPE data;
   TreeNode *rightPtr; // pointer to right subtree
}; // end class TreeNode

// constructor
template< typename NODETYPE >
TreeNode< NODETYPE >::TreeNode( const NODETYPE &d )
{
   data = d;
   leftPtr = rightPtr = 0;
} // end TreeNode constructor

// return a copy of the data value
template< typename NODETYPE >
NODETYPE TreeNode< NODETYPE >::getData() const 
{ 
   return data; 
} // end function getData

#endif