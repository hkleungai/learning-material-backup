#include <iostream>
#include <fstream>

#include "Game.h"
#include "Dog.h"

/*
 * Remember to include the header file of the animal classes here
 */
#include "ArmyAnt.h"
#include "ArmyAntQueen.h"
#include "Bat.h"
#include "Cat.h"
#include "Dragon.h"
#include "Hawk.h"
#include "Shark.h"
#include "Turtle.h"
#include "Phoenix.h"
#include "Cerberus.h"
#include "BoaConstrictor.h"

using namespace std;

Game::Game(std::string file){
	have_queen[0] = false;
	have_queen[1] = false;
	have_boa[0] = false;
	have_boa[1] = false;
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
			animals[c/5][c%5] = new Hawk(this, c/5, c%5);
			break;
		case BAT:
			animals[c/5][c%5] = new Bat(this, c/5, c%5);
			break;
		case TURTLE:
			animals[c/5][c%5] = new Turtle(this, c/5, c%5);
			break;
		case SHARK:
			animals[c/5][c%5] = new Shark(this, c/5, c%5);
			break;
		case ARMY_ANT:
			animals[c/5][c%5] = new ArmyAnt(this, c/5, c%5);
			break;
		case ARMY_ANT_QUEEN:
			if(have_queen[c/5]){
				cerr << "ERROR: there is already a army ant queen!" << endl;
				exit(-1);
			}else{
				animals[c/5][c%5] = new ArmyAntQueen(this, c/5, c%5);
				have_queen[c/5] = true;
			}
			break;
		case DRAGON:
			animals[c/5][c%5] = new Dragon(this, c/5, c%5);
			break;
		case PHOENIX:
			animals[c/5][c%5] = new Phoenix(this, c/5, c%5);
			break;
		case CERBERUS:
			animals[c/5][c%5] = new Cerberus(this, c/5, c%5);
			break;
		case BOACONSTRICTOR:
			if(have_boa[c/5]){
				cerr << "ERROR: there is already a boa constrictor!" << endl;
				exit(-1);
			}else{
				animals[c/5][c%5] = new BoaConstrictor(this, c/5, c%5);
				have_boa[c/5] = true;
			}
			break;
		}

		c++;
	}

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
		int flyCount = 0, swimCount = 0, antCount = 0, legendCount = 0, grab_position = -1;
		bool have_cerberus = false;

		for(int i = 0; i < 5; i++)			// get the position in which the animal is being grabber by a enemy boa constrictor
			if(animals[!currentPlayer][i]->getName() == "BoaConstrictor"){
				const BoaConstrictor* temp = dynamic_cast<BoaConstrictor*> (animals[!currentPlayer][i]);
				if(temp){
					grab_position = temp->getGrabPos();
					break;
				}
			}

		for(int i = 0; i < 5; i++)
			if(!animals[currentPlayer][i]->isDead()){
				if(i != grab_position){
					animals[currentPlayer][i]->attack();
				}else if(animals[currentPlayer][i]->getName() == "BoaConstrictor"){		// if the prey is also a boa constrictor,
					animals[currentPlayer][i]->attack();								// it can attack back
				}
			}

		/**
		 * To-Do 2: Codes for Special moves (if any) should be written here
		 * Hint: You should use dynamic binding, you may add data members/ functions in the Game class to help you implement this part
		 */
		for(int i = 0; i < 5; i++)		// decide whether there is a special move
		{
			if(!animals[currentPlayer][i]->isDead()){
				if(animals[currentPlayer][i]->getName() == "Shark"
						|| animals[currentPlayer][i]->getName() == "Turtle")
					swimCount++;															// count swimming animals
				else if(animals[currentPlayer][i]->getName() == "Hawk"
						|| animals[currentPlayer][i]->getName() == "Bat"
						|| animals[currentPlayer][i]->getName() == "Dragon"
						|| animals[currentPlayer][i]->getName() == "Phoenix")
					flyCount++;																// count flying animals
				else if(animals[currentPlayer][i]->getName() == "ArmyAnt"
						|| animals[currentPlayer][i]->getName() == "ArmyAntQueen")
					antCount++;																// count ants
				if(animals[currentPlayer][i]->getName() == "Dragon"
						|| animals[currentPlayer][i]->getName() == "Phoenix"
						|| animals[currentPlayer][i]->getName() == "Cerberus")
					legendCount++;															// count legendary animals
				if(animals[currentPlayer][i]->getName() == "Cerberus")
					have_cerberus = true;
			}
		}

		// special move if any
		if(flyCount > 2)
			harass(currentPlayer, grab_position);

		if(swimCount > 2)
			summonTsunami(currentPlayer, grab_position);

		if(antCount == 5)
			marchAndConquer(currentPlayer, grab_position);

		if(legendCount > 2)
			storm(currentPlayer, grab_position);

		if(have_cerberus)
			groupAttack(currentPlayer, grab_position);


		//Output turn info
		cout << "Turn " << turnCount++ << " Player " << currentPlayer+1 << " attacks:" << endl;
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



void Game::harass(Player currentPlayer, int grab_position){
	for(int i = 0; i < 5; i++){
		if(!animals[currentPlayer][i]->isDead() && i != grab_position)
			if(animals[currentPlayer][i]->getName() == "Hawk"
					|| animals[currentPlayer][i]->getName() == "Bat"
					|| animals[currentPlayer][i]->getName() == "Dragon"
					|| animals[currentPlayer][i]->getName() == "Phoenix"){
				FlyAnimal* temp = dynamic_cast<FlyAnimal*> ( animals[currentPlayer][i] );
				if(temp)
					temp->harass();
			}
	}
}

void Game::summonTsunami(Player currentPlayer, int grab_position){
	for(int i = 0; i < 5; i++){
		if(!animals[currentPlayer][i]->isDead() && i != grab_position)
			if(animals[currentPlayer][i]->getName() == "Shark"
					|| animals[currentPlayer][i]->getName() == "Turtle"){
				SwimmingAnimal* temp = (SwimmingAnimal* ) animals[currentPlayer][i];
				if(temp)
					temp->summonTsunami();
			}
	}
}

void Game::marchAndConquer(Player currentPlayer, int grab_position){
	for(int i = 0; i < 5; i++){
		ArmyAnt* temp = (ArmyAnt* ) animals[currentPlayer][i];
		if(temp)
			if(!temp->isDead() && i != grab_position)
				temp->marchAndConquer();
	}
}

void Game::storm(Player currentPlayer, int grab_position){
	for(int i = 0; i < 5; i++){
		if(!animals[currentPlayer][i]->isDead() && i != grab_position)
			if(animals[currentPlayer][i]->getName() == "Dragon"
					|| animals[currentPlayer][i]->getName() == "Phoenix"
					|| animals[currentPlayer][i]->getName() == "Cerberus"){
				LegendaryAnimal* temp = dynamic_cast<LegendaryAnimal*>( animals[currentPlayer][i]);
				if(temp)
					temp->storm();
			}
	}
}

void Game::groupAttack(Player currentPlayer, int grab_position){
	for(int i = 0; i < 5; i++){
		if(!animals[currentPlayer][i]->isDead() && i != grab_position)
			if(animals[currentPlayer][i]->getName() == "Dog"
					|| animals[currentPlayer][i]->getName() == "Cerberus"){
				Dog* temp = dynamic_cast<Dog*>( animals[currentPlayer][i]);
				if(temp)
					temp->groupAttack();
			}
	}
}






