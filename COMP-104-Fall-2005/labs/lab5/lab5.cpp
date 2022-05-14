//--------------------------------------------------------------------------------------
// yourName		yourLabSection
// lab5.cpp     (model answer using counting strategy)
// Baccarat Gambling Program
#include <iostream>             // contains cout and cin
#include <cstdlib>              // contains the random number generator rand() 
#include <ctime>                // contains time() to seed the random number            
using namespace std;

int drawcard();					// return a card (1-13)
void displaycard(int cardnum);  // display a card
int cardpoint(int facevalue); //return the card point
int cardtotal(int cardpoints[], int size); // return total total  

//--------------------------------------------------------------------------------

int main(){
	
	int	banker3card[8][10] =   {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
								1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
								1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
								1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
								0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
								0, 0, 0, 0, 1, 1, 1, 1, 0, 0,
								0, 0, 0, 0, 0, 0, 1, 1, 0, 0,
								0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	// for game
	int pcards[3], bcards[3];		// player and banker cards
	int ppoints[3], bpoints[3];		// player and banker cards points, A for 1, 2-9 are face value, 10, J, Q and K are 0
	int ptotal, btotal;				// player and banker total card counts
	char winner;					// 'b' when banker wins, 'p' when player wins, 't' when tie

	// for user
	int money;				// money user has
	char choice;			// for continuing, 'c' for continuing
	char bet;				// for bet, 'b' for banker wins, 'p' for player wins, 't' for tie
	
	// misc
	int i;

	// initalization
	srand(time(0));                 // initialize random number
	
	choice = 'c';					// initalize user
	money = 1000;

	while (choice=='c'){

		for (i=0; i<=2; i++){			// initalize
		pcards[i]=0; ppoints[i]=0;
		bcards[i]=0; bpoints[i]=0;
		}
		ptotal=0; btotal=0;	

		// start 
		cout << endl;
		cout << " Baccarat Gambling Game " << endl;
		cout << " ---------------------- " << endl;
		cout << " User's money: $" << money << endl;
		
		// kick out the user if he has no money left
		if (money == 0){ 
			cout << " You don't have money! Game over!" << endl;
			return 0;
		}

		// draw first two cards
		for (i=0; i<=1; i++){
		pcards[i] = drawcard(); 
		ppoints[i] = cardpoint(pcards[i]); // find card points

		bcards[i] = drawcard();
		bpoints[i] = cardpoint(bcards[i]);
		}	

		// show the first card of banker and player to give hint to user
		cout << " Player 1st card: ";
		displaycard(pcards[0]);
		cout << ", banker 1st card: ";
		displaycard(bcards[0]);
		cout << endl;

		// get user's bet
		cout << " Make your bet on who wins (Press 'b' for banker, 'p' for player, 't' for tie) :" ;
		cin >> bet;
		while (!((bet=='b')||(bet=='p')||(bet=='t'))){ // if user's input is wrong
			cout << " Wrong bet! Input bet again!" << endl;
			cout << " Make your bet on who wins ('b' for banker, 'p' for player, 't' for tie) :" ;
			cin >> bet;
		}		

		// find total for first two cards
		ptotal = cardtotal(ppoints, 2);
		btotal = cardtotal(bpoints, 2);

		// print first two cards and points
		cout << " Player cards: \t"; // print player's cards
		displaycard(pcards[0]);
		cout << " "; 
		displaycard(pcards[1]);
		cout << " ( Two-card total: " << ptotal << " )";
		cout << endl;

		cout << " Banker cards: \t"; // print user's cards
		displaycard(bcards[0]);
		cout << " ";
		displaycard(bcards[1]);
		cout << " ( Two-card total: " << btotal << " )";
		cout << endl;
	
		if ((ptotal>=8)||(btotal>=8)){ // 1. checks whether banker or player get "natural".
			cout << " Player total: " << ptotal << ", banker total: " << btotal << endl;
			if (ptotal>btotal) {
				winner = 'p';
				cout << " Player wins!" << endl;
			}
			else if (ptotal==btotal){
				winner = 't';
				cout << "Tie!" << endl;
			}
			else{
				winner = 'b';
				cout << " Banker wins!" << endl;
			}
		}
		else{ // 2. both hands doesn't get "natural", both hands may be assigned to a third card. 
			// 2.1 check the two-card total of player first.
			switch (ptotal){ 
			case 7: // player stands when ptotal=6 or 7
			case 6:
				cout << " Player stands." << endl;
				break;
			default: // player hits when ptotal of 0 to 5
				pcards[2] = drawcard(); // draw 3rd card to player
				ppoints[2] = cardpoint(pcards[2]);
				cout << " Player hits. ";
				cout << " Player 3rd card: ";
				displaycard(pcards[2]);
				cout << endl;
			}

			// 2.2 Now it is turn to check the banker.
			if ((ptotal==6)||(ptotal==7)){ // 2.2.1 when the player stands
				if (btotal<=5){ // banker hits when btotal<=5
					bcards[2] = drawcard(); // draw 3rd card to banker
					bpoints[2] = cardpoint(bcards[2]);
					cout << " Banker hits. ";
					cout << " Banker 3rd card: ";
					displaycard(bcards[2]);
					cout << endl;
				}
				else if ((btotal==6)||(btotal==7)){
					cout << " Banker stands. " << endl;
				}
			}
			else{ // 2.2.2 when the player hits
				if (banker3card[btotal][ppoints[2]]){ // check the draw cards table and find hit
					bcards[2] = drawcard(); // draw 3rd card to banker
					bpoints[2] = cardpoint(bcards[2]);
					cout << " Banker hits. ";
					cout << " Banker 3rd card: ";
					displaycard(bcards[2]);
					cout << endl;
				}
				else{ // check the draw cards table and find stand
					cout << " Banker stands. --- fail after checking table" << endl;
				}
			}

			// 2.3 final cards are dealt, winning side is the one with greater total

			ptotal = cardtotal(ppoints, 3);
			btotal = cardtotal(bpoints, 3);
			cout << " Player total: " << ptotal << ", banker total: " << btotal << endl;
			if (ptotal>btotal) {
				winner = 'p';
				cout << " Player wins!" << endl;
			}
			else if (ptotal==btotal) {
				winner = 't';
				cout << " Tie!" << endl;
			}
			else{
				winner = 'b';
				cout << " Banker wins!" << endl;
			}

		}		

		// determine whether user wins
		if (bet==winner){ // good bet, give user bonus
			if (bet == 't'){ // bonus for tie is $500
				cout << " Good bet! $500 is added to your account! " << endl;
				money += 500; 
			}
			else{ // bonus for normal is $100
				cout << " Good bet! $100 is added to your account! " << endl;
				money += 100; 
			}
		}
		else{			 // bad bet
			cout << " Bad bet! $100 is deducted from your account! " << endl;
			money -= 100; // update user's money
		}

		// ask user whehter he wants to continue
		cout << " Continue? (Press 'c' to continue) : ";
		cin >> choice;

		if (choice != 'c'){ // users quit the game
			cout << " User leaves the game." << endl;
			cout << " Money you have: " << money << "$" << endl;
		}
	} // end of one round of the game

	return 0;
}

//--------------------------------------------------------------------------------

int drawcard(){							// return a card (1-13)
	int v;
	v = rand()%13 + 1;				// value: 1-13
	return v;
}

//--------------------------------------------------------------------------------

void displaycard(int cardnum){  // display a card
	
	if(cardnum == 1)
		cout << "A ";
	else if(cardnum <= 10)
		cout << cardnum << " "; 
	else if(cardnum == 11)
		cout << "J ";
	else if(cardnum == 12)
		cout << "Q ";
	else if(cardnum == 13)
		cout << "K ";
}

//--------------------------------------------------------------------------------

int cardtotal(int cardpoints[], int size){
	int total = 0;
	int i;
	for (i=0; i<=size-1; i++)
		total += cardpoints[i];
	total = total%10;
	return total;
}

//---------------------------------------------------------------------------------

int cardpoint(int facevalue){
	if (facevalue>=10) 
		return 0;
	else
		return facevalue;
}