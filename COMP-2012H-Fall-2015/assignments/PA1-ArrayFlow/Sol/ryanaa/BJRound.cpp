//
//  Blackjack.cpp
//  PA1_OOP
//
//  Created by Yre on 14/9/15.
//  Copyright (c) 2015 Yre. All rights reserved.
//

#include "BJRound.h"
#include "BJPlayer.h"
#include "Player.h"
#include "Dealer.h"
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <cstdlib>
using namespace std;

BJRound::BJRound(double totalMoney){
	this->totalMoney = totalMoney;
	cardPoolPointer = 1;
	numberOfPlayers = 1;
	totalBusted = 0;
    dealer.setName("Dealer");
    player[1].setName("Player");
    player[2].setName("Split");
    player[3].setName("Second Split");
    player[4].setName("Thrid Split");
}
//==========Set Card===========
int BJRound::getCardPointer(){
	return cardPoolPointer++;  // and pull it out and move it to the next position. Because this two always happen together
}

//===========Set Card & Reshuffle==========
bool BJRound::checkTestCase(){
	cout << "Test Case? (Y/N)" << endl;
	if (checkInput()) return true;
	return false;
}

void BJRound::normalCaseDeck(){
	int k=1;
	for (int i = 1; i <= 13; i++)
		for (int j = 0; j < 4; j++){
			cardPool[k].setNumb(i);
			cardPool[k].setSuit(j);
			k++;
		}
	reshuffle(1);
}

void BJRound::testCaseDeck(){
    int input,numberOfCardinTestCase;

//This part is the testcase on the website.
    numberOfCardinTestCase = 12;
    int testCaseNum[55]={0,2,2,3,7,5,9,10,2,4,3,4,11}; // set for 2D 2H 3C 7D 5C 9D 10H 2C 4D 3S 4H 11D
    char testCaseSuit[55]={' ','D','H','C','D','C','D','H','C','D','S','H','D'};
	
    if (!onWeb){
	//any-size test case and can input different test case
		int input;
	    char str[100];
	    cout << "Number of test case cards: " << endl;
	    do{
	        while(1){
	            cin >> str;
	            int flag = 0;
	            for (int i = 0; i < strlen(str); i++)
	                if (str[i]>'9' || str[i]<'0'){
	                    flag=1;                       //check whether it is a pure number
	                    break;
	                }
	            if (flag)
	                cout << "Input error. Plz input a number(e.g. 12):" << endl;
	            else break;
	        }
	        input = 0;
	        for (int i = 0; i < strlen(str); i++){
	            input = input * 10 + (str[i]-'0');   //convert the substring into a number
	        }
	        if (input > 52)
	            cout << "Too many cards. Input a number between 1 and 52." << endl;
	    }
	    while (input>52);
        numberOfCardinTestCase = input;
	    cout << "Input " << numberOfCardinTestCase << " cards(e.g.\"2D 2H 3C 7D 5C 9D 10H 2C 4D 3S 4H 11D\"):" << endl;
	    for (int i = 1; i <= numberOfCardinTestCase; i++)
	        scanf("%d%c",&testCaseNum[i],&testCaseSuit[i]);
	}

	for (int i = 1; i <= numberOfCardinTestCase; i++){
		testCase[i][0]=testCaseNum[i];
		if (testCaseSuit[i]=='H') testCase[i][1]=0;
		if (testCaseSuit[i]=='D') testCase[i][1]=1;
		if (testCaseSuit[i]=='C') testCase[i][1]=2;
		if (testCaseSuit[i]=='S') testCase[i][1]=3;				// converting the suit into number
	}

	for (int i = 1; i <= numberOfCardinTestCase; i++){
		cardPool[i].setNumb(testCase[i][0]);
		cardPool[i].setSuit(testCase[i][1]);
	}
	int k=numberOfCardinTestCase+1; 
	for (int i = 1; i <= 13; i++)
		for (int j = 0; j < 4; j++){			// generating 4 suits
            int ch;
			for (ch = 1; ch <= numberOfCardinTestCase; ch++)      // if it appeared in the previous cards, then break
                if (testCase[ch][0] == i && testCase[ch][1] == j) break;
            if (ch==numberOfCardinTestCase+1){                    // otherwise generating a new one
                cardPool[k].setNumb(i);
                cardPool[k].setSuit(j);
                k++;
            }

		}

	// the order of first numberOfCardinTestCase cards have been settled already,
	// so we don't have to reshuffle the first numberOfCardinTestCase cards.
	reshuffle(numberOfCardinTestCase+1);
}

