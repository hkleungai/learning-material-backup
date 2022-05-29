#ifndef _LIST_H
#define _LIST_H

#include <iostream>
#include <cstddef>
#include <string>
using namespace std;

class List {
public:
	// the type of object that the list will be store
	typedef string ItemType;

	// an empty linked-list
	List();

	// cleanup the list
	~List();

	// TO DO: add the element e to the head of the list
	void Add(ItemType e);

    // TO DO:
	// if found, return the cost (at least 1)
	// if not found, return -1
	int Find(ItemType item);

	// TO DO: print out the whole list from head to tail
	void Print();

	// reverse the list
	void Reversal();

private:
	struct Node {
		ItemType item;
		Node* next;

		Node() { next = NULL; };
		Node(ItemType _item, Node* _next): item(_item), next(_next) { };
	};

	// insert node before the head,
	// so node becomes head
	void InsertBeforeHead(Node* node);

	// insert newNode after node
	// (... -> node -> newNode -> ...)
	void InsertAfter(Node* node, Node* newNode);

	// delete node->next
	bool DeleteNextNode(Node* node);

	// delete all nodes
	void DeleteAll();

	// delete the head, so the second element become the head (if exist)
	void DeleteHead();

	Node* head;
};

////////////////////////////////////////////////////////////////
// constructor and destructor
////////////////////////////////////////////////////////////////

List::List() {
	head = NULL;
}

List::~List() {
	DeleteAll();
}

void List::Add(ItemType item) {

}

////////////////////////////////////////////////////////////////
// print
////////////////////////////////////////////////////////////////

void List::Print() {
	Node* n = head;
	cout << '<';
	while (n != NULL) {

		//TO DO: print the element
		//...
		//...
		cout << ' ';
	}
	cout << '>' << endl;
}

////////////////////////////////////////////////////////////////
// reserve the list
////////////////////////////////////////////////////////////////
void List::Reversal() {
	// when curr is in the middle of the list
	// orginally:
	// a    -> b    -> c    -> ...
	// prev    curr    next
	Node* curr = head;
	Node* prev = NULL; // prev->next == curr
	Node* next = NULL; // curr->next == next

	while (curr != NULL) {
		// now, reserve the direction of nodes->next

		// a       b    -> c    -> ...
		// prev    curr

		next = curr->next;

		// a       b    -> c    -> ...
		// prev    curr    next

		curr->next = prev;

		// a    <- b       c    -> ...
		// prev    curr    next

		prev = curr;
		curr = next; // advance to next step

		// a    <- b    -> c    -> ...
		//         prev    curr
	}

	head = prev;
}

////////////////////////////////////////////////////////////////
// find member function
////////////////////////////////////////////////////////////////
// TO DO:
	// if found, return the cost (at least 1), that is, you have visit how many elements
	// if not found, return -1
int List::Find(ItemType item) {

}

////////////////////////////////////////////////////////////////
// insert member functions
////////////////////////////////////////////////////////////////

void List::InsertBeforeHead(Node* node) {
	node->next = head;
	head = node;
}

void List::InsertAfter(Node* node, Node* newNode) {
	Node* afterNode = node->next;
	node->next = newNode;
	newNode->next = afterNode;
}

////////////////////////////////////////////////////////////////
// delete member functions
////////////////////////////////////////////////////////////////

bool List::DeleteNextNode(Node* node) {
	if (NULL == node || NULL == node->next) {
		return false; // nothing can be deleted
	}

	Node* nextNode = node->next;
	node->next = nextNode->next;
	delete nextNode;
	return true;
}

void List::DeleteAll() {
	while (DeleteNextNode(head)) {
		// keep deleting the second node
		// nothing here...
	}

	// the remaining node is the head only (1 node left)
	delete head;
	head = NULL;
}


void List::DeleteHead() {
	Node* n = head;
	head = head->next; // 2nd element becomes the head
	delete n;
}


#endif
