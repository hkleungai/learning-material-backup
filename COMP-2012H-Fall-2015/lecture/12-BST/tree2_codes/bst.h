// bst.h
// unbalanced binary search trees
#ifndef BSTree_
#define BSTree_

#include "binary.h"
#include "xcept.h"

template<class E, class K>
  class BSTree: public BinaryTree<E> {
 public:
    bool Search(const K& k, E& e) const;
    BSTree<E, K>& Insert(const E& e);
    BSTree<E, K>& InsertVisit(const E& e, void(*visit)(E& u));
    BSTree<E, K>& Delete(const K& k, E& e);
    void Ascend() {
      this->InOutput();
    }
  };

template<class E, class K>
  bool BSTree<E, K>::Search(const K& k, E &e) const {
  // Search for element that matches k.
  // pointer p starts at the root and moves through
  // the tree looking for an element with key k

  BinaryTreeNode<E> *p = this->root;
  while (p) // examine p->data
    if (k < p->data)    // if the data type does not match k, implicit cast is performed
      p = p->LeftChild;
    else if (k > p->data)
      p = p->RightChild;
    else {// found element
      e = p->data;
      return true;
    }
  return false;
}

template<class E, class K>
  BSTree<E, K>& BSTree<E, K>::Insert(const E& e) {
  // Insert e if not duplicate.

  BinaryTreeNode<E> *p = this->root, // search pointer
    *pp = 0; // parent of p

  // find place to insert by searching
  while (p) {// examine p->data
    pp = p;
    // move p to a child
    if (e < p->data)
      p = p->LeftChild;
    else if (e > p->data)
      p = p->RightChild;
    else
      throw BadInput(); // duplicate
  }

  // get a node for e and attach to pp
  BinaryTreeNode<E> *r = new BinaryTreeNode<E> (e);
  if (this->root) {// tree not empty
    if (e < pp->data)
      pp->LeftChild = r;
    else
      pp->RightChild = r;
  } else
    // insertion into empty tree
    this->root = r;

  return *this;
}

template<class E, class K>
  BSTree<E, K>& BSTree<E, K>::InsertVisit(const E& e, 
					  void(*visit)(E& u)) {
  // Insert e if not duplicate.
  // Visit e if duplicate.

  // search for a matching element
  BinaryTreeNode<E> *p = this->root, // search pointer
    *pp = 0; // parent of p
	
  while (p) {// examine p->data
    pp = p;
    if (e < p->data)
      p = p->LeftChild;
    else if (e > p->data)
      p = p->RightChild;
    else {// duplicate
      visit(p->data);
      return *this;
    };
  }

  // not a duplicate
  // get a node for e and attach to pp
  BinaryTreeNode<E> *r = new BinaryTreeNode<E> (e);
  if (this->root) {// tree not empty
    if (e < pp->data)
      pp->LeftChild = r;
    else
      pp->RightChild = r;
  } else
    // insertion into empty tree
    this->root = r;
  
  return *this;
}

template<class E, class K>
BSTree<E, K>& BSTree<E, K>::Delete(const K& k, E& e) {
  // Delete element with key k and put it in e.

  // set p to point to node with key k
  BinaryTreeNode<E> *p = this->root, // search pointer
    *pp = 0; // parent of p

  // search for the element first
  while (p && p->data != k) {// move to a child of p
    pp = p;
    if (k < p->data)
      p = p->LeftChild;
    else
      p = p->RightChild;
  }
  if (!p)
    throw BadInput(); // no element with key k
  
  e = p->data; // save element to delete
  
  // restructure tree
  // handle case when p has two children
  if (p->LeftChild && p->RightChild) {// two children
    // convert to zero or one child case
    // find the predecessor, i.e., the largest element in left subtree of p

    BinaryTreeNode<E> *s = p->LeftChild, *ps = p; // parent of s

    while (s->RightChild) {// move to larger element
      ps = s;
      s = s->RightChild;
    }
    
    // move largest from s to p
    p->data = s->data;
    p = s;
    pp = ps;
  }

  // p has at most one child
  // save child pointer in c
  BinaryTreeNode<E> *c;
  if (p->LeftChild)
    c = p->LeftChild;
  else
    c = p->RightChild;
  
  // delete p
  if (p == this->root)
    this->root = c;     // delete root 
  else {// is p left or right child of pp?
    if (p == pp->LeftChild)
      pp->LeftChild = c;
    else
      pp->RightChild = c;
  }
  delete p;
  
  return *this;
}

#endif
