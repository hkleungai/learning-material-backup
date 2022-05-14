//--------------------------------------------------------------------------
// yourName yourLabSection
// extra14.cpp (model answer)
// The Lord of the Rings
#include <iostream>	// contains cout and cin
#include <cstdlib>	// contains the random number generator rand()
#include <ctime>	// contains time() to seed random number
#include <conio.h>	// contains getch()
using namespace std;

struct BlackRider{
    int row;            // current row number of Black Rider
    int col;            // current col number of Black Rider
    BlackRider* next;   // pointer to next Black Rider
};

struct Board{
    int stage;               // current stage number
    int frodoRow;            // current row number of Frodo
    int frodoCol;            // current col number of Frodo
    BlackRider* bhead;       // pointer to Black Rider linked list
};

// initialize the game board with stage=1, Frodo at upper-left, and 2 BlackRiders at random
void initGame(Board& board);	
// game logic
void playGame(Board& board);
// display the game information
void display(Board board, int timeRemaining);
// Frodo makes a move(left, right, up, down or diagonal)
void moveFrodo(Board& board);
//BlackRider makes a move (left, right, up, down or diagonal)
void moveBlackRiders(Board& board);
// check if game ends
bool gameEnd(Board board, int timeRemaining);
// check to see if Frodo at exit
bool FrodoAtExit(Board board);	
// check if any BlackRider and Frodo located in the same position
bool blackRiderAttackFrodo(Board board);
// increment the stage of game 
void incrementStage(Board& stage, int timeremain);
// set the number of Black Riders to 3*stage number
void addBlackRiders(Board& board);
// delete linked list of Black Riders
void deleteBlackRiders(Board& board);	


void main(){
	Board board;
	
	srand(time(0));	
	initGame(board);
	playGame(board);
}

// initialize the game board with stage=1, Frodo at upper-left, and 2 BlackRiders at random
void initGame(Board& board){	
	board.stage = 1;
	board.frodoRow = 0;
	board.frodoCol = 0;	
	addBlackRiders(board);
}

// game logic
void playGame(Board& board){
	int startTime;
	int timeRemaining = 80;	// start with 80 seconds to play game
	
	startTime = time(0);	
	display(board, timeRemaining);
	while(true){
		//move Frodo and Black Riders
		moveFrodo(board);
		moveBlackRiders(board);
		
		//check if game ends. If yes, return to the caller function
		timeRemaining = 80 - (time(0) - startTime);
		if(gameEnd(board, timeRemaining)){
			deleteBlackRiders(board);
			return;
		}
		
		//advance to next stage 
		display(board, timeRemaining);		
		if(FrodoAtExit(board)){
			incrementStage(board, timeRemaining);
		}
	}
}

// display the game information
void display(Board board, int timeRemaining){
	int r, c;
	char maze[8][16];	// board maze
	
	for(r=0; r<8; r++)								// set all to space as default
		for(c=0; c<16; c++)
			maze[r][c] = ' ';	
		
		maze[7][15] = 'E';								// mark exit
		maze[board.frodoRow][board.frodoCol] = 'F';		// mark Frodo
		BlackRider* p = board.bhead;
		while(p!=NULL){
			maze[p->row][p->col] = 'B';					//  mark BlackRiders
			p = p->next;
		}
		
		system("cls");	// clear the screen (in <cstdlib>)
		cout << "The Lord of the Rings" << endl;
		for(r=0; r<8; r++){
			cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
			for(c=0; c<16; c++)
				cout << "|" << maze[r][c];
			cout << "|" << endl;
		}
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		cout << "stage: " << board.stage << endl;
		cout << "Time remaining: " << timeRemaining << endl;
}

