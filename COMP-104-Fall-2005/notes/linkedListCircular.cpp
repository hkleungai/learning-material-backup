#include <iostream>
using namespace std;

struct Node{	 
	int data;	
	Node *next;
};

typedef Node* NodePtr; 


void print(NodePtr Rear){
	NodePtr Cur;
	if(Rear != NULL){
		Cur = Rear->next;
		do{
			cout << Cur->data << " ";
			Cur = Cur->next;
		}while(Cur != Rear->next);
		cout << endl;
	}
}

void insertNode(NodePtr& Rear, int item){
	NodePtr  New, Cur, Prev;
	New = new Node;	New->data = item;                 
	if(Rear == NULL){	// insert into empty list
		Rear = New;
		Rear->next = Rear;
		return;
	}
	Prev = Rear;
	Cur = Rear->next;
	do{
		if(item <= Cur->data)
			break;
		Prev = Cur;
		Cur = Cur->next;
	}while(Cur != Rear->next);
	New->next = Cur;
	Prev->next = New;
	if(item > Rear->data)	//revise end node pointer if adding to end
		Rear = New;
}

void deleteNode(NodePtr& Rear, int item){
	NodePtr Cur, Prev;                
	if(Rear == NULL){       
		cout << "Trying to delete empty list" << endl;
		return;
	}     
	Prev = Rear;
	Cur = Rear->next;		
	do{				// find Prev and Cur
		if(item <= Cur->data)  break;
		Prev = Cur;
		Cur = Cur->next;
	}while(Cur != Rear->next);
	if(Cur->data != item){	// data does not exist
		cout << "Data Not Found" << endl;
		return;
	}
	if(Cur == Prev){		// delete single-node list
		Rear = NULL;
		delete Cur;
		return;
	}
	if(Cur == Rear)		// revise Rear pointer if deleting end
		Rear = Prev;
	Prev->next = Cur->next;	// revise pointers
	delete Cur;
}

void main(){
	NodePtr Rear = NULL;
	
	insertNode(Rear, 3);
	insertNode(Rear, 1);
	insertNode(Rear, 7);
	insertNode(Rear, 5);
	insertNode(Rear, 8);
	print(Rear);
	deleteNode(Rear, 1);
	deleteNode(Rear, 3);
	deleteNode(Rear, 8);
	print(Rear);
	insertNode(Rear, 1);
	insertNode(Rear, 8);                
	print(Rear);
}
