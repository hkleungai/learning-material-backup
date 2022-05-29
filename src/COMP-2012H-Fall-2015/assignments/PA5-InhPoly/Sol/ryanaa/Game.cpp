#include <iostream>
#include <fstream>

#include "Game.h"
#include "Dog.h"
#include "Cat.h"
#include "Hawk.h"
#include "Bat.h"
#include "Turtle.h"
#include "Shark.h"
#include "ArmyAnt.h"
#include "ArmyAntQueen.h"
#include "Dragon.h"
#include "Phoenix.h"
#include "Cerberus.h"

/*
 * Remember to include the header file of the animal classes here
 */

using namespace std;

Game::Game(std::string file) {
	
	antc[0]=antc[1]=0;
	flyc[0]=flyc[1]=0;
	swimc[0]=swimc[1]=0;
	legc[0]=legc[1]=0;
	load(file);

}

Game::~Game() {
	for(int i = 0; i < 10; i++)
		delete animals[i/5][i%5];
}

/**
 * You should instantiate the animal objects here
 * Please refer to the example of "Dog" 
 */
void Game::load(std::string file)
{
	ifstream in(file.c_str());
	int c = 0;
	int id;
	Cerberus* cb;
	Phoenix* ph;
	Dragon* dr;

	while(in >> id)
	{
		switch(id)
		{
		case DOG:
			animals[c/5][c%5] = new Dog(this, c/5, c%5);
			break;
		case CAT:
			animals[c/5][c%5] = new Cat(this, c/5, c%5);
			break;
		case HAWK:
			flyAnimals[c/5][flyc[c/5]++] = new Hawk(this, c/5, c%5);
			animals[c/5][c%5] = flyAnimals[c/5][flyc[c/5]-1];
			break;
		case BAT:
			flyAnimals[c/5][flyc[c/5]++] = new Bat(this, c/5, c%5);
			animals[c/5][c%5] = flyAnimals[c/5][flyc[c/5]-1];
			break;
		case TURTLE:
			swimAnimals[c/5][swimc[c/5]++] = new Turtle(this, c/5, c%5);
			animals[c/5][c%5] = swimAnimals[c/5][swimc[c/5]-1];
			break;
		case SHARK:
			swimAnimals[c/5][swimc[c/5]++]=new Shark(this, c/5, c%5);			
			animals[c/5][c%5] = swimAnimals[c/5][swimc[c/5]-1];
			break;
		case ARMY_ANT:
			armyAnts[c/5][antc[c/5]++] = new ArmyAnt(this, c/5, c%5);
			animals[c/5][c%5] = armyAnts[c/5][antc[c/5]-1];
			break;
		case ARMY_ANT_QUEEN:
			armyAnts[c/5][antc[c/5]++] = new ArmyAntQueen(this, c/5, c%5);
			animals[c/5][c%5] = armyAnts[c/5][antc[c/5]-1];
			break;
		case DRAGON:
			dr = new Dragon(this, c/5, c%5);
			flyAnimals[c/5][flyc[c/5]] = dr;
			legendAnimals[c/5][legc[c/5]] = dr;
			animals[c/5][c%5] = dr;
			flyc[c/5]++; legc[c/5]++;
			break;
		case PHOENIX:
			ph = new Phoenix(this, c/5, c%5);
			flyAnimals[c/5][flyc[c/5]] = ph;
			legendAnimals[c/5][legc[c/5]] = ph;
			animals[c/5][c%5] = ph;
			flyc[c/5]++; legc[c/5]++;
			break;
		case CERBERUS:
			cb = new Cerberus(this, c/5, c%5);
			legendAnimals[c/5][legc[c/5]] = cb;
			animals[c/5][c%5] = cb;
			legc[c/5]++;
			break;
		}
		c++;
	}	
//	cout << "ww" << endl;
}

/**
 * Do NOT modify this function
 */
