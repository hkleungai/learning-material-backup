#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::left;

#include <iomanip>
using std::setw;

#include <iterator>
using std::begin;
using std::end;

#include <algorithm>
using std::random_shuffle;
using std::swap;

#include <random>
using std::default_random_engine;

#include <chrono>
using std::chrono::system_clock;

int grid[3][3];
const int MAX_WIDTH = 7;

void display() {
	cout << "\n\n";
	cout << left;
	cout << "  | "; 
	for(int i = 0; i < 3; i++) {
		cout << setw(MAX_WIDTH) << i;
	}
	cout << endl;

	cout << "--+-------------------" << endl;
	for(int i = 0; i < 3; i++) {
		cout << (char)('A' + i) << " | ";
		for(int j = 0; j < 3; j++) {
			cout << setw(MAX_WIDTH) << grid[i][j];
		}
		cout << "\n  |\n";
	}
}

void generate_for_demo() {
	grid[0][0]=2;grid[0][1]=3;grid[0][2]=0;
	grid[1][0]=1;grid[1][1]=4;grid[1][2]=5;
	grid[2][0]=7;grid[2][1]=8;grid[2][2]=6;
}

void generate() {
	int temp[9] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
	unsigned int num_reverse_pair = 0;

	do {
		num_reverse_pair = 0;

		unsigned int seed = system_clock::now().time_since_epoch().count();
		shuffle(begin(temp), end(temp), default_random_engine(seed)); // Array Size of 9.

		// Ignore the empty cell 0.
		for (int i = 0; i < 8; ++i) {
			if (temp[i] == 0) {
				continue;
			}

			for (int j = i + 1; j < 9; ++j) {
				if (temp[j] == 0) {
					continue;
				}

				if (temp[i] > temp[j]) {
					num_reverse_pair += 1;
				}
			}
		}
	} while (((num_reverse_pair % 2) != 0) || (num_reverse_pair == 0)); // Repeat until non-zero even-number of reverse pairs.
    
	for (int i = 0; i < 9; i++) {
		grid[i/3][i%3] = temp[i];
	}
}

int check(char row, int col) {
	int rowNum = row - 'A';

	if ((rowNum < 0) || (rowNum > 2) || (col < 0) || (col > 2)) {
		return -1;
	}

	// Ordering is important when checking for the empty cell.
	if (grid[rowNum][col] == 0) {
		return 0;
	}

	// This would also return 1 for the empty cell, so it is important to check for the empty cell beforehand.
	for (int i = 0; i < 3; ++i) {
		if ((grid[rowNum][i] == 0) || (grid[i][col] == 0)) {
			return 1;
		}
	}

	return 0;
}

void operate(char row, int col) {
	int rowNum = row - 'A';

	// Find the empty cell.
	int row0, col0;
	for (int i = 0; i < 9; i++) {
		if (grid[i/3][i%3] == 0) {
			row0 = i/3;
			col0 = i%3;
			break;
		}
	}

	// Swap with the empty cell. If there is a middle cell, swap again with it.
	swap(grid[rowNum][col], grid[row0][col0]);
	if (rowNum == row0) {
		if (((col - col0) == 2) || ((col0 - col) == 2)) {
			swap(grid[row0][col0], grid[row0][1]);
		}
	}
	else {
		if (((rowNum - row0) == 2) || ((row0 - rowNum) == 2)) {
			swap(grid[row0][col0], grid[1][col0]);
		}
	}
}

bool win() {
	for (int i = 0; i < 8; i++) {
		if (grid[i/3][i%3] != i + 1) {
			return false;
		}
	}
	return true;
}

// Game Loop.
int main() {
	generate();

	while(!win()) {
		display();

		cout << "Which cell do you want to click?" << endl;

		char row;
		int col;
		cin >> row >> col;

		int ok = check(row, col);

		switch (ok) {
			case 0:
				cout << "This cell can't be clicked!" << endl;
				break;

			case 1:
				operate(row, col);
				break;

			case -1:
				cout << "Invalid input!" << endl;
				break;

			default:
				break;
		}
	}

	display();
	cout << "Nice!" << endl;
}
