//--------------------------------------------------------------------------
// yourName yourLabSection
// lab4.cpp (model answer)
// Crossing the River
#include <iostream>            // contains cout and cin
using namespace std;

int main()
{
	int canLeft;			//cannibals on left bank
	int canRight;			//cannibals on right bank
	int misLeft;			//missionaries on left bank
	int misRight;			//missionaries on right bank
	char first;				//first passenger
	char second;			//second passenger
	int round;			    //rounds the boat moves
	bool left;				//the boat is on left if TRUE, otherwise FALSE
	bool illegalInput;		//set to True if user tries illegal move, False otherwise
	int n;

	//value initialization
	left = true;
	canLeft = 3;
	canRight = 0;
	misLeft = 3;
	misRight = 0;
	round = 0;

	cout << "Crossing the River" << endl; 
	cout << "-----------------------------------------" << endl; 
	//loop while there are person(s) on the LEFT bank
	while(canLeft > 0 || misLeft > 0){		
		cout << "Round " << round << endl;
		cout << "Left\tRight" << endl;
		for(n=0; n<misLeft; n++)
			cout << 'M';
		for(n=0; n<canLeft; n++)
			cout << 'C';
		cout << "\t";
		for(n=0; n<misRight; n++)
			cout << 'M';
		for(n=0; n<canRight; n++)
			cout << 'C';
		cout << endl;

		if(left){	//boat on left bank
			cout << "Boat" << endl;
			//Check if the cannibals eat missionaries
			if((canLeft>misLeft && misLeft>0) || (canRight>misRight && misRight>0)){
				cout << "Missionaries eaten by cannibals! You lose!" << endl;
				return 0;
			}
			do{
				illegalInput = false;
				cout << "First passenger (c for cannibal, m for missionary): ";
				cin >> first;
				if(first=='m' && misLeft>0){
					misLeft--; misRight++;
				}
				else if(first=='c' && canLeft>0){
					canLeft--; canRight++;
				}
				else{
					cout << "Illegal input!" << endl;
					illegalInput = true;
				}
			}while(illegalInput);
			do{
				illegalInput = false;
				cout << "Second passenger (c for cannibal, m for missionary, n for none): ";
				cin >> second;
				if(second=='m' && misLeft>0){
					misLeft--; misRight++;
				}
				else if(second=='c' && canLeft>0){
					canLeft--; canRight++;
				}
				else if(second=='n')
					;
				else{
					cout << "Illegal input!" << endl;
					illegalInput = true;
				}
			}while(illegalInput);
		}
		else{	// boat on right bank
			cout << "\tBoat" << endl;
			//Check if the cannibals eat missionaries
			if((canLeft>misLeft && misLeft>0) || (canRight>misRight && misRight>0)){
				cout << "Missionaries eaten by cannibals! You lose!" << endl;
				return 0;
			}
			do{
				illegalInput = false;
				cout << "First passenger (c for cannibal, m for missionary): ";
				cin >> first;
				if(first=='m' && misRight>0){
					misRight--; misLeft++;
				}
				else if(first=='c' && canRight>0){
					canRight--; canLeft++;
				}
				else{
					cout << "Illegal input!" << endl;
					illegalInput = true;
				}
			}while(illegalInput);
			do{
				illegalInput = false;
				cout << "Second passenger (c for cannibal, m for missionary, n for none): ";
				cin >> second;
				if(second=='m' && misRight>0){
					misRight--; misLeft++;
				}
				else if(second=='c' && canRight>0){
					canRight--; canLeft++;
				}
				else if(second=='n')
					;
				else{
					cout << "Illegal input!" << endl;
					illegalInput = true;
				}
			}while(illegalInput);
		}
		left = !left;
		round++;
		cout << "-----------------------------------------" << endl; 
	}

	cout << "Congratulations! You win the game in " << round << " rounds!" << endl;
	return 0;

}
