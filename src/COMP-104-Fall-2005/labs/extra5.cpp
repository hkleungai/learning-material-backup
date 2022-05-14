//--------------------------------------------------------------------------
// yourName yourLabSection
// extra5.cpp (model answer)
// Crossing the Bridge
#include <iostream>             // contains cout and cin

using namespace std;

int main(){
	bool ALeft;					//passenger A is on left if it is true
	bool BLeft;					//passenger B is on left if it is true
	bool CLeft;					//passenger C is on left if it is true
	bool DLeft;					//passenger D is on left if it is true
	bool ELeft;					//passenger E is on left if it is true
	char first;					//first passenger
	char second;				//second passenger
	int speed_first;			//first passenger's speed
	int speed_second;			//second passenger's speed
	int time_remain;			//time left
	bool left;					//lamp is on left if it is true				
	bool continueLoop;
	
	//value initialization
	left = true;
	ALeft = true;
	BLeft = true;
	CLeft = true;
	DLeft = true;
	ELeft = true;
	speed_first = 0;
	speed_second = 0;
	time_remain = 30;
	
	cout << "Crossing the Bridge" << endl; 
	cout << "-----------------------------------------" << endl; 
	//loop while there are person(s) on the LEFT bank
	while(ALeft == true || BLeft == true || CLeft == true || DLeft == true  || ELeft == true){		
		//print out the game state
		cout << "Time Remain: " << time_remain << endl;					
		cout << "Left\t\tRight" << endl;
		if(ALeft == true)
			cout << "A(speed: 1 min)" << endl;
		else 
			cout << "               \t" <<"A(speed: 1 min)" << endl;
		if(BLeft == true)
			cout << "B(speed: 3 min)" << endl;
		else 
			cout << "               \t" <<"B(speed: 3 min)" << endl;
		if(CLeft == true)
			cout << "C(speed: 6 min)" << endl;
		else 
			cout << "               \t" <<"C(speed: 6 min)" << endl;
		if(DLeft == true)
			cout << "D(speed: 8 min)" << endl;
		else 
			cout << "               \t" <<"D(speed: 8 min)" << endl;
		if(ELeft == true)
			cout << "E(speed: 12 min)" << endl;
		else 
			cout << "               \t" <<"E(speed: 12 min)" << endl;
		if(left){				//lamp on left bank
			cout << "Lamp" << endl;
			do{
				//input the first passenger
				cout << "First person (A, B, C, D or E): ";
				cin >> first;
				continueLoop = false;
				if(first == 'A' && ALeft == true){
					ALeft = false;
					speed_first = 1;
				}
				else if(first == 'B' && BLeft == true){
					BLeft = false;
					speed_first = 3;
				}
				else if(first == 'C' && CLeft == true){
					CLeft = false;
					speed_first = 6;
				}
				else if(first == 'D' && DLeft == true){
					DLeft = false;
					speed_first = 8;
				}
				else if(first == 'E' && ELeft == true){
					ELeft = false;
					speed_first = 12;
				}
				else{
					cout << "Illegal input!" << endl;
					continueLoop = true;
				}
			}while(continueLoop);
			do{
				//input the second passenger
				cout << "Second person (A, B, C, D, E or N for none): ";
				cin >> second;
				continueLoop = false;
				if(second =='A' && ALeft == true){
					ALeft = false;
					speed_second = 1;
				}
				else if(second == 'B' && BLeft == true){
					BLeft = false;
					speed_second = 3;
				}
				else if(second == 'C' && CLeft == true){
					CLeft = false;
					speed_second = 6;
				}
				else if(second == 'D' && DLeft == true){
					DLeft = false;
					speed_second = 8;
				}
				else if(second == 'E' && ELeft == true){
					ELeft = false;
					speed_second = 12;
				}
				else if(second == 'N'){
					speed_second = 0;
				}
				else {	
					cout << "Illegal input!" << endl;
					continueLoop = true;
				}
			}while(continueLoop);
		} else {	// lamp on right bank
			cout << "               \tLamp" << endl;
			do{
				//input the first passenger
				cout << "First person (A, B, C, D, E): ";
				cin >> first;
				continueLoop = false;
				if(first == 'A' && ALeft == false){
					ALeft = true;
					speed_first = 1;
				}
				else if(first == 'B' && BLeft == false){
					BLeft = true;
					speed_first = 3;
				}
				else if(first == 'C' && CLeft == false){
					CLeft = true;
					speed_first = 6;
				}
				else if(first == 'D' && DLeft == false){
					DLeft = true;
					speed_first = 8;
				}
				else if(first == 'E' && ELeft == false){
					ELeft = true;
					speed_first = 12;
				}
				else {
					cout << "Illegal input!" << endl;
					continueLoop = true;
				}
			}while(continueLoop);
			do{
				//passenger
				cout << "Second person (A, B, C, D, E or N for none): ";
				cin >> second;
				continueLoop = false;
				if(second == 'A' && ALeft == false){
					ALeft = true;
					speed_second = 1;
				}
				else if(second == 'B' && BLeft == false){
					BLeft = true;
					speed_second = 3;
				}
				else if(second == 'C' && CLeft == false){
					CLeft = true;
					speed_second = 6;
				}
				else if(second == 'D' && DLeft == false){
					DLeft = true;
					speed_second = 8;
				}
				else if(second == 'E' && ELeft == false){
					ELeft = true;
					speed_second = 12;
				}
				else if(second == 'N'){
					speed_second = 0;
				}
				else{
					cout << "Illegal input!" << endl;
					continueLoop = true;
				}
			}while(continueLoop);
		}
		left = !left;
		//update the remaining time
		if(speed_second > speed_first)
			time_remain -= speed_second;
		else
			time_remain -= speed_first;
		cout << "-----------------------------------------" << endl; 
		if(time_remain < 0){
			cout << "The lamp has gone out! You lose!" << endl;
			return 0;
		}
	}
	cout << "Congratulations! You helped the family cross the bridge in " << 30-time_remain << " minutes!" << endl;
	return 0;
}


