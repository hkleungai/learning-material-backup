/* File: bst.cpp */

template <typename T>
bool BST<T>::contains(const T& x) const
{
  if (is_empty( ))
    return false;
  
  if (root->value == x)
    return true;
  else if (x < root->value)
    return root->left.contains(x);
  else
    return root->right.contains(x);
}

template <typename T>
void BST<T>::print(int depth) const
{
  if (is_empty( ))                 // Base case
    return;
  
  root->right.print(depth+1);       // Recursion: right subtree
  
  for (int j = 0; j < depth; j++)  // Print the node value
    cout << '\t';
  cout << root->value << endl;
  
  root->left.print(depth+1);       // Recursion: left subtree
}

template <typename T>   // Find the maximum value
const T& BST<T>::find_max( ) const
{
  if (is_empty( ))    // Should not happen!
    {
      cerr << "Error: find_max( ) called by an empty BST\n";
      return DUMMY;   // Returned value is a dummy
    }
  
  const bst_node* node = root;
  while (!node->right.is_empty( ))
    node = node->right.root;
  
  return node->value;
}

template <typename T>   // Find the minimum value
const T& BST<T>::find_min( ) const
{
  if (is_empty( ))    // Should not happen!
    {
      cerr << "Error: find_min( ) called by an empty BST\n";
      return DUMMY;   // Returned value is a dummy
    }
    
  const bst_node* node = root;
  while (!node->left.is_empty( ))
    node = node->left.root;

  return node->value;
}


template <typename T> // Replace the item to be remove by the
void BST<T>::remove(const T& x) // leftmost item of its right subtree
{
  if (is_empty( ))            // Item is not found; do nothing
    return;
  
  if (x < root->value)        // Remove from the left subtree
    root->left.remove(x);
  else if (x > root->value)   // Remove from the right subtree
    root->right.remove(x);
  else if (root->left.root && root->right.root) // Found node has 2 children
    {
      root->value = root->right.find_min( );
      root->right.remove(root->value);
    }
  else // Found node has 0 or 1 child
    {
      bst_node* deleting_node = root; // Save the root to delete first
      root = (root->left.is_empty( )) ? root->right.root : root->left.root;
      
      // Reset its left/right subtree to null first before removal
      deleting_node->left.root = deleting_node->right.root = NULL;
      delete deleting_node;
    }
}
    
    
template <typename T>   // Insert and preserve the BST property
void BST<T>::insert(const T& x)
{
  if (is_empty( ))    // Find the spot
    root = new bst_node(x);
  else if (x < root->value)
    root->left.insert(x);
  else if (x > root->value)
    root->right.insert(x);
  else
    ;               // x == root->value; do nothing
}
