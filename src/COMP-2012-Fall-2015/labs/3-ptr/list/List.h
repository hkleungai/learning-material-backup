#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
using namespace std;

typedef struct Node {
		string str;
		Node* ptrNext;
} *NodePtr;

void deleteList(NodePtr& m_Head);	
void Print(NodePtr m_Head);
bool Insert(NodePtr& m_Head, string str);

//ToDo:  implement this function to return the number of nodes between two stations
// return -1 when cannot find the distance between str1 and str2
int FindDistance(NodePtr m_Head, string str1, string str2);


#endif
