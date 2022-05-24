/*

http://everything2.com/title/AVL+tree

I present here a highly recursive implementation of the AVL tree algorithm. This is 
a generic implementation using template classes that will order a binary tree on a 
user defined sort key plus allow for arbitrary payloads. 


The AVL tree algorithm is used to keep the binary tree in balance so that seaching 
will always be optimal. Each time you insert or remove a node from the tree, the 
tree is rebalanced. Thus, you pay a small price when maintaining the tree for excellent 
search results with O(log n) execution for each search. 

By default, the T::operator < (with its traditional meaning of less than) is 
used to create order in the tree but by reversing the meaning of T::operator < to 
actual mean greater than, you can create a tree that is reverse sorted. If you do this, 
please comment it carefully and fully otherwise some poor sucker is going to be 
hopelessly confused when he comes along and tries to modify your code. 

This code has been compiled and tested using MS VC++ 6.0 and DJGPP 3.04. 

You can download this code from http://www.cjkware.com/wamckee/avl.zip 

*/

//--------------------------------------------------------------------------------

//
//
// The template class AVL::Node (used in AVL::Tree) requires the following:
//
// T::T (const T &);
// T::~T ();
// bool T::operator < (const T & rhs) const;
// bool T::operator == (const T & rhs) const;
// 
// For printing purposes one must declare:
//
// ostream & operator << (const ostream &, const T &);
//

//
// iostream is required for printing only.
//

#include <iostream>
#include <stdlib.h>

//
// Use "namespace" to make sure the class names don't conflict with other code.
//

namespace AVL {

//
// The basic unit of currency in a tree are the nodes that comprise it.
//
template <class T>
class Node
{
public :

// This is were we keep the data we want to store in each node.
// It is const because if you change it while it is in the tree structure
// you compromise the integrity of the tree.
// It is public because the Tree class must have access to it in order
// to return it after being found with the found_node function.

    const T data;

private :

// Each node has two children: left and right. If they are both NULL then
// the node is a leaf node. Otherwise, it's an interior node.

    Node<T> * left, * right;

// The height is computed to be: 0 if NULL, 1 for leaf nodes, and the maximum
// height of the two children plus 1 for interior nodes.
// This is used to keep the tree balanced.

    int height;

    void compute_height ()
    {
        height = 0;
        if (left != NULL && left -> height > height)
            height = left -> height;
        if (right != NULL && right -> height > height)
            height = right -> height;
        height += 1;
    }

// The constructor is private because the nodes are self allocating.

    Node (const T & inData)
        : data (inData), left (NULL), right (NULL), height (1)
    {
    }

public :

// Recursively delete the children if this node is being nuked.

    ~Node ()
    {
        delete left;
        delete right;
    }

// Recursively insert some data into the tree then balance it on the way up.

    Node<T> * insert_node (const T & inData)
    {
        if (this == NULL)
            return new Node<T> (inData);

        if (inData < data)
            left = left -> insert_node (inData);
        else
            right = right -> insert_node (inData);
        return balance ();
    }

// Recursively find some data in the tree and if found return a pointer
// to the node containing the data. If not found then return NULL.

    const Node<T> * find_node (const T & inData) const
    {
        if (this == NULL)
            return NULL;

        if (inData == data)
            return this;

        if (inData < data)
            return left -> find_node (inData);
        else
            return right -> find_node (inData);
    }

// Recursively search the tree for some data and if found remove (delete) it.
// When you remove an interior node the right child must be place right of
// the right most child in the left sub-tree.
// Remember to balance the tree on the way up after removing a node.

    Node<T> * remove_node (const T & inData)
    {
        if (this == NULL)
            return NULL;

        // we found the data we were looking for

        if (inData == data)
        {
            // save the children

            Node<T> * tmp = left -> move_down_righthand_side (right);

            // by setting the children to NULL, we delete exactly one node.

            left = NULL;
            right = NULL;
            delete this;

            // return the reorganized children

            return tmp;
        }

        if (inData < data)
            left = left -> remove_node (inData);
        else
            right = right -> remove_node (inData);
        return balance ();
    }

// Recursively print out all nodes in order (left to right).

    void print_node (std::ostream & co) const
    {
        if (this == NULL)
            return;

        left -> print_node (co);

        co << data << " ";

        right -> print_node (co);
    }

private :


// move_down_righthand_side is the remove_node helper function:
//
// Recursively find the right most child in a sub-tree and put
// the "rhs" sub-tree there.
// Re-balance the tree on the way up.

    Node<T> * move_down_righthand_side (Node<T> * rhs)
    {
        if (this == NULL)
            return rhs;

        right = right -> move_down_righthand_side (rhs);
        return balance ();
    }

//
// Balancing a tree (or sub-tree) requires the AVL algorithm.
//
// If the tree is out of balance left-left, we rotate the node to the right.
// If the tree is out of balance left-right, we rotate the left child to the
// left and then rotate the current node right.
// If the tree is out of balance right-left, we rotate the right child to the
// right and then rotate the current node left.
// if the tree is out of balance right-right, we rotate the node to the left.
//

