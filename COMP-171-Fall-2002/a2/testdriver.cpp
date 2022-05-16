#include "stdlib.h"
#include "stdio.h"
#include "iostream.h"
#include "math.h"
#include "string.h"
#include "fstream.h"
#include "dictionary.hpp"


// Definition of a Stack.
struct Stack
{
	int Black_Height;
	Stack * next;
};

// Push a black height into a stack.
void Push_Stack(int B_Height, Stack * &stack)
{
	Stack * p = new Stack;
	p->Black_Height = B_Height;
	p->next = stack;
	stack = p;
}

// Pop a black height out of a stack.
int Pop_Stack(Stack * &stack)
{
	Stack * p = stack->next;
	int i = stack->Black_Height;
	delete stack;
	stack = p;
    return i;
}

// Clear a stack if it is not empty. 
void Clear_Stack(Stack *&stack)
{
	while (!(stack == 0)){
		Stack * p = stack;
		stack = stack->next;
		delete p;
	}
}

// Function to verify the red black property of a node in a binary tree.
template <class T>
bool Verify_Red_Black(RBTreeNode<T> * Sentinel, RBTreeNode<T> * Node,Stack * &stack)
{
	bool v;
	RBTreeNode<T> * p=Node;
    if (p == Sentinel){ 
		Push_Stack(0,stack);
		return true;
	}
	else{
		v = (Verify_Red_Black(Sentinel,p->rightchild,stack)) && (Verify_Red_Black(Sentinel,p->leftchild,stack));
		if (!(v)) return false;
		else{
		   int left_height = Pop_Stack(stack);
		   if ((p->leftchild)->color == BLACK) left_height = left_height + 1;
		   int right_height = Pop_Stack(stack);
		   if ((p->rightchild)->color == BLACK) right_height = right_height + 1;
		   if (!(right_height == left_height)) return false;
		   else Push_Stack(left_height,stack);
		   if (p->color == RED){
			   if ( ((p->rightchild)->color == RED) || ((p->leftchild)->color == RED) ) return false;
			   else return true;
		   }
		   return true;
		}
	}
}

// The inherited class from the red black tree.
template <class T>
class RedBlack_Tree: public RedBlackTree<T>
{
	public:
        bool Verify_Red_Black_Property( );
	
};

// Function to verify the red black property of a binary tree.
template <class T>
bool RedBlack_Tree<T>::Verify_Red_Black_Property( )
{
	RBTreeNode<T> * Root = getRoot( );
	RBTreeNode<T> * Sentinel = getSentinel( );
	Stack * Black_Height_Stack = 0;
	bool R_B_Property;
	if (Root->color == RED) return false;
	else R_B_Property = Verify_Red_Black(Sentinel, Root, Black_Height_Stack);
    Clear_Stack(Black_Height_Stack);
	return R_B_Property;
}



// The test driver.
int main(int argc, char** argv )
{
	// check if there are two arguments as required
    if (!(argc==2)) {
        cout << "You should use one argument." << endl;
        return 0;
    }


    // get the second argument, the length of the array, and turn into a string
    int length=atoi((const char *)(argv[1]));
    char fl[10];
	strcpy(fl, argv[1]);
    

    // find the file to read array from
    char filename[15];
    strcpy(filename, "array");
    strcat(filename, fl);
    strcat(filename, ".txt");


	// array to hold all the elements to be sorted
    int key[1024]; 
    ifstream fin;
	int i;


    // read the numbers from the array file into the array
    fin.open(filename);
    for (i = 0; i< length; i++) { 
        char c[10];
        fin.getline(c, '\n');
        key[i]=atoi(c);
    }
    fin.close();


	// A sample array with which to test your algorithm.
	//int key[] = {33,12,4567,1,234,7,456,90,67,213,66,54,71,999,28,53,87,458,912,77,17,888,1235,97,29,61,38};
    
	// In the test driver we instantiate the template with integer.
	RedBlack_Tree<int>  Red_Black_Tree;
	RedBlack_Tree<int> * pRed_Black_Tree = &Red_Black_Tree;
	bool Red_Black_Property;



	// Insert the keys in the array one by one and examine the red black property after each insertion.
	for (i = 0; i < length;i++){
		pRed_Black_Tree->insert(key[i]);
		cout << key[i]<<endl;
		Red_Black_Property = pRed_Black_Tree->Verify_Red_Black_Property( );
	    if (Red_Black_Property) cout<< "A correct Black_Red_Tree" <<endl;
	    else cout<< "Not a correct Black_Red_Tree" <<endl;
	}

 
	// Sample code to test the "find" function of your code.
    int * p = pRed_Black_Tree->find(99);
	if(!(p == 0)) cout<< *p <<endl;
	else cout<<"The key is not found"<<endl;


	// Erase the keys in the array one by one and examine the red black property after each erasion.
    for (i = 0;i < length;i++) {
		pRed_Black_Tree->erase(key[i]);
		Red_Black_Property = pRed_Black_Tree->Verify_Red_Black_Property( );
	    if (Red_Black_Property) cout<< "A correct Black_Red_Tree" <<endl;
	    else cout<< "Not a correct Black_Red_Tree" <<endl;
	}
	return 1;

}