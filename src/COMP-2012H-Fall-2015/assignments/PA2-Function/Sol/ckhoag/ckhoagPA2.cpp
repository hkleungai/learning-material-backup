#include <iostream>
#include <algorithm>
using namespace std;

//Sort the first 'size' elements in the array, ascendingly
void sort(char (&array)[10], int size) {
	char temp;

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - 1; j++) {
			if (array[j + 1] < array[j]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}

}

void reverse(char (&array)[10], int start, int end) {
	char temp[10];
	int i = start;
	int j = end;
	while (i <= end) {
		temp[j] = array[i];
		i++;
		j--;
	}
	for (int i = start; i <= end; i++) {
		array[i] = temp[i];
	}

}

//This function returns true if there exist a next permutation, and print it out,
//return false if no next permutation (It's already the last one)
bool printNextPerm(char (&array)[10], int numOfElements) {

	//No next perm if numOfElements is one
	if (numOfElements == 1) {
		return false;
	}
	//Checking if it's already the last permutation
	int flag = 1;
	for (int i = 1; i < numOfElements; i++) {
		if (array[i-1] < array[i]) {
			flag = 0;  // There exist array[i-1] < array[i]
			break;
		}
	}
	if (flag == 1) {
		return false;
	}

	int index1 = 1; //index1 MUST BE at least 1, IN ALL CASES
	int index2 = numOfElements - 1;
	//Generating index1, Note: Assume numOfElements at least 2, so i starts from 1
	//Starting from the front
	for (int i = 1; i < numOfElements; i++) {
		if (array[i - 1] < array[i]) {
			index1 = i;
		}
	}

	//Generating index2, starting from the back
	for (int j = (numOfElements - 1); j >= index1; j--) {
		if (array[j] > array[index1 - 1]) {
			index2 = j;
			break;
		}
	}
	//Swapping array [index2] and array[index1-1]

	char temp;
	temp = array[index2];
	array[index2] = array[index1 - 1];
	array[index1 - 1] = temp;

	//Finally reverse the elements from array[index1] till array[numOfElements-1]
	reverse(array, index1, numOfElements - 1);

	//Print out the new permutation
	for (int i = 0; i < numOfElements; i++) {
		cout << array[i];
	}
	cout << endl;

	return true;
}

int main() {
	do {
		char again;
		///////////////////////////////////////////////////////////////
		int MAX_ELEMENTS = 10;
		char characters[10];
		cout << "Please input array size (1-10): " << endl;
		cin >> MAX_ELEMENTS;
		cout << "Please input array elements:" << endl;
		for (int i = 0; i < MAX_ELEMENTS; i++) {
			cin >> characters[i];
		}
		//sort the array first
		sort(characters, MAX_ELEMENTS);

		cout << "The permutations are:" << endl;
		//Print out the first perm
		for (int i = 0; i < MAX_ELEMENTS; i++) {
			cout << characters[i];
		}
		cout << endl;

		while (printNextPerm(characters, MAX_ELEMENTS)){

		}

		cout << "Continue to use this program? (C/c to continue)" << endl;
		cin >> again;

		////////////////////////////////////////////////////////////////////////
		if (again == 'C' || again == 'c') {
			continue;
		} else {
			break;
		}
	} while (true);
	return 0;
}
