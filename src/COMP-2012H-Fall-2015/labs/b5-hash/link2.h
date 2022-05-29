// FILE: link2.h
// PROVIDES: A toolkit of ten template functions for manipulating linked lists.
// Each node of the list contains a piece of data and a pointer to the next
// node, as shown in this template struct:
// 
//     template <class Item>        Item may be any of the C++ built-in types
//     struct Node                  (int, char, etc.), or a class with a default
//     {                            constructor, an assignment operator,
//         Item data;               and a test for equality (x == y).
//         Node *link;
//     };
//
// FUNCTIONS in the linked list toolkit:
//   template <class Item>
//   int list_length(Node<Item>* head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The value returned is the number of nodes in the linked
//     list. The list itself is unaltered.
//
//   template <class Item>
//   void list_head_insert(Node<Item>*& head_ptr, const Item& entry)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: A new node containing the given entry has been added at
//     the head of the linked list; head_ptr now points to the head of the new,
//     longer linked list.
//
//   template <class Item>
//   void list_insert(Node<Item>* previous_ptr, const Item& entry) 
//     Precondition: previous_ptr points to a node in a linked list.
//     Postcondition: A new node containing the given entry has been added
//     after the node that previous_ptr points to.
//
//   template <class Item>
//   Node<Item>* list_search(Node<Item>* head_ptr, const Item& target)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The pointer returned points to the first node containing
//     the specified target in its data member. If there is no such node, the
//     null pointer is returned. The list itself is unaltered.
//
//   template <class Item, class SizeType>
//   Node<Item>* list_locate(Node<Item>* head_ptr, SizeType position)
//     Precondition: head_ptr is the head pointer of a list, and position > 0.
//     Postcondition: The pointer returned points to the node at the specified
//     position in the list. (The head node is position 1, the next node is
//     position 2, and so on). If there is no such position, then the null
//     pointer is returned. The list itself is unaltered.
//
//   template <class Item>
//   void list_head_remove(Node<Item>*& head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list, with at
//     least one node.
//     Postcondition: The head node has been removed and returned to the heap;
//     head_ptr is now the head pointer of the new, shorter linked list.
//
//   template <class Item>
//   void list_remove(Node<Item>* previous_ptr)
//     Precondition: previous_ptr points to a node in a linked list, and this
//     is not the tail node of the list.
//     Postcondition: The node after previous_ptr has been removed.
//
//   template <class Item>
//   void list_clear(Node<Item>*& head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: All nodes of the list have been returned to the heap,
//     and the head_ptr is now NULL.
//
//   template <class Item>
//   void list_copy
//     (Node<Item>* source_ptr, Node<Item>*& head_ptr, Node<Item>*& tail_ptr)
//     Precondition: source_ptr is the head pointer of a linked list.
//     Postcondition: head_ptr and tail_ptr are the head and tail pointers for
//     a new list that that contains the same items as the list pointed to by
//     source_ptr.
//
//   template <class Item>
//   void list_piece
//     (Node<Item>* source_ptr, Node<Item>* end_ptr,
//     Node<Item>*& head_ptr, Node<Item>*& tail_ptr)
//     Precondition: source_ptr and end_ptr are pointers to nodes on the same
//     linked list, with the source_ptr node at or before the end_ptr node.
//     Postcondition: head_ptr and tail_ptr are the head and tail pointers for
//     a new linked list that contains the items from source_ptr to end_ptr.
//     The original list is unaltered.

#ifndef LINK2_H
#define LINK2_H

#include <assert.h>    // Provides assert

template <class Item>
struct Node
{
    Item data;
    Node *link;
};

// FUNCTIONS for the linked list toolkit
template <class Item>
int list_length(Node<Item>* head_ptr);

template <class Item>
void list_head_insert(Node<Item>*& head_ptr, const Item& entry); 

template <class Item>
void list_insert(Node<Item>* previous_ptr, const Item& entry);

template <class Item>
Node<Item>* list_search(Node<Item>* head_ptr, const Item& target);

template <class Item, class SizeType>
Node<Item>* list_locate(Node<Item>* head_ptr, SizeType position);

template <class Item>
void list_head_remove(Node<Item>*& head_ptr);

template <class Item>
void list_remove(Node<Item>* previous_ptr);

template <class Item>
void list_clear(Node<Item>*& head_ptr);

