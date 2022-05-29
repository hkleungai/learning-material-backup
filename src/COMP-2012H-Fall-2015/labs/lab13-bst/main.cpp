#include <iostream> 
using std::cin; 
using std::cout; 

#include "Tree.h"

void searchTree(int intVal, const Tree< int > &intTree)
{
	cout << "\nSearch for " << intVal << ":\n";

   // create a pointer with the user value
   TreeNode< int > *ptr = intTree.binaryTreeSearch( intVal );

   // a value is found
   if ( ptr != 0 )
      cout << ptr->getData() << " was found\n";
   else // value not found
      cout << "Element was not found\n";
}

int main()
{
   Tree< int > intTree;
   int intVal;

   cout << "=== Enter 10 integer values ===\n";

   intTree.insertNode( 1 );
   intTree.insertNode( 2 );
   intTree.insertNode( 3 );
   intTree.insertNode( 88 );
   intTree.insertNode( 4 );
   intTree.insertNode( 6 );
   intTree.insertNode( 0 );
   intTree.insertNode( 22 );
   intTree.insertNode( 21 );
   intTree.insertNode( 10 );

   cout << "\nPreorder traversal\n";
   intTree.preOrderTraversal();

   cout << "\nInorder traversal\n";
   intTree.inOrderTraversal();

   cout << "\nPostorder traversal\n";
   intTree.postOrderTraversal();

   cout << "\n\nThere are " << intTree.getDepth()
      << " levels in this binary tree\n";

  searchTree( 5 , intTree );
  searchTree( 22 , intTree );   

   return 0; // indicates successful termination
} // end main