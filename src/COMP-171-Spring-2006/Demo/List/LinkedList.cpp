#include "LinkedList.h"

int Node::getData() {
   return data;
}

void Node::setData(int newData) {
   data=newData;
}

Node *Node::getNext() {
   return next;
}

void Node::setNext(Node *newNext) {
   next=newNext;
}

// true == okay
// Always insert at the end of the list
bool LinkedList::append(int number) {
   Node *current, *previous, *node;

   if ((node=new Node()) == NULL)  // cannot allocate new memory
      return false;
      
   node->setData(number);
   
   current=head;     // initialized settings for pointers to iterate
   previous=NULL;    // the linked list
   
   while (current != NULL) {
      previous=current;
      current=current->getNext();
   }
   
   if (previous == NULL) {
      node->setNext(head);
      head=node;
   } else {
      previous->setNext(node);
      node->setNext(current);
   }
   
   return true;
   
}

// true == okay
// if index <= 0, indicate insert in the beginning
bool LinkedList::insert(int index, int number) {
   Node *current, *previous, *node;
   
   if (getSize() < index)  // cannot insert a node which is out of boundary
      return false;
   
   if ((node=new Node()) == NULL)  // cannot allocate new memory
      return false;     
   
   node->setData(number);
   
   current=head;     // initialized settings for pointers to iterate
   previous=NULL;    // the linked list
   
   while (index > 0) {
      previous=current;
      current=current->getNext();
      index--;
   }
   
   if (previous == NULL) {
      node->setNext(head);
      head=node;
   } else {
      previous->setNext(node);
      node->setNext(current);
   }
   
   return true;
}

int LinkedList::getSize() {
   Node *current;
   int count=0;
   
   current=head;
   while (current != NULL) {
      count++;
      current=current->getNext();
   }
   
   return count;
}

// return -1 == no found, otherwise, the index of the list
int LinkedList::search(int number) {
   Node *current;
   int index;
   
   index=0;
   current=head;
   while (current != NULL) {
      if (current->getData() == number)
         return index;
      index++;
      current=current->getNext();
   }
   
   return -1;
}

bool LinkedList::remove(int index) {
   Node *current, *previous, *node;
   
   if (getSize() <= index  // cannot delete a node which is out of boundary
         ||
       index < 0)
      return false;

   current=head;
   previous=NULL;
   while (index > 0) {
      previous=current;
      current=current->getNext();
      index--;
   }
   
   if (previous == NULL)
      head=current->getNext();
   else
      previous->setNext(current->getNext());
   
   delete current;
   
   return true;
}

void LinkedList::display() {
   Node *current;
   
   current=head;
   while (current != NULL) {
      cout << current->getData() << " ";
      current=current->getNext();
   }
   cout << endl;
}

LinkedList::~LinkedList() {
   for (int i=0, size=getSize(); i < size; i++)
      remove(0);
}

int main() {
   LinkedList *list=new LinkedList();
   
   list->append(1);
   list->append(2);
   list->append(3);
   list->append(4);
   list->display();
   
   list->insert(1,100);
   list->insert(3,100);
   list->display();
   
   if (list->search(3) >= 0)
      cout << "3 is found!" << endl;
   if (list->search(1010) >= 0)
      cout << "1010 is found!" << endl;
   
   list->remove(0);
   list->remove(3);
   list->display();
   
   return 0;
}