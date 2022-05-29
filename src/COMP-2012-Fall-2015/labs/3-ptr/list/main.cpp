#include <iostream>
#include <fstream>
#include <string>
#include "List.h"
#include <stdlib.h>
using namespace std;

#define STATION_FILE "station.txt"

NodePtr InitList() {
	NodePtr head = NULL;
	ifstream fin(STATION_FILE);
	if (!fin) {
		cerr << "error: unable to open input file " << STATION_FILE << "\n";
		exit(-1);
	}

	int intNum;
	fin >> intNum;

	for (int i = 0; i<intNum; i++)
	{
		string temp;
		fin >> temp;
		if (!Insert(head, temp))
		{
			cout << "Some error in input file " << STATION_FILE << "\n";
			exit(-1);
		}
	}
	return head;
}

int main()
{
	string strStation1, strStation2;
	int intCost;
	NodePtr list = NULL;
	list = InitList();

	cout << "Input the names of the two stations for finding the distance in between (in term of station)\n";
	cout << "Type q to exit \n\n";
	while (true) {
		intCost = -1;

		Print(list);
		cout << "Station1 > ";
		cin >> strStation1;

		//Exit
		if (strStation1 == "q" || strStation1 == "Q")
			break;

		cout << "Station2 > ";
		cin >> strStation2;

		intCost = FindDistance(list, strStation1, strStation2);
		if (intCost != -1) {
			cout << "Distance: " << intCost << "\n\n";
		}
		else {
			cout << "No such station !\n\n";
		}
	}
	deleteList(list);
	return 0;
}