// Frodo makes a move(left, right, up, down or diagonal)
void moveFrodo(Board& board){
	char dir;
	
	cout << "Which way to move (1-9)? Press x to exit: ";
	dir = getch();
	if      (dir == '1'){ board.frodoRow++; board.frodoCol--; }
	else if (dir == '2'){ board.frodoRow++;                   }
	else if (dir == '3'){ board.frodoRow++; board.frodoCol++; }
	else if (dir == '4'){                   board.frodoCol--; }
	else if (dir == '5'){                                     }
	else if (dir == '6'){                   board.frodoCol++; }
	else if (dir == '7'){ board.frodoRow--; board.frodoCol--; }
	else if (dir == '8'){ board.frodoRow--;                   }
	else if (dir == '9'){ board.frodoRow--; board.frodoCol++; }
	else if (dir == 'x'){
		cout << endl << "Exiting!" << endl << "GAME OVER!" << endl;
		deleteBlackRiders(board);
		exit(0);
	}
	if(board.frodoRow<0 || board.frodoRow>7 || board.frodoCol<0 || board.frodoCol>15){
		cout << endl << "Frodo falls off the board!!" << endl << "GAME OVER!" << endl;
		deleteBlackRiders(board);
		exit(0);
	}
}

//BlackRider makes a move (left, right, up, down or diagonal)
void moveBlackRiders(Board& board){
    int dir, oldrow, oldcol;
	
	BlackRider* p = board.bhead;
	while(p!=NULL){
		oldrow = p->row;
		oldcol = p->col;
		dir = rand()%9+1;
		if     (dir==1){ p->row++; p->col--; }
		else if(dir==2){ p->row++;           }
		else if(dir==3){ p->row++; p->col++; }
		else if(dir==4){           p->col--; }
		else if(dir==5){                     }
		else if(dir==6){           p->col++; }
		else if(dir==7){ p->row--; p->col--; }
		else if(dir==8){ p->row--;           }
		else if(dir==9){ p->row--; p->col++; }
		if(p->row<0 || p->row>7 || p->col<0 || p->col>15){ // if moves off board, replace to same postion
			p->row = oldrow;
			p->col = oldcol;
		}
		p = p->next;
	}
}


// check if game ends
bool gameEnd(Board board, int timeRemaining){
	//time out. Game ends
	if(timeRemaining <= 0){
		cout << endl << "Time has run out!" << endl;
		cout << "GAME OVER!" <<endl;
		return true;
	}
	
	//Frodo attacked by Black Riders. Game ends
	display(board, timeRemaining);
	if(blackRiderAttackFrodo(board)){
		cout << "You are attacked by a BlackRider!" << endl;
		cout << "GAME OVER!" << endl;	
		return true;
	}
	
	//Frodo crossed the Black Forest. Game ends
	if(FrodoAtExit(board) && board.stage==8){
		cout << "Congratulations! You completed all 8 stages! You win!!!!" << endl;
		return true;		
	}
	
	//Frodo still alive and has not crossed the Black Forest yet and not time out. Game continue!
	return false;
}

// check to see if Frodo at exit
bool FrodoAtExit(Board board){	
	if(board.frodoRow==7 && board.frodoCol==15)
		return true;
	else 
		return false;
}

// check if any BlackRider and Frodo located in the same position
bool blackRiderAttackFrodo(Board board){
	BlackRider* p = board.bhead;
	while(p!=NULL){
		if(p->row==board.frodoRow && p->col==board.frodoCol)
			return true;
		p = p->next;
	}
	return false;
}

// increment the stage of game 
void incrementStage(Board& board, int timeRemaining){
	deleteBlackRiders(board);
	board.stage++;
	board.frodoRow = 0;
	board.frodoCol = 0;
	addBlackRiders(board); 
	display(board, timeRemaining);
	cout << "Congratulations! You have reached the exit "<<board.stage-1<<"!" << endl;
	cout << "Now starting stage " << board.stage << "!" << endl;
} 

// set the number of Black Riders to 3*stage number
void addBlackRiders(Board& board){
	BlackRider* p;
	
	board.bhead = NULL;
	for(int i=0; i<3*board.stage; i++){
		p = new BlackRider;
		do{
			p->row = rand()%8; 
			p->col = rand()%16; 
		}while(p->row==0 && p->col==0);	// do not allow BlackRider in upper-left initially
		p->next = board.bhead;	//  add new BlackRider to head of list
		board.bhead = p;
	}
}

// delete linked list of Black Riders
void deleteBlackRiders(Board& board){	
	BlackRider* cur;
	BlackRider* p = board.bhead;
	while(p!=NULL){
		cur = p;
		p = p->next;
		delete cur;
	}
	board.bhead = NULL;
}
