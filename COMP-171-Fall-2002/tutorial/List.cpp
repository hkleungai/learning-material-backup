#include <iostream>
#include "List.hpp"

int main(){
	List<int> IntList;
	IntList.addKey(2);
	IntList.printList();
	IntList.addKey(1);
	IntList.printList();
	IntList.addKey(3);
	IntList.printList();
	IntList.removeKey(4);
	IntList.printList();
	IntList.removeKey(3);
	IntList.printList();
}