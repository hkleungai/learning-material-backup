// FILE: table2.h
// TEMPLATE CLASS PROVIDED: Table<RecordType>
//   This class is a container template class for a Table of records.
//   The template parameter, RecordType, is the data type of the records in the
//   Table. It may any type with a default constructor, a copy constructor,
//   an assignment operator, and an integer member variable called key.

#ifndef TABLE1_H
#define TABLE1_H

#include "link2.h"
#include <assert.h> // Provides assert

template <class RecordType>
class Table
{
public:
    // MEMBER CONSTANT
    enum { TABLE_SIZE = 811 }; // Or: static const int TABLE_SIZE = 811;
    // CONSTRUCTORS and DESTRUCTOR
    Table( );
    Table(const Table& source);
    ~Table( );
    // MODIFICATION MEMBER FUNCTIONS
    void insert(const RecordType& entry);
    void remove(int key);
    void operator =(const Table& source);
    // CONSTANT MEMBER FUNCTIONS
    void find(int key, bool& found, RecordType& result) const;
    bool is_present(int key) const;
    int size( ) const { return total_records; }
private:
    Node<RecordType> *data[TABLE_SIZE];
    int total_records;
    // HELPER FUNCTION
    int hash(int key) const;
    Node<RecordType>* find_node(int key) const;
};

// constructor
template <class RecordType>
Table<RecordType>::Table( )
{
    total_records = 0;
    for (int i = 0; i < TABLE_SIZE; i++)
        data[i] = NULL;
}

// copy constructor
template <class RecordType>
Table<RecordType>::Table(const Table<RecordType>& source) 
{
    Node<RecordType>* tail_ptr; // Needed for list_copy

    for (int i = 0; i < TABLE_SIZE; i++)
        list_copy(source.data[i], data[i], tail_ptr);
    total_records = source.total_records;
}

// destructor
template <class RecordType>
Table<RecordType>::~Table( )
{
    total_records = 0;
    for (int i = 0; i < TABLE_SIZE; i++)
        list_clear(data[i]);
}

// If the table already had a record with a key equal to
// entry.key, then that record is replaced by entry. Otherwise, entry has
// been added as a new record of the Table.
template <class RecordType>
void Table<RecordType>::insert(const RecordType& entry)
{
    Node<RecordType>* cursor; // set to point to existing Node with given key

    assert(entry.key >= 0);

	// ===== TO-DO =====
	//
	// set cursor to point to existing Node with given key (if there is one)
	// if the node already exists, replace it by entry
	// else append it to the head of the list at the corresponding Node
	// and update total_records
}

// If a record was in the Table with the specified key, then
// that record has been removed; otherwise the table is unchanged.
template <class RecordType>
void Table<RecordType>::remove(int key)
{
    Node<RecordType> *cursor;    // Points to existing Node with given key
    Node<RecordType> *precursor = NULL; // Points to node before the cursor

    assert(key >= 0);

	// ===== TO-DO =====
	//
    // set cursor to point to existing Node with given key (if there is one)
	// look for the key until cursor is NULL (not found)
	// or the key is hit (found)
	//
	// in case of found
    // if curosr points to head, remove head
	// otherwise remove the cursor node
	// update total_records
}

// assignment operator
template <class RecordType>
void Table<RecordType>::operator =(const Table<RecordType>& source) 
{
    int i;
    Node<RecordType>* tail_ptr; // Needed for list_copy

    if (this == &source)
        return; // Avoid self-assignment

    for (i = 0; i < TABLE_SIZE; i++)
    {
	list_clear(data[i]);
        list_copy(source.data[i], data[i], tail_ptr);
    }
    total_records = source.total_records;
}

// The return value is true if there is a record in the
// Table with the specified key. Otherwise, the return value is false.
template <class RecordType>
bool Table<RecordType>::is_present(int key) const
{
    assert(key >= 0);
    return (find_node(key) != NULL);
}

// If a record is in the Table with the specified key, then
// found is true and result is set to a copy of the record with that key.
// Otherwise found is false and the result contains garbage.
template <class RecordType>
void Table<RecordType>::find(int key, bool& found, RecordType& result) const
{
    Node<RecordType> *cursor;

    cursor = find_node(key);
    found = (cursor != NULL);
    if (found)
        result = cursor->data;
}

// hash function
template <class RecordType>
int Table<RecordType>::hash(int key) const
{
    return (key % TABLE_SIZE);
}

// The return value is a pointer to the record with the
// specified key (if there is one). If there is no such node, the return value
// is the NULL pointer.
template <class RecordType>
Node<RecordType>* Table<RecordType>::find_node(int key) const
{ 
    Node<RecordType>* cursor = NULL;

	// ===== TO-DO =====
	//
	// locate the value with the hash function
	// and search through the list attached
	// return NULL pointer if not found

    return cursor;
}

#endif
