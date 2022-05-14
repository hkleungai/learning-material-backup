#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

struct Node{
        int data;
        Node* next;
        Node* prev;
};
typedef Node* NodePtr;

void createHead(NodePtr& Head){
	Head = new Node;
	Head->next = Head;
	Head->prev = Head;
}

NodePtr searchNode(NodePtr Head, int item){
	NodePtr Cur = Head->next;
	while(Cur != Head){
		if(Cur->data == item)
			return Cur;
		if(Cur->data < item)
			Cur = Cur->next;
		else
			break;
	}
	return NULL;
}

void deleteNode(NodePtr Head, int item){
	NodePtr Cur;
	Cur = searchNode(Head, item);
	if(Cur != NULL){
		Cur->prev->next = Cur->next;
		Cur->next->prev = Cur->prev;
		delete Cur;
	}
}       

void insertNode(NodePtr Head, int item){ 
	NodePtr New, Cur;                        
	New = new Node;
	New->data = item;
        
	Cur = Head->next;
	while(Cur != Head){	//position Cur for insertion 
		if(Cur->data < item)
			Cur = Cur->next;
		else    
			break;
	}
	New->next = Cur;
	New->prev = Cur->prev;
	Cur->prev = New;
	(New->prev)->next = New;
}

void print(NodePtr Head){   
	NodePtr Cur=Head->next;
	while(Cur != Head){
		cout << Cur->data << " ";
		Cur = Cur->next;
	}
	cout << endl;
}

void main(){
	NodePtr Head, temp;
        
	createHead(Head);
	print(Head);
	insertNode(Head, 3);
	print(Head);
	insertNode(Head, 5);   
	print(Head);
	insertNode(Head, 2);
	print(Head);
	insertNode(Head, 7);
	insertNode(Head, 1);
	insertNode(Head, 8);
	print(Head);
	deleteNode(Head, 7);
	deleteNode(Head, 0);
	print(Head);
	temp = searchNode(Head, 5);
	if(temp != NULL)
		cout << "Data is contained in the list" << endl;
	else
		cout << "Data is NOT contained in the list" << endl;
}

