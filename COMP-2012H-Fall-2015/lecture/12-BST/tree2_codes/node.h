
#ifndef Node_
#define Node_

template <class T> class LinkedStack;
template <class T> class LinkedQueue;

template <class T>
class Node {
  friend class LinkedStack<T>;
  friend class LinkedQueue<T>;
 private:
  T data;
  Node<T> *link;
};

#endif
