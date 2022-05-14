#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

bool stackIsEmpty(Node* pHead);
void pushStack(Node* &pHead, int item);
Node* popStack(Node* &pHead);
Node* searchStack(Node *pHead, int item);
void printStack(Node* pHead);

void main(){
	Node *pHead = NULL;
	
	pushStack(pHead, 3);
	pushStack(pHead, 1);
	pushStack(pHead, -5);
	pushStack(pHead, 7);

	printStack(pHead);

	popStack(pHead);
	printStack(pHead);

	popStack(pHead);
	printStack(pHead);

	popStack(pHead);
	printStack(pHead);

	popStack(pHead);
	printStack(pHead);
}

bool stackIsEmpty(Node* pHead){
	return (pHead == NULL);
}

void pushStack(Node* &pHead, int item){
	Node* pNew;
	pNew = new Node;
	if(pNew == NULL){
		cout << "Failed at Memory Allocation" << endl;
		return;
	}
	pNew->data = item;	
	pNew->next = pHead;
	pHead = pNew;
}

Node* popStack(Node* &pHead){
	Node* pCur = NULL;
	if(!stackIsEmpty(pHead)){
		pCur = pHead;
		pHead = pHead -> next;
	}	
	return pCur;		
}

void printStack(Node *pHead){
	Node* pCur = pHead;
	while(pCur != NULL){
		cout << pCur->data << " ";
		pCur = pCur->next;
	}
	cout << endl;
}

Node* searchStack(Node *pHead, int item) {
	Node *pCur = pHead;
	while(pCur != NULL){
		if(pCur->data == item)
			break;
		pCur = pCur->next;
	}
	return pCur;
}