template <class Item>
void list_copy 
  (Node<Item>* source_ptr, Node<Item>*& head_ptr, Node<Item>*& tail_ptr);

template <class Item>
void list_piece
  (Node<Item>*  source_ptr, Node<Item>*  end_ptr,
   Node<Item>*& head_ptr,   Node<Item>*& tail_ptr);

template <class Item>
size_t list_length(Node<Item>* head_ptr)
// Library facilities used: stdlib.h
{
    Node<Item> *cursor;
    size_t answer;

    answer = 0;
    for(cursor = head_ptr; cursor != NULL; cursor = cursor->link)
        answer++;

    return answer;
}

template <class Item>
void list_head_insert(Node<Item>*& head_ptr, const Item& new_item)
{
    Node<Item> *insert_ptr;

    insert_ptr = new Node<Item>;
    insert_ptr->data = new_item;
    insert_ptr->link = head_ptr;
    head_ptr = insert_ptr;
}

template <class Item>
void list_insert(Node<Item>* previous_ptr, const Item& new_item)
{
    Node<Item> *insert_ptr;

    insert_ptr = new Node<Item>;
    insert_ptr->data = new_item;
    insert_ptr->link = previous_ptr->link;
    previous_ptr->link = insert_ptr;
}

template <class Item>
Node<Item>* list_search(Node<Item>* head_ptr, const Item& target)
{
    Node<Item> *cursor;

    for (cursor = head_ptr; cursor != NULL; cursor = cursor->link)
        if (cursor->data == target)
            return cursor;

    return NULL;
}

template <class Item, class SizeType>
Node<Item>* list_locate(Node<Item>* head_ptr, SizeType position)
// Library facilities  assert.h, stdlib.h
{
    Node<Item> *cursor;
    size_t i;

    assert(position > 0);
    
    cursor = head_ptr;
    for(i = 1; (i != position) && (cursor != NULL); i++)
        cursor = cursor->link;
    return cursor;
}

template <class Item>
void list_head_remove(Node<Item>*& head_ptr)
{
    Node<Item> *remove_ptr;

    remove_ptr = head_ptr;
    head_ptr = head_ptr->link;
    delete remove_ptr;
}

template <class Item>
void list_remove(Node<Item>* previous_ptr)
{
    Node<Item> *remove_ptr;

    remove_ptr = previous_ptr->link;
    previous_ptr->link = remove_ptr->link;
    delete remove_ptr;
}

template <class Item>
void list_clear(Node<Item>*& head_ptr)
// Library facilities used: stdlib.h
{
    while (head_ptr != NULL)
        list_head_remove(head_ptr);
}

template <class Item>
void list_copy
(Node<Item>* source_ptr, Node<Item>*& head_ptr, Node<Item>*& tail_ptr)
// Library facilities used: stdlib.h
{
    head_ptr = NULL;
    tail_ptr = NULL;

    // Handle the case of the empty list
    if (source_ptr == NULL)
        return;

    // Make the head node for the newly created list, and put data in it
    list_head_insert(head_ptr, source_ptr->data);
    tail_ptr = head_ptr;

    // Copy the rest of the nodes one at a time, adding at the tail of new list
    for (source_ptr = source_ptr->link; source_ptr != NULL; source_ptr = source_ptr->link)
    {
        list_insert(tail_ptr, source_ptr->data);
        tail_ptr = tail_ptr->link;
    }
}

template <class Item>
void list_piece
(Node<Item>* start_ptr, Node<Item>* end_ptr, Node<Item>*& head_ptr, Node<Item>*& tail_ptr)
// Library facilities used: assert.h, stdlib.h
{
    head_ptr = NULL;
    tail_ptr = NULL;

    // Handle the case of the empty list
    if (start_ptr == NULL)
        return;
    
    // Make the head node for the newly created list, and put data in it
    list_head_insert(head_ptr, start_ptr->data);
    tail_ptr = head_ptr;
    if (start_ptr == end_ptr)
        return;
    
    // Copy the rest of the nodes one at a time, adding at the tail of new list
    for (start_ptr = start_ptr->link; start_ptr != NULL; start_ptr = start_ptr->link)
    {
        list_insert(tail_ptr, start_ptr->data);
        tail_ptr = tail_ptr->link;
        if (start_ptr == end_ptr) 
            return;
    }
}

#endif
