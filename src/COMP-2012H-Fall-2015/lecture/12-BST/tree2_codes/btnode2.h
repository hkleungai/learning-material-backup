
#ifndef BinaryTreeNode_
#define BinaryTreeNode_

// E is the record, K is the key
template <class T> class BinaryTree;
template<class E, class K> class BSTree;
template<class E, class K> class DBSTree;

template <class T>
class BinaryTreeNode {

  friend class BinaryTree<T>;
  //   friend void PlaceBoosters(BinaryTreeNode<T> *);
  friend class BSTree<T,int>;
  friend class DBSTree<T,int>;

 public:
  BinaryTreeNode() {LeftChild = RightChild = 0;}
  BinaryTreeNode(const T& e)
    {data = e; LeftChild = RightChild = 0;}
  BinaryTreeNode(const T& e, BinaryTreeNode *l,
		 BinaryTreeNode *r)
    {data = e; LeftChild = l; RightChild = r;}

 private:
  T data;
  BinaryTreeNode<T> *LeftChild,  // left subtree
    *RightChild;                 // right subtree
};

#endif
