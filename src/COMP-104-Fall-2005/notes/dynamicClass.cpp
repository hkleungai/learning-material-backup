#include <iostream>
using namespace std;

struct Node{	 
public:
	int data;	
	Node *next;
};
typedef Node* Nodeptr;

class listClass{
public:
	listClass();                   // constructor
	listClass(const listClass& list1); // copy constructor
	~listClass();                  // destructor
	
	bool empty() const;            // boolean function
	int headElement() const;       // access functions
	
	void addHead(int newdata);     // add to the head
	void delHead();                // delete the head
	
	int length() const;           // utility function
	void print() const;           // output
	
private:
	Nodeptr Head;
};


listClass::listClass(){
	Head = NULL;
}

bool listClass::empty() const{
	if(Head==NULL)
		return true;
	else
		return false;
}

int listClass::headElement() const {
	if(Head != NULL) 
		return Head->data;
	else{
		cout << "error: trying to find head of empty list" << endl;
		return -999999;
	}
}

listClass::~listClass(){
	Nodeptr cur;
	while(Head!=NULL){
		cur = Head;
		Head = Head->next;
		delete cur;
	}
}

void listClass::addHead(int newdata){
	
	Nodeptr newPtr = new Node;
	newPtr->data = newdata;
	newPtr->next = Head;
	Head = newPtr;
}

void listClass::delHead(){
	if(Head != NULL){
		Nodeptr cur = Head;
		Head = Head->next;
		delete cur;
	}
}

listClass::listClass(const listClass& list1) {
	Head = NULL;
	Nodeptr cur = list1.Head;
	while(cur != NULL) {
		// addEnd(cur->data);  
		addHead(cur->data); // inverse list order
		cur = cur->next;
    }
	
}

void listClass::print() const{
	cout << "{ ";
	Nodeptr cur = Head;
	while(cur != NULL){
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << "}" << endl;
}

int listClass::length() const{
	
	int n=0;
	Nodeptr cur = Head;
	while(cur != NULL){
		n++;
		cur = cur->next;
	}
	return n;
}



void main(){
	listClass L;	   // constructor called automatically here for L
	L.print();                
	L.addHead(30);
	L.print();                   
	L.addHead(13);
	L.print();                    
	L.addHead(40);
	L.print();                  
	L.addHead(50);
	L.print();                   
	listClass N(L);
	N.print();                   

	listClass R;
	R.print();                  
	if(R.empty())
		cout << "List R empty" << endl;
	L.delHead();
	L.print();                  
	L.delHead();
	L.print();                   
	if(L.empty())
		cout << "List L empty" << endl;
	else{
		cout << "List L contains " << L.length() << " nodes" << endl;
		cout << "Head element of list L is: " << L.headElement() << endl;
	}
}			   // destructor called automatically here for L