void BJRound::reshuffle(int startPoint){
	Card temp;
	int index;
	srand(time(0));  // initialize random number generator
	for (int i = startPoint; i <= 52; i++){             // for each card
		index = rand()%(52-startPoint+1)+startPoint;    // change the position with an random one 
		temp = cardPool[i];
		cardPool[i] = cardPool[index]; 
		cardPool[index] = temp;
	}
	cardPoolPointer=1;
}

//=============Interactions================
void BJRound::display(){
	dealer.display();
	for (int i = 1;i <= numberOfPlayers; i++)
		player[i].display();

}
bool BJRound::checkBlackJackforPlayer(Player& player){
	if (player.getCardSize()==2 && player.getTotalPoint()==21)   // if the total point is 21 and there are only 2 cards
		return true;
	return false;
}

void BJRound::askDrawFor(Player& player){
	cout << "Draw for " << player.getName() << "(current " << player.getTotalPoint() << ")? (Y/N)" << endl;
}
void BJRound::askSplitFor(Player& player){
	cout << "Split for " << player.getName() << "? (Y/N)" << endl;
}
bool BJRound::checkInput(){
	char input;
	cin >> input;
	while(input!='Y' && input!='y' && input!='N' && input!='n'){
        	cout << "Wrong input. Input again: ";
        	cin >> input;
     }
	if (input == 'Y' || input == 'y')
		return true;
	else return false;
}

//=================Drawing===================

int BJRound::canSplit(){
	if (curPay > totalMoney) return 0;           // money should be enough to split
	for (int i = 1; i <= numberOfPlayers; i++){
		if (!player[i].checkSplitibility()) continue; 
		return i; 								// as long as there exists one that can split, return the index
	}
	return 0;
}

void BJRound::drawForPlayer(Player& player){
	while (player.getCardSize() < 5){
		askDrawFor(player);
        if (!checkInput()){
            display();
            break;    // stop drawing
        }
		player.Draw(cardPool[cardPoolPointer++]);
		//moveCardPoolPointer(1);
        player.getTotalPoint();
		if (player.checkBusted()){      // if one is busted, then break and stop drawing. 
			display();
			cout << player.getName() << " busted!" << endl;
			player.setBustedFlag(true);
			totalBusted ++;             // count the totalbusted number in order to avoid the situation 
			break;						// that all the players(split) are busted and dealer keep drawing 
		}
		display();
	}
}

bool BJRound::decideForNaiveDealer(){
	return dealer.getTotalPoint()<=16;	// naive dealer only consider the totalpoint is less then 16 or not
}

bool BJRound::decideForSmartDealer(){
	int totalPoint=85*4,cardnum=0;
	double ave;
	totalPoint -= dealer.getTotalPoint();
	for (int i = 1; i<=numberOfPlayers;i++){
		totalPoint -= player[i].ca[1].getNumb();
		totalPoint -= player[i].ca[2].getNumb();
		cardnum+=2;
	}
	cardnum+=dealer.getCardSize();			
	// totalpoint is the sum of cards' rank that cannot be seen from the dealer.
	// 52-cardnum is the number of cards that cannot be seen
	// we calculate the expectation of the number of card which will be drawn next
	ave = 1.0*totalPoint / (52-cardnum);
	return (dealer.getTotalPoint()+(int)ave<=21);
}

void BJRound::drawForDealer(Dealer& dealer){
	while (dealer.getCardSize() < 5 && decideForSmartDealer()){   //if use the naive one, change the decideForSmartDealer() into decideForNaiveDealer()
		dealer.Draw(cardPool[cardPoolPointer++]);
		if (dealer.checkBusted()){
			display();
			dealer.setBustedFlag(true);
			break;
		}
	}
    display();
}

//================Judging======================
void BJRound::Announcement(){
	cout << endl;
	dealer.final_display();
	for (int i = 1;i <= numberOfPlayers; i++)
		player[i].display();
	cout << "> Dealer " << dealer.getTotalPoint() << " points, Player " << player[1].getTotalPoint() << " points";
	for (int i = 2; i <= numberOfPlayers; i++){
		cout << ", and " << player[i].getTotalPoint() << " points";
	}
	cout << "." << endl;
    

    for (int i = 1;i<=numberOfPlayers;i++){
        judge(player[i],dealer.getTotalPoint());     //compare each player's score and the dealer's score
    }
	calcReward();
}

void BJRound::judge(Player& player,int dealerScore){
//	cout << "judge " << playerScore << ' ' << dealerScore << endl;
    int playerScore = player.getTotalPoint();
    if  (playerScore>21) playerScore = 0; 
	if ((playerScore==0 && dealerScore > 21) ||    //dealer and player busted
		(playerScore == dealerScore)){             //same score
		cout << "Tie for " << player.getName() << "!" << endl;
	}
	else if (playerScore < dealerScore && dealerScore <= 21){
		cout << "Dealer wins " << player.getName() << "!" << endl;
	}else{
		cout << player.getName() << " wins Dealer!" << endl;
	}
}

