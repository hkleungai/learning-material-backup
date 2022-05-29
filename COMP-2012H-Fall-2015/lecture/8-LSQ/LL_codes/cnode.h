// file cnode.h

#ifndef ChainNode_
#define ChainNode_

template <class T> class Chain;
template <class T> class ChainIterator;
template <class T> class KeyedChain;
template <class T> class LinkedStack;

template <class T>
class ChainNode {
  friend class Chain<T>;
  friend class ChainIterator<T>;
  friend class KeyedChain<T>;
  friend class LinkedStack<T>;
 private:
  T data;
  ChainNode<T> *link;
};

#endif
