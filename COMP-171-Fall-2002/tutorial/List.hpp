//-----------------------------------
//			List Node				
//-----------------------------------
template<class T>
class Node{
	public:
		Node();
		T getKey() const;
		void setKey(T k);
		Node<T> * getNext() const;
		void setNext(Node * n);
	private:
		T key;
		Node<T> * Next;
};

template<class T>
Node<T>::Node(){
	Next = NULL;
}

template<class T>
T Node<T>::getKey() const{
	return key;
}

template<class T>
void Node<T>::setKey(T k){
	key = k;
}

template<class T>
Node<T> * Node<T>::getNext() const{
	return Next;
}

template<class T>
void Node<T>::setNext(Node * n){
	Next = n;
}

//-----------------------------------
//			List			
//-----------------------------------
template<class T>
class List{
	public:
		List();
		int findKey(T k) const;
		int addKey(T k);
		int removeKey(T k);
		void printList() const;
	private:
		Node<T> *root;
};

template<class T>
List<T>::List(){
	root = NULL;
}

// return 1 if k is found else return 0
template<class T>
int List<T>::findKey(T k) const{
	Node<T> * ptr1;
	ptr1 = root;
	while (ptr1 != NULL){
		if (ptr1->getKey() == k)
			return 1;
		else
			ptr1 = ptr1->getNext();
	}
	return 0;
}

template<class T>
int List<T>::addKey(T k){
	// check if it exists
	if (findKey(k)){
		return 0;
	}
	// create new node
	Node<T> *newNode;
	newNode = new Node<T>;
	newNode->setKey(k);
	// find the pos
	Node<T> *ptr1, *ptr2;
	ptr1 = ptr2 = root;
	while (ptr1 != NULL && ptr1->getKey() < k){
		ptr2 = ptr1;
		ptr1 = ptr1->getNext();
	}
	// insert it
	if (ptr1 == root){
		newNode->setNext(root);
		root = newNode;
		return 1;
	}
	newNode->setNext(ptr1);
	ptr2->setNext(newNode);
	return 1;
};

template<class T>
int List<T>::removeKey(T k){
	// check if it exists
	if (findKey(k) != 1){
		return 0;
	}
	// find the pos
	Node<T> *ptr1, *ptr2, *rNode;
	ptr1 = ptr2 = root;
	while (ptr1 != NULL && ptr1->getKey() != k){
		ptr2 = ptr1;
		ptr1 = ptr1->getNext();
	}
	// remove it
	if (ptr1 == root){
		rNode = root;
		root = root->getNext();
		delete rNode;
		return 1;
	}
	rNode = ptr1;
	ptr2->setNext(ptr1->getNext());
	delete rNode;
	return 1;
};

template<class T>
void List<T>::printList() const{
	Node<T> * ptr1;
	ptr1 = root;
	while (ptr1 != NULL){
		cout << ptr1->getKey() << "=> ";
		ptr1 = ptr1->getNext();
	}
	cout << "NULL" << endl;
};