void BJRound::setPay(){
	int input;
	do{
		char str[100];
		cout << "Pay for this round: ";
		while(1){
			cin >> str;
			int flag = 0;
            for (int i = 0; i < strlen(str); i++)
				if (str[i]>'9' || str[i]<'0'){
					flag=1;                      //check whether it is a "pure number"
					break;
				}
			if (flag)
				cout << "Input error. Plz input a number:" << endl;
			else break;
		}
		input = 0;
        for (int i = 0; i < strlen(str); i++){
			input = input * 10 + (str[i]-'0');   // converting a string into a number
		}
	    if (input == 0) cout << "Pay needs to be bigger than 0" << endl;
	    else if (input <= totalMoney) break;
	    else cout << "Money is not enough. Type again.";
	}while (input > totalMoney || input <= 0);
	curPay = input;
}

void BJRound::calcReward(){
	for (int i=1;i<=numberOfPlayers;i++){
		if (player[i].getBustedFlag()) continue;
		if (player[i].getTotalPoint() < dealer.getTotalPoint() && dealer.getTotalPoint()<=21) continue;
		if (player[i].Blackjack) totalMoney+=2.5*curPay;
		else if (player[i].getTotalPoint() == dealer.getTotalPoint()) totalMoney+=curPay;
		else totalMoney+=2*curPay;
	}
}

void BJRound::outputTotalMoney(){
	cout << "Current Money:" << totalMoney << endl;
}

//================Rundown===============

int BJRound::run(){

	setPay();
	totalMoney -= curPay;

	 if (!checkTestCase())   // use testcase or random case
	 	normalCaseDeck();
	 else {
	 	cout << "Use test case on the website? (Y/N)" << endl;
	 	onWeb=false;
	 	if (checkInput()) onWeb=true;  // flag on whether the test case need to be input (or use the one on the webpage)
	 	testCaseDeck();
	 }

    player[1].Draw(cardPool[cardPoolPointer++]);
    player[1].Draw(cardPool[cardPoolPointer++]); // after drawing cards from cardpool, the pointer of card pool need +1

	dealer.Draw(cardPool[cardPoolPointer++]);
	dealer.Draw(cardPool[cardPoolPointer++]);

    if (checkBlackJackforPlayer(player[1])){  // if blackjack at first, then there is no chance to do the split
    	player[1].display();
        cout << "Black jack for player!" << endl;
        totalMoney += curPay*2.5; //1.5+1, including the original paid money
        outputTotalMoney();
        return totalMoney;
    }
    display();
   
	while (numberOfPlayers < 4){      // at most split three time, which means the number of player needs to smaller or equal to 4
		int toSplitPlayer = canSplit();   // if there is one can split, then return the index
        if (toSplitPlayer == 0) break;    // if it is 0, which means no one can be splited
        	askSplitFor(player[toSplitPlayer]);
            if (checkInput()){
                numberOfPlayers++;
                totalMoney -= curPay;     // every split need to pay the same amount of money as the first hand
                player[toSplitPlayer].split(player[numberOfPlayers]);
                player[toSplitPlayer].Draw(cardPool[cardPoolPointer++]);
                player[numberOfPlayers].Draw(cardPool[cardPoolPointer++]);  // after a split, 2 cards need to be given individually
                if(checkBlackJackforPlayer(player[toSplitPlayer])){         // check whether the blackjack will happen
                    player[toSplitPlayer].Blackjack = true;
                    cout << "Blackjack for " << player[toSplitPlayer].getName() << "!" << endl;
                }
                if (checkBlackJackforPlayer(player[numberOfPlayers])){		// check whether the blackjack will happen
                    player[numberOfPlayers].Blackjack = true;
                    cout << "Blackjack for " << player[numberOfPlayers].getName() << "!" << endl;
                }
            }else player[toSplitPlayer].splitable = false; //once the splitable set to false, the system will not ask the player whether he wants to split, even if he can.
            cout << endl;
            display();
	}

    for (int i = 1; i <= numberOfPlayers; i++){
        if (player[i].Blackjack){
            cout << player[i].getName() << " have blackjacked!" << endl <<"I suggest that you stop  drawing=)" << endl;
            continue;
        }
		drawForPlayer(player[i]);  // draw for each player(or split)
    }
	
	if (numberOfPlayers != totalBusted){  // if none of player(or split) remain unbusted, then the dealer wins directly.
		drawForDealer(dealer);
	}
	Announcement();
	outputTotalMoney();
	return totalMoney;			// return the money left after the game
}


//1S 3C 2S 11D 5H 7D 8H 1H 5C 3D 4H 12C 6H