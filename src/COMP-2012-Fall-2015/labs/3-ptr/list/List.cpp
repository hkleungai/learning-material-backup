#include "List.h"

void deleteList(NodePtr& m_Head)
{
	NodePtr ptrTemp;
	while (m_Head != NULL)
	{
		ptrTemp = m_Head;
		m_Head = m_Head->ptrNext;
		delete ptrTemp;
	}
}


void Print(NodePtr m_Head)
{
	NodePtr ptrTemp = m_Head;
	// add the code to print the node str 
	//



    	cout << "NIL" << endl;
}

int FindDistance(NodePtr m_Head, string str1, string str2)
{
	if (m_Head == NULL)		// empty list
		return -1;
	else {
                if (str1 == str2) {
                	return 0;
 		}
		else {

            	  // To add some code here
		  //




		}
		return -1;
	}
}

bool Insert(NodePtr& m_Head, string str)
{
	if (str == "q") {
		cerr << "invalid string\n";
		return false;
	}

	if (m_Head == NULL) {	// empty list
		m_Head = new Node;
		m_Head->str = str;
		m_Head->ptrNext = NULL;
	}
	else {
		//Create new node
		NodePtr ptrNew = new Node;
		ptrNew->str = str;
		ptrNew->ptrNext = NULL;

		NodePtr ptrTemp = m_Head;
		while (ptrTemp->ptrNext != NULL)
		{
			if (ptrTemp->str == str)	// discard duplicated node
				return false;
			ptrTemp = ptrTemp->ptrNext;
		}
		if (ptrTemp->str == str)	// checking the last node
			return false;

		//Append to last
		ptrTemp->ptrNext = ptrNew;
	}
	return true;
}
