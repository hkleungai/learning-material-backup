#include <iostream>
using namespace std;

class listNode{				// a node on the list
	public:
		int data;			// a data item on the list
		listNode *next;		// pointer to next node
};
typedef listNode* ptrType;	// pointer to node


class listClass {
	public:
		// constructors and destructor:
		listClass();
		listClass(const listClass& L);
		~listClass();

		// list operations:
		bool empty();
		int length();
		void add(int newdata);
		void del(int deldata);
		void print();
	private:
		int Size; 
		ptrType Head;
		ptrType new_and_check();  // "new and check"
};


ptrType listClass::new_and_check() {
// allocate a new node; returns only upon successful memory allocation
// else, exit
	ptrType temp;
	temp = new listNode;
	if (temp == NULL) { // not successful
		cerr << "Memory allocation error!" << endl;
		exit(1);
	}
	return temp;
}

listClass::listClass(){
	Size = 0;
	Head = NULL;
}

listClass::listClass(const listClass& L){
	Size = L.Size;
	if(L.Head==NULL){
		Head = NULL;	// original list is empty
		return;
	}
	// copy first node
	Head = new_and_check();
	Head->data = L.Head->data;

	// copy rest of list
	ptrType cur = Head;	// new list pointer
	ptrType orig = L.Head->next;
	while(orig != NULL){
		cur->next = new_and_check ();
		cur = cur->next;
		cur->data = orig->data;
		orig = orig->next;
	}
	cur->next = NULL;
}

listClass::~listClass(){
	while(Head!=NULL){
		ptrType cur = Head;
		Head = Head->next;
		delete cur;
	}
}

bool listClass::empty(){
	if(Size==0)
		return true;
	else
		return false;
}

int listClass::length(){
	return Size;
}

void listClass::add(int newdata){
	Size++;
	ptrType newPtr = new_and_check ();
	newPtr->data = newdata;
	newPtr->next = NULL;
	ptrType prev, cur = Head;
	while(cur!=NULL  &&  newdata > cur->data){
		prev = cur;
		cur = cur->next;
	}
	if(cur==Head){
		newPtr->next = Head;  
		Head = newPtr;
	}
	else{
		newPtr->next = cur;
		prev->next = newPtr;
	}
}

void listClass::del(int deldata){
	ptrType prev, cur = Head;
	while(cur!=NULL  &&  deldata > cur->data){
		prev = cur;
		cur = cur->next;
	}
	if(cur==NULL || cur->data!=deldata){
		cout << "Delete error: " << deldata << " not in list!" << endl;
		return;
	}
	if(cur==Head)
		Head = Head->next;
	else
		prev->next = cur->next;
	delete cur;
	Size--;
}

void listClass::print(){
	cout << "[ ";
	ptrType cur = Head;
	while(cur != NULL){
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << "]" << endl;
}




void main(){
	listClass L;
	L.add(30);
	L.print();
	listClass N(L);
	N.print();
	L.add(20);
	L.print();
	L.add(40);
	L.print();
	L.add(10);
	L.print();
	L.del(50);
	L.print();
	L.del(40);
	L.print();
	L.del(30);
	L.print();
	L.del(20);
	L.print();
	L.del(10);
	L.print();
}
