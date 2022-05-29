#include <iostream>
#include <string>
#include "list.h"

using namespace std;



int main() {
	//List list;
	List<string> list;
	//List list;

	// insert some sample data to the list
	list.Add("a");
	list.Add("g");
	list.Add("e");
	list.Add("d");
	list.Add("c");
	list.Add("h");
	list.Add("b");
	list.Add("f");

	std::cout << "Orginal: " << endl;
	list.Print();

	list.Reversal();
	std::cout << "Reversed: " << endl;
	list.Print();

	list.Reversal();
	std::cout << "Reverse again: " << endl;
	list.Print();

	string str;
	std::cout << "Enter the item you want to find: ";
	std::cin>> str;
	std::cout <<list.Find(str)<<endl;

	return 0;
};
