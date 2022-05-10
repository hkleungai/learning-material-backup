// Titanic Maze Game (initial version)
#include <cstdlib>
#include <iostream>
#include <ctype.h>
#include <conio.h>
#include <time.h>
using namespace std;

// NO_COLS and NO_ROWS determine the size of the field
const int NO_COLS = 16;
const int NO_ROWS = 8;

// The function 'offboard' is used to check if positin is off the board
bool offboard(int row, int col);

// Print the field, with the Titanic at (row, col) and the iceberg at (irow, icol)
void print_field(int row, int col, int irow, int icol);

// This function clears the screen
void clear_screen()
{
  cout << char(27) << "[2J";
}

// This function makes the cursor go back to the top left position(home)
void home_cursor()
{
  cout << char(27) << "[H";
}

// Ask the player for the direction to move the Titanic. If 'x' is pressed, exit.
void move_Titanic(int &row, int &col);

// Move from the position indicated by (row, col)
// randomly by one sqaure, but stay on the board
void move_iceberg(int& row, int& col);

void main(){
	int row, col, irow, icol;

	// initialize random number generation
	srand(time(0));

	row = 1;				// initial position of Titanic
	col = NO_COLS;
	do{				// initial position of iceberg
		irow = rand()%NO_ROWS + 1;
		icol = rand()%NO_COLS + 1;
		if(irow==NO_ROWS && icol==1)	// Don't allow the iceberg on the New York square
			;
		else if(irow==row && icol==col) // Don't allow the iceberg initial Titanic position
			;
		else 
			break;		// iceberg position okay
	}while(true);

	clear_screen();
	while(true){
		home_cursor();
		print_field(row, col, irow, icol);
		move_Titanic(row, col);
		move_iceberg(irow, icol);
		// Test whether Titanic has reached New York
		if(row == NO_ROWS && col == 1) {
			cout << "\n\nCongratulations! You have reached New York!\n";
			return;
		}
		// Test whether Titanic has hit land
		if(offboard(row, col)){
			cout << "\n\nYou have hit land! The Titanic has sunk!\n";
			return;
		}
		// Test whether Titanic has hit iceberg
		if(irow == row && icol == col) {
			cout << "\n\nYou have hit an iceberg! The Titanic has sunk!\n";
			return;
		}
	}
}

void move_Titanic(int& row, int& col)
{
	char dir, resp;

	// Ask user for Titanic move
	cout << "\n[U]p, [D]own, [L]eft, [R]ight, e[X]it? ";
	// get a character from keyboard without waiting for Enter key
	dir = tolower(getch());
	if (dir == 'u')
		row--;
	else if (dir == 'd')
		row++;
	else if (dir == 'l')
		col--;
	else if (dir == 'r')
		col++;
	else if (dir == 'x') {
		cout << "\nDo you really want to abandon ship (y/n)? ";
		resp = tolower(getch());
		if (resp == 'y') {
			cout << "Man overboard!!\n";
			exit(0);
		}
		clear_screen();
	}
}

void move_iceberg(int &irow, int &icol)
{
	int oldr = irow;
	int oldc = icol;
	do{
		irow += (rand()%3) - 1;
		icol += (rand()%3) - 1;
		if(offboard(irow, icol)==false && (irow!=NO_ROWS || icol!=1))  // Don't allow the iceberg on the New York square
			return;
		irow = oldr;
		icol = oldc;
	}while(true);
}

bool offboard(int row, int col)
{
	if(row<1 || row>NO_ROWS)
		return true;
	else if(col<1 || col>NO_COLS)
		return true;
	return false;
}

void print_separator()
{
	cout << "+";
	for (int col=1; col<=NO_COLS; col++)
		cout << "-+";
	cout << endl;
}

void print_row(int r, int row, int col, int irow, int icol)
{
	cout << "|";
	for (int c=1; c<=NO_COLS; c++) {
		if(r==NO_ROWS && c==1)
			cout << "N|";
		else if(r==row && c==col)
			cout << "T|";
		else if(r==irow && c==icol)
			cout << "I|";
		else
			cout << " |";
	}
	cout << endl;
}


void print_field(int row, int col, int irow, int icol)
{
	for (int r=1; r<=NO_ROWS; r++){
      		print_separator();
      		print_row(r, row, col, irow, icol);
   	}
   	print_separator();
}

