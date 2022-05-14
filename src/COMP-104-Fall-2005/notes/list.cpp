#include <iostream>
using namespace std;

struct Node{	 
	int data;	
	Node *next;
};

typedef Node* NodePtr; 

void addHead(NodePtr& Head, int newdata){
	
	NodePtr newPtr = new Node;
	
	if(newPtr != NULL){
		newPtr->data = newdata;
		newPtr->next = Head;
		Head = newPtr;
	}
	else {
		cout << "Memory allocation error" << endl;
		exit(1);
	}
}

void delHead(NodePtr& Head){
	
	if(Head != NULL){
		NodePtr cur = Head;
		Head = Head->next;
		delete cur;
	}
	
}

void DisplayList(NodePtr Head){
	NodePtr cur;
	cur = Head;
	while(cur != NULL){
		cout << cur->data << endl;
		cur = cur->next;
	} 
}



//return the pointer of the node has data=item
//return NULL if item does not exist
NodePtr searchNode(NodePtr Head, int item){
	NodePtr Cur = Head;	
	NodePtr Result = NULL;
	while(Cur != NULL){
		if(Cur->data == item)			
			Result = Cur;		
		Cur = Cur->next;	
	}	
	return Result;
}


void addEnd(NodePtr& Head, int newdata){
	
	NodePtr last = Head;
	NodePtr newPtr = new Node;
	if(newPtr == NULL){
		cout << "allocation error" << endl;
		exit(1);
	}
	newPtr->data = newdata;
	newPtr->next = NULL;
	if(last != NULL){ 	// general non-empty list case
		while(last->next != NULL) 
			last = last->next;
		last->next = newPtr;
	}
	else	// deal with the case of empty list
		Head = newPtr;
}

//insert item into linked list according to ascending order
void insertNode(NodePtr& Head, int item){	
	NodePtr New, Cur, Pre;	        
	New = new Node;				
	if(New == NULL){
		cout<<"Insufficient Memory"<<endl;
		exit(1);	
	}	
	New->data = item;
	Pre = NULL;
	Cur = Head;	
	while(Cur != NULL && item > Cur->data){
		Pre = Cur;
		Cur = Cur->next;	
	}
	if(Pre == NULL){	//insert to head of linked list
		New->next = Head;
		Head = New;
	} else {		
		Pre->next = New;
		New->next = Cur;
	}
}

void deleteNode(NodePtr& Head, int item){
	NodePtr prev, cur = Head;
	while(cur!=NULL  &&  item > cur->data){
		prev = cur;
		cur = cur->next;
	}
	
	if(cur==NULL || cur->data!=item){
		cout << "Delete error: " << item 
			<< " not in list!" << endl;
		return;
	}
	if(cur==Head)
		Head = Head->next;
	else
		prev->next = cur->next;
	delete cur;
}


void main(){
	NodePtr Head1=NULL, Head2 = NULL;
	
	addHead(Head1, 50);
	addHead(Head1, 40);
	addHead(Head1, 30);
	addHead(Head1, 20);
	delHead(Head1);
	cout << "List 1: " << endl;
	DisplayList(Head1);
	if(searchNode(Head1, 40))
		cout << "40-node exists" << endl;
	else
		cout << "40-node does not exist" << endl;
	if(searchNode(Head1, 25))
		cout << "25-node exists" << endl;
	else
		cout << "25-node does not exist" << endl;
	
	insertNode(Head2, 30);
	insertNode(Head2, 40);
	insertNode(Head2, 10);
	insertNode(Head2, 50);
	insertNode(Head2, 20);
	cout << "List 2: " << endl;
	DisplayList(Head2);
	deleteNode(Head2, 40);
	cout << "List 2 revised: " << endl;
	DisplayList(Head2);
	deleteNode(Head2, 25);
	
}
