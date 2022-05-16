#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
   private:
      int data;
      Node *next;
   public:
      Node(): data(0), next(NULL) {}
      int getData();
      void setData(int newData);
      Node *getNext();
      void setNext(Node *newNext);
};

class LinkedList {
   private:
      Node *head;
   public:
      LinkedList(): head(NULL) {}
      ~LinkedList();
      bool append(int number);
      bool insert(int index, int number);
      int getSize();
      int search(int number);
      bool remove(int index);
      void display();
};

#endif
