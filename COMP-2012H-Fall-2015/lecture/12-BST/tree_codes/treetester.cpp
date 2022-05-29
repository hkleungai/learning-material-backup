/*----- treetester.cpp -----------------------------------------------------
                Program for testing class template BST.
 ------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include "BST.h"

int main()
{
  // Testing Constructor and empty()
  BST<int> intBST;            // test the class constructor
  cout << "Constructing empty BST\n";
  cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";

  // Testing inorder
  cout << "Inorder Traversal of BST: \n";
  intBST.inorder(cout);

  // Testing insert
  cout << "\nNow insert a bunch of integers into the BST."
    "\nTry items not in the BST and some that are in it:\n";
  int number;
  for (;;)
    {
      cout << "Item to insert (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      intBST.insert(number);
    }
  intBST.graph(cout);  // graph out the tree

  cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";
  cout << "Inorder Traversal of BST: \n";
  intBST.inorder(cout);

  cout << endl;

  // Testing search()
  cout << "\n\nNow testing the search() operation."
    "\nTry both items in the BST and some not in it:\n";
  for (;;)
    {
      cout << "Item to find (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      cout << (intBST.search(number) ? "Found" : "Not found") << endl;
    }

  // Testing remove()
  cout << "\nNow testing the remove() operation."
    "\nTry both items in the BST and some not in it:\n";
  for (;;)
    {
      cout << "Item to remove (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      intBST.remove(number);
      intBST.graph(cout);
    }
  cout << "\nInorder Traversal of BST: \n";
  intBST.inorder(cout);
  cout << endl;
}