    Node<T> * balance ()
    {
        int d = difference_in_height ();

        // only rotate if out of balance
        if (d < -1 || d > 1)
        {
            // too heavy on the right
            if (d < 0)
            {
                // if right child is too heavy on the left,
                // rotate right child to the right
                if (right -> difference_in_height () > 0)
                    right = right -> rotate_right ();

                // rotate current node to the left
                return rotate_left ();
            }
            // too heavy on the left
            else
            {
                // if left child is too heavy on the right,
                // rotate left child to the left
                if (left -> difference_in_height () < 0)
                    left = left -> rotate_left ();

                // rotate current node to the right
                return rotate_right ();
            }
        }

        // recompute the height of each node on the way up
        compute_height ();

        // otherwise, the node is balanced and we simply return it
        return this;
    }

// ** balancing helper functions **

    Node<T> * exchange_left (Node<T> * & r, Node<T> * node)
    {
        r = left;
        left = node -> balance ();
        return balance ();
    }

    Node<T> * exchange_right (Node<T> * & l, Node<T> * node)
    {
        l = right;
        right = node -> balance ();
        return balance ();
    }

    int difference_in_height ()
    {
        int left_height = (left != NULL) ? left -> height : 0;
        int right_height = (right != NULL) ? right -> height : 0;
        return left_height - right_height;
    }

    Node<T> * rotate_left ()
    {
        return right -> exchange_left (right, this);
    }

    Node<T> * rotate_right ()
    {
        return left -> exchange_right (left, this);
    }

};

//
// Cover class for maintaining the tree.
//
// Since Node<T> is self allocating and self deleting, the Tree<T> class
// ensures that only qualified calls are made.
//
// Tree<T> is the public interface to the AVL Tree code.
// Node<T> is not meant to be used by the public.
//
// This code makes use of the somewhat dubious practice of calling a member
// function with a NULL "this" pointer. We will not run into problems since
// we have no virtual member functions in Node<T>.
//

template <class T>
class Tree
{
private :

    Node<T> * root;

public :

    Tree ()
    {
        root = NULL;
    }

    ~Tree ()
    {
        delete root;
    }

    void insert (const T & inData)
    {
        root = root -> insert_node (inData);
    }

    const T * find (const T & inData) const
    {
        const Node<T> * found = root -> find_node (inData);
        if (found != NULL)
            return & found -> data;
        else
            return NULL;
    }

    void remove (const T & inData)
    {
        root = root -> remove_node (inData);
    }

    void print (std::ostream & co) const
    {
        root -> print_node (co);
    }

};

//
// Declare a useful extention to the output stream convention for
// the Tree<T> class.
//

template <class T>
std::ostream & operator << (std::ostream & co, const Tree<T> & tree)
{
    tree.print (co);
    return co;
}

// end of namespace AVL

}

// Test program for AVL::Tree<simple>

using namespace std;

class simple
{
public :

    int key;
    int payload;

    simple (int _key, int _payload)
        : key (_key), payload (_payload) { }

    simple (int _key) : key (_key) { }

// required member functions

    simple (const simple & rhs)
    {
        key = rhs.key;
        payload = rhs.payload;
    }

    bool operator== (const simple & rhs) const
    {
        return key == rhs.key;
    }

    bool operator< (const simple & rhs) const
    {
        return key >= rhs.key; 
    }

};

// required global function

ostream & operator << (ostream & co, const simple & data)
{
    co << data.key << " is #" << data.payload;
    return co;
}

int main ()
{
    AVL::Tree<simple> tree;

    // insert 100 random values and assign them each a "count" number as a
    // payload

    for (int i = 0; i < 100; i++)
    {
        simple v (rand () % 1000, i);
        const simple * vv = tree.find (v);
        if (vv != NULL)
        {
            cout << "already inserted " << *vv << endl;
        }
        else
        {
            cout << "insert " << v << endl;
            tree.insert (v);
            cout << tree << endl;
        }
    }

    cout << tree << endl;

    // randomly search for and remove values

    for (int j = 0; j < 1000; j++)
    {
        simple v (rand () % 1000);

        cout << "looking for " << v.key << " - ";
        const simple * vv = tree.find (v);
        if (vv != NULL)
        {
            cout << "found " << *vv << endl;
            cout << tree << endl;
        }
        else
        {
            cout << "not found" << endl;
        }
        tree.remove (v);
    }

    cout << tree << endl;

    return 0;
}




// References: http://www.enteract.com/~bradapp/ftp/src/libs/C++/AvlTrees.html 

