/*	This program outputs all the non-identical permutations
 * 	of a given array of characters.
 * 	Author:	LIU, Xin
 * 	e-mail:	xliubl@ust.hk
 */

//preprocessing statements
#include <iostream>
using namespace std;
#define MAX_ELEMENTS 10

//function prototypes
void asksize(int& size);
void swap(char&, char&);
bool check(char*, int, int);
void permutation(char*, int, int);

//the main function
int main() {
	char array[MAX_ELEMENTS];
	int size;
	asksize(size);
	cout << "Please input array elements: ";
	for (int k = 0; k < size; k++)
		cin >> array[k];
	permutation(array, 0, size-1);
	return 0;
}

//function definition

//ask the size of the array
void asksize(int& size)	{
	int temp;
	cout << "Please input array size (1-10): ";
		cin >> temp;
		if (temp <= 10 || temp >= 1)
			size = temp;
		else asksize(size);
}

//swap two elements of the array
void swap(char& first, char& second) {
	char temp = first;
	first = second;
	second = temp;
}

//check whether the element being swapped is duplicated or not
bool check(char* array, int start, int index) {
	for (; start < index; start++)
		if (array[index] == array[start])
			return false;
	return true;
}

//permutation
void permutation(char* array, int start, int end) {
	// parameter:	start & end:
	//				permutate array[start : end]

	// if start == end, one instance of permutation is generated
	// print
	if (start == end) {
		for (int i = 0; i <= end; i++)
			cout << array[i] << " ";
		cout << endl;
	}
	// if start != end, continue recursion
	else {
		// define a looping index j, every time permutation
		// is executed
		int index = start;
		do {
			// if the swapping elements are duplicated,
			// then continuing permutation process is meaningless
			// unless the indices of the two are the same
			if (check(array, start, index)) {
				swap(array[start], array[index]);
				permutation(array, start+1, end);
				swap(array[start], array[index]);
			}
			// swap between start and j has been finished
			// increment j by one and continue swapping
			index++;
		}
		// check whether j has reached the end
		while (index <= end);
	}
}
