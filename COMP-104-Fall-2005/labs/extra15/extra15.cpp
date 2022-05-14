//--------------------------------------------------------------------------
// yourName yourLabSection
// extra15.cpp (model answer)
// The Lord of the Rings with Dynamic Class
#include <iostream> // contains cout and cin
#include <cstdlib> // contains the random number generator rand()
#include <ctime> // contains time() to seed random number
#include <conio.h> // contains getch()
using namespace std;

const int WIDTH = 8;
const int LENGTH = 16;
const int GAMEDURATION = 80;
const int STAGE = 8;

//class definition of Frodo
class Frodo{
public:
	Frodo(); // constructor
	void move(int rowBound, int colBound); // Frodo makes a move
	void reset(); // reset Frodo to upper left corner
	bool atExit(int rowBound, int colBound) const;
	int getrow() const; // get the row index of Frodo's position
	int getcol() const; // get the column index of Frodo's position
private:
	int row;
	int col;
};


Frodo::Frodo(){
	row = 1;
	col = 1;
}

//Frodo makes a move(left, right, up, down or diagonal)
void Frodo::move(int rowBound, int colBound){
	char dir;
	
	cout << "Which way to move (1-9)? Press x to exit: ";
	dir = getch();
	if(dir == '1'){ row++; col--; }
	else if (dir == '2') row++;
	else if (dir == '3'){ row++; col++; }
	else if (dir == '4') col--;
	else if (dir == '6') col++;
	else if (dir == '7'){ row--; col--; }
	else if (dir == '8') row--;
	else if (dir == '9'){ row--; col++; }
	else if (dir == 'x'){
		cout << "\nExiting!" << endl << "GAME OVER!" << endl;
		exit(0);
	}
	if(row<1 || row>rowBound || col<1 || col>colBound){
		cout << endl << "Frodo falls off the board!!" << endl << "GAME OVER!" << endl;
		exit(0);
	}
}

//return the row number of Frodo's position
int Frodo::getrow() const{
	return row;
}

//return the column number of Frodo's position
int Frodo::getcol() const{
	return col;
}

//reset Frodo to upper left corner at the start of a new stage
void Frodo::reset(){
	row=1;
	col=1;
}

bool Frodo::atExit(int rowBound, int colBound) const{
	return ((row==rowBound) && (col == colBound));
}

class BlackRider{
public:
	BlackRider(); // constructor
	void move(int rowBound, int colBound); // BlackRider makes a move
	int getrow() const; // return the row number of BlackRider's position
	int getcol() const; // return the column number of BlackRider's position
	bool atHere(int r, int c) const;
	bool attackFrodo(Frodo f) const;
private:
	int row;
	int col;
};


//constructor
BlackRider::BlackRider(){
	do{
		row = rand()%8+1;
		col = rand()%16+1;
	}while(row==1 && col==1);	// do not allow BlackRIder in upper-left initially
}

//BlackRider makes a move (left, right, up, down or diagonal)
void BlackRider::move(int rowBound, int colBound){
    int dir;
    int oldr;
    int oldc;
	
    oldr = row;
    oldc = col;
	dir = rand()%9+1;
	if (dir==1){ row++; col--; }
	else if (dir==2){ row++; }
	else if (dir==3){ row++; col++; }
	else if (dir==4){ col--; }
	else if (dir==5){ col++; }
	else if (dir==6){ row--; col--; }
	else if (dir==7){ row--; }
	else if (dir==8){ row--; col++; }
	if(row<1 || row>rowBound || col<1 || col>colBound){		// if moves off board, replace to same position
		row = oldr;
		col = oldc;
	}
}

//return BlackRider's row number
int BlackRider::getrow() const{
	return row;
}

//return BlackRider's column number
int BlackRider::getcol() const{
	return col;
}

bool BlackRider::atHere(int r, int c) const{
	return ((row == r) && (col == c));
}

bool BlackRider::attackFrodo(Frodo f) const {
	return ((row == f.getrow()) &&(col == f.getcol()));
}
class BlackRiderArray{
public:
	BlackRiderArray(); // constructor
	BlackRiderArray(const BlackRiderArray &A); // copy constructor
	~BlackRiderArray(); // destructor
	
	void move(int rowBound, int colBound) const; // all BlackRiders make a move
	bool attackFrodo(Frodo f) const; // check if BlackRider attacks Frodo
	void incrementstage(); // increase the number of BlackRider when the stage is increased by 1
	bool anyBlackRidersHere(int r, int c) const;// check  if a BlackRider located at (r,c)
private:
	BlackRider *BlackRiderptr;
	int numBlackRiders;
};

//constructor
BlackRiderArray::BlackRiderArray(){
	numBlackRiders = 3;
	BlackRiderptr = new BlackRider[numBlackRiders];
	
	if(BlackRiderptr == NULL){
		cout << "Memory allocation error, exiting" << endl;
		exit(1);
	}
}

//copy constructor
BlackRiderArray::BlackRiderArray(const BlackRiderArray &A){
	numBlackRiders = A.numBlackRiders;
	BlackRiderptr = new BlackRider[numBlackRiders];
	
	if(BlackRiderptr == 0){
		cout << "Memory allocation error, exiting" << endl;
		exit(1);
	}
	
	for(int i=0; i<numBlackRiders; i++)
		BlackRiderptr[i] = A.BlackRiderptr[i];
}