bool Game::isEnd()
{
	int deadCount1 = 0;
	int deadCount2 = 0;
	
	
	for(int i = 0; i < 5; i++)
	{
		deadCount1 += animals[P1][i]->isDead();
		deadCount2 += animals[P2][i]->isDead();
	}
	if(deadCount1 == 5 && deadCount2 == 5)
	{
		cout << "Draws!" << endl;
	}else if (deadCount1 == 5)
	{
		cout << "Player " << P2+1 << " Wins!" << endl;
	} else if (deadCount2 == 5)
	{
		cout << "Player " << P1+1 << " Wins!" << endl;
	} else {
		return false;
	}
	return true;

}

void Game::start()
{
	Player currentPlayer = P1;
	int turnCount = 1;

	while(!isEnd())
	{
		for(int i = 0; i < 5; i++)
		{
			if(!animals[currentPlayer][i]->isDead()){
				animals[currentPlayer][i]->attack();
				/*cout << 
				for(int i = 0; i < 5; i++)
				{
					if(!animals[P2][i]->isDead())
						cout << animals[P2][i]->getName() << ":"
						<< animals[P2][i]->getCurrentHP() << " ";
					else
						cout << animals[P2][i]->getName() << ":"
						<< "DEAD" << " ";
				}
				cout << endl;*/

			}
		}

		/**
		 * To-Do 2: Codes for Special moves (if any) should be written here
		 * Hint: You should use dynamic binding, you may add data members/ functions in the Game class to help you implement this part
		 */
		if (flyc[currentPlayer] >=3){
			int tmpCnt=0;
			for (int i = 0; i<flyc[currentPlayer]; i++)
				if (!flyAnimals[currentPlayer][i]->isDead()) tmpCnt++;
			if (tmpCnt>=3){
				for (int i = 0; i<flyc[currentPlayer]; i++){
					if (flyAnimals[currentPlayer][i]->isDead()) continue;
					flyAnimals[currentPlayer][i]->harass();
				}
			}
		}
		if (swimc[currentPlayer] >=3){
			int tmpCnt=0;
			for (int i = 0; i<swimc[currentPlayer]; i++)
				if (!swimAnimals[currentPlayer][i]->isDead()) tmpCnt++;
			if (tmpCnt>=3){
				for (int i = 0; i<swimc[currentPlayer]; i++){
					if (swimAnimals[currentPlayer][i]->isDead()) continue;
					swimAnimals[currentPlayer][i]->summonTsunami();
				}
			}
		}
		if (antc[currentPlayer] ==5){
			int tmpCnt=0;
			for (int i = 0; i<antc[currentPlayer]; i++)
				if (!armyAnts[currentPlayer][i]->isDead()) tmpCnt++;
			if (tmpCnt==5){
				for (int i = 0; i<antc[currentPlayer]; i++){
					if (armyAnts[currentPlayer][i]->isDead()) continue;
					armyAnts[currentPlayer][i]->marchAndConquer();
				}
			}
		}

		if (legc[currentPlayer] >=3){
			int tmpCnt=0;
			for (int i = 0; i<legc[currentPlayer]; i++)
				if (!legendAnimals[currentPlayer][i]->isDead()) tmpCnt++;
			if (tmpCnt>=3){
				for (int i = 0; i<legc[currentPlayer]; i++){
					if (legendAnimals[currentPlayer][i]->isDead()) continue;
					legendAnimals[currentPlayer][i]->storm();
				}
			}
		}
		//Output turn info
		cout << "Player 1" << endl;
		for(int i = 0; i < 5; i++)
		{
			if(!animals[P1][i]->isDead())
				cout << animals[P1][i]->getName() << ":"
				<< animals[P1][i]->getCurrentHP() << " ";
			else
				cout << animals[P1][i]->getName() << ":"
				<< "DEAD" << " ";
		}
		cout << endl;
		cout << "Player 2" << endl;
		for(int i = 0; i < 5; i++)
		{
			if(!animals[P2][i]->isDead())
				cout << animals[P2][i]->getName() << ":"
				<< animals[P2][i]->getCurrentHP() << " ";
			else
				cout << animals[P2][i]->getName() << ":"
				<< "DEAD" << " ";
		}
		cout << endl;


		//Switch player turn
		if(currentPlayer == P1)
			currentPlayer = P2;
		else
			currentPlayer = P1;
	}
}
