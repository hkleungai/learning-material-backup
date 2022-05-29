/* File: bst.h 
 * Each non-empty BST has a root point to a bst_node.
 * Each bst_node has a 
 */
template <typename T>
class BST
{
 private:
  static const T DUMMY; // Returned value of an empty BST in 
                        // find_max() and find_min()
  
  struct bst_node       // A node in a binary search tree
  {
    T value;
    BST left;         // Left sub-tree or called left child
    BST right;        // Right sub-tree or called right child

    // call default constructors for left and right BST (both NULL)
  bst_node(const T& x) : value(x), left( ), right( ) { }; 
  };
  
  bst_node* root;
    
 public:
 BST( ) : root(NULL) { }     // Empty BST when its root is NULL
  BST(const BST& bst) { root = bst.root; } // Shallow BST copy
  ~BST( ) { delete root; }
  
  bool is_empty( ) const { return root == NULL; }
  bool contains(const T& x) const;  // search for x
  void print(int depth = 0) const;  // print the BST, rotated by 90% anti-clockwise
  
  const T& find_max( ) const; // Find the maximum value
  const T& find_min( ) const; // Find the minimum value
  void insert(const T&);      // Insert an item with a policy
  void remove(const T&);      // Remove an item 

  // Challenge1: Implement deep copy for constructor
  // Challenge2: Implement deep copy for assignment
  // Challenge3: how to implement successor function?
};