//destructor
BlackRiderArray::~BlackRiderArray(){
	delete [] BlackRiderptr;
}


//all the BlackRiders make a move
void BlackRiderArray::move(int rowBound, int colBound) const{
	int i;
	
	for(i=0; i<numBlackRiders; i++)
		BlackRiderptr[i].move(rowBound, colBound);
}

//check if any BlackRider and Frodo located in the same position
bool BlackRiderArray::attackFrodo(Frodo f) const{
	for(int i=0; i<numBlackRiders; i++){
		if(BlackRiderptr[i].attackFrodo(f))
			return true;
	}
	return false;
}

//increase the number of BlackRiders when the game stage is increased by 1
void BlackRiderArray::incrementstage(){
	delete [] BlackRiderptr;
	
	numBlackRiders += 3;
	BlackRiderptr = new BlackRider[numBlackRiders];
	
	if(BlackRiderptr == NULL){
		cout << "Memory allocation error, exiting" << endl;
		exit(1);
	}
}

//check if any BlackRider located at (r,c)
bool BlackRiderArray::anyBlackRidersHere(int r, int c) const{
	int i;
	
	for(i=0; i<numBlackRiders; i++){
		if(BlackRiderptr[i].atHere(r, c))
			return true;
	}
	
	return false;
}


//class definition of board
class Board{
public:
	//constructor for board
	Board(Frodo* f, BlackRiderArray *b);
	//destructor for board
	~Board();
	
	void playGame();
	bool gameEnd(int remain);
	void incrementStage(int remain);
	bool blackRiderAttackFrodo();
	void display(int remain);
	
private:
	
	BlackRiderArray *blackRiderPtr;
	Frodo *frodoPtr;
	
	int stage;
	char board[WIDTH+1][LENGTH+1];
	
};								 


//constructor
Board::Board(Frodo *f, BlackRiderArray *b)
{
	//initialize the pointer
	frodoPtr = f;
	blackRiderPtr = b;
	
	//initialize the board
	for(int r=1; r<=WIDTH; r++)
		for(int c=1; c<=LENGTH; c++)
			board[r][c] = ' ';	
		
		//initialize the stage
		stage = 1;
}

//destructor
Board::~Board()
{
	delete frodoPtr;
	delete blackRiderPtr;
}

//display the game information
void Board::display(int remain){
	int r, c;
	
	for(r=1; r<=WIDTH; r++)
		for(c=1; c<=LENGTH; c++)
			board[r][c] = ' ';	
		
	board[WIDTH][LENGTH] = 'E';
	board[frodoPtr->getrow()][frodoPtr->getcol()] = 'F';
	for(r=1; r<=WIDTH; r++)
		for(c=1; c<=LENGTH; c++)
			if(blackRiderPtr->anyBlackRidersHere(r, c))
				board[r][c] = 'B';

	system("cls");	// clear the screen (in <cstdlib>)
	cout << "The Lord of the Rings" << endl;
	for(r=1; r<=WIDTH; r++){
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		for(c=1; c<=LENGTH; c++) {
			cout << "|" << board[r][c];
		}
		cout << "|" << endl;
	}
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	cout << "stage: " << stage << endl;
	cout << "Time remaining: " << remain << endl;
}

//game logic 
void Board::playGame(){
	int startTime;
	int timeremain = GAMEDURATION;
	startTime = time(0);
	
	display(timeremain);
	while(true){
		//entity make moves
		frodoPtr->move(WIDTH, LENGTH);
		blackRiderPtr->move(WIDTH, LENGTH);
		
		//check if game ends. If yes, return to the caller function
		timeremain = GAMEDURATION-(time(0) - startTime);
		if(gameEnd(timeremain))
			break;
		
		//advance to next stage 
		display(timeremain);		
		if(frodoPtr->atExit(WIDTH, LENGTH))
			incrementStage(timeremain);
	}
}

//increase the stage of game 
void Board::incrementStage(int timeremain){
	
	stage++;
	frodoPtr->reset();	
	blackRiderPtr->incrementstage(); 
	display(timeremain);
	cout << "Congratulations! You have reached the exit "<<stage-1<<"!" << endl;
	cout << "Now starting stage " << stage << "!" << endl;
} 

//check if game ends
bool Board::gameEnd(int remain){
	//time out. Game ends
	if(remain <= 0){
		cout << endl << "Time has time out!" << endl;
		cout << "GAME OVER!" <<endl;
		return true;
	}
	
	//Frodo attacked by Black Riders. Game ends
	display(remain);
	if(blackRiderAttackFrodo()){
		cout << "You are attacked by a BlackRider!" << endl;
		cout << "GAME OVER!" << endl;	
		return true;
	}
	
	//Frodo crossed the Black Forest. Game ends
	if (frodoPtr->atExit(WIDTH, LENGTH) && stage == STAGE){
		cout << "Congratulations! You completed all " << STAGE << " stages! You win!!!!" << endl;
		return true;		
	}
	
	//Frodo still alive and has not cross the Black Forest yet and time not out. Game continues!
	return false;
}

//check if any black rider resides in the same space as Frodo
bool Board::blackRiderAttackFrodo(){
	return (blackRiderPtr->attackFrodo(*frodoPtr)); 
}

//program starts here
int main(){
	
	srand(time(0));	
	Frodo*  f = new Frodo();
	BlackRiderArray* blackRiders = new BlackRiderArray();
	Board board(f,blackRiders);
	board.playGame(); 
	return 0;
}
