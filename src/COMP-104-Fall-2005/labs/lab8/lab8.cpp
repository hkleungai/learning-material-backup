#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// function prototypes
int  get_map_size();					// get the size of map, i.e. number of columns, (3-19)
int  get_user_guess(int size);			// get user's guess, column number (1 - total number of columns)
void generate_map(char *map, int size);	// initialize, put '+' and '@' in the map (obstacle and car)
void display_map(char *map, int size);	// used by the update_map()
int  update_map(char *map, int size);	// update and display the map


void main() {
	int size=0;
	int guess=0, answer=0;
	char *map;

	srand(time(0));

	cout << "*************** Comp104 Rally!!! **************" << endl << endl;
	
	size = get_map_size();

	map = new char[size*size];	// create the map

	generate_map(map, size);
	system("cls");
	display_map(map, size);

	guess = get_user_guess(size);

	answer = update_map(map, size);
	
	cout << endl;
	if (guess==answer) {
		cout << "Congulations!! You win the prize!!!" << endl;
	}
	else {
		cout << "Sorry! You loose..." << endl;
	}

	delete [] map;		// destroy the map

}

int get_map_size() {
	int size=0;
	bool ok=true;

	do {
		cout << "Please input the size of map (3-19 columns): ";
		cin >> size;
		if ((size < 3) || (size > 19)) {
			cout << "The number should between 3 and 19. Input again." << endl;
			ok=false;
		}
		else {
			ok=true;
		}
	} while (!ok);

	return size;
}

int get_user_guess(int size) {
	int guess=-1;
	bool ok=true;

	do {
		cout << "In which column (1-" << size << ") will the car reach the bottom: ";
		cin >> guess;
		if ((guess < 1) || (guess > size)) {
			cout << "This number is out of range. Input again." << endl;
			ok=false;
		}
		else {
			ok=true;
		}
	} while (!ok);

	return guess;
}

void generate_map(char *map, int size) {
	double ratio=0.5;
	int r, c, i;

	// initalize the map
	for(r=0; r<size; r++){
		for(c=0; c<size; c++){
			*(map+r*size+c) = ' ';
		}
	}

	for(i=0; i < (size*size*ratio); i++) {
		r=rand()%size;	// get a random position
		c=rand()%size;
		// there should be at least one space between each '+' (obstacle)
		if (*(map+r*size+c) != '+' && r>=0 && c>=0 && r<=size-1 && c<=size-1
			&& *(map+r*size+c+1) != '+' && *(map+r*size+c-1) != '+') {
			*(map+r*size+c) = '+';
		}
	}

	// put the car in the middle
	r=0;
	c=size/2;
	*(map+r*size+c) = '@';

}

void display_map(char *map, int size) {
	int r, c;

	cout << endl << endl;

	// print the content of map
	for(r=0; r<size; r++){
		cout << "| ";
		for(c=0; c<size; c++){
			cout << *(map+r*size+c) << " ";
		}
		cout << "|" << endl;
	}

	// output last line, which is the column number
	// The column number mod 10 and get a ones value, is for display only
	cout << "| ";
	for(c=1; c<=size; c++) {
		cout << (c%10) << " ";
	}
	cout << "|" << endl;
}
				
int update_map(char *map, int size) {
	int carR=0, carC=size/2;

	int oldR, oldC;
	bool hasOld=false;
	
	display_map(map, size);

	// update the map
	do {
		*(map+carR*size+carC) = ' ';	// reset the location to nothing
		if (hasOld) {
			*(map+carR*size+carC) = '+';	//reset the location of + in left turn or right turn
			hasOld = false;
		}

		// if a '+' block its way, either turn left or turn right
		if(*(map+(carR+1)*size+carC) == '+') {			
			if (rand()%2) {		// (rand()%2) give out either 0 or 1
				carC--;			// -1 = turn left
				if (carC < 0) { // hit the wall
					cout << "Car crashed!!!" << endl;
					carC=0;
					return -1;
				}
				else {
					if (*(map+carR*size+carC) == '+') {
						oldR=carR;
						oldC=carC;
						hasOld = true;
					}
					*(map+carR*size+carC) = '@';
				}
			}
			else {
				carC++;			// +1 = turn right
				if (carC > size-1) { // hit the wall
					cout << "Car crashed!!!" << endl;
					carC=size-1;
					return -1;
				}
				else {
					if (*(map+carR*size+carC) == '+') {
						oldR=carR;
						oldC=carC;
						hasOld = true;
					}
					*(map+carR*size+carC) = '@';
				}
			}
		}
		else { // nothing block the road, then go to next line
			carR++;
			*(map+carR*size+carC) = '@';
		}

		system("cls");
		display_map(map, size);

	} while (carR < size-1);

	// when the car reach the last line, that is the answer
	return carC+1;
}