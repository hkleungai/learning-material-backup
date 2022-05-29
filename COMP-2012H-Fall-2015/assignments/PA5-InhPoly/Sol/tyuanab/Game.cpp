#include <iostream>
#include <fstream>

#include "Game.h"
#include "Dog.h"
#include "Cat.h"
#include "Bat.h"
#include "Hawk.h"
#include "Dragon.h"
#include "ArmyAnt.h"
#include "ArmyAntQueen.h"
#include "Turtle.h"
#include "Shark.h"
#include "Phoenix.h"
#include "Cerberus.h"

/*
 * Remember to include the header file of the animal classes here
 */

using namespace std;

Game::Game(std::string file) {
	load(file);
	srand(time(NULL));
}

Game::~Game() {
	for (int i = 0; i < 10; i++)
		delete animals[i / 5][i % 5];
}

/**
 * You should instantiate the animal objects here
 * Please refer to the example of "Dog" 
 */
void Game::load(std::string file) {
	ifstream in(file.c_str());
	int c = 0;
	int id;
	while (in >> id) {
		switch (id) {
		case DOG:
			animals[c / 5][c % 5] = new Dog(this, c / 5, c % 5);
			break;
		case CAT:
			animals[c / 5][c % 5] = new Cat(this, c / 5, c % 5);
			break;
		case HAWK:
			animals[c / 5][c % 5] = new Hawk(this, c / 5, c % 5);
			break;
		case BAT:
			animals[c / 5][c % 5] = new Bat(this, c / 5, c % 5);
			break;
		case TURTLE:
			animals[c / 5][c % 5] = new Turtle(this, c / 5, c % 5);
			break;
		case SHARK:
			animals[c / 5][c % 5] = new Shark(this, c / 5, c % 5);
			break;
		case ARMY_ANT:
			animals[c / 5][c % 5] = new ArmyAnt(this, c / 5, c % 5);
			break;
		case ARMY_ANT_QUEEN:
			animals[c / 5][c % 5] = new ArmyAntQueen(this, c / 5, c % 5);
			break;
		case DRAGON:
			animals[c / 5][c % 5] = new Dragon(this, c / 5, c % 5);
			break;
		case PHOENIX:
			animals[c / 5][c % 5] = new Phoenix(this, c / 5, c % 5);
			break;
		case CERBERUS:
			animals[c / 5][c % 5] = new Cerberus(this, c / 5, c % 5);
			break;
		}

		c++;
	}

}

/**
 * Do NOT modify this function
 */
bool Game::isEnd() {
	int deadCount1 = 0;
	int deadCount2 = 0;
	for (int i = 0; i < 5; i++) {
		deadCount1 += animals[P1][i]->isDead();
		deadCount2 += animals[P2][i]->isDead();
	}

	if (deadCount1 == 5 && deadCount2 == 5) {
		cout << "Draws!" << endl;
	} else if (deadCount1 == 5) {
		cout << "Player " << P2 + 1 << " Wins!" << endl;
	} else if (deadCount2 == 5) {
		cout << "Player " << P1 + 1 << " Wins!" << endl;
	} else {
		return false;
	}
	return true;

}
void Game::start() {
	Player currentPlayer = P1;
	int turnCount = 1;
	while (!isEnd()) {
		for (int i = 0; i < 5; i++) {
			if (!animals[currentPlayer][i]->isDead()) {
				animals[currentPlayer][i]->getBuff();
				animals[currentPlayer][i]->attack();
			}
		}

		/**
		 * To-Do 2: Codes for Special moves (if any) should be written here
		 * Hint: You should use dynamic binding, you may add data members/ functions in the Game class to help you implement this part
		 */
		spe_attack(0, 2, animals, currentPlayer);
				spe_attack(1, 3, animals, currentPlayer);
				spe_attack(2, 3, animals, currentPlayer);
				spe_attack(3, 5, animals, currentPlayer);
				Legend_attack(3, animals, currentPlayer);
		//Output turn info
		cout << "Turn " << turnCount++ << " Player " << currentPlayer + 1
				<< " attacks:" << endl;
		cout << "Player 1" << endl;
		for (int i = 0; i < 5; i++) {
			if (!animals[P1][i]->isDead())
				cout << animals[P1][i]->getName() << ":"
						<< animals[P1][i]->getCurrentHP() << " ";
			else
				cout << animals[P1][i]->getName() << ":" << "DEAD" << " ";
		}
		cout << endl;
		cout << "Player 2" << endl;
		for (int i = 0; i < 5; i++) {
			if (!animals[P2][i]->isDead())
				cout << animals[P2][i]->getName() << ":"
						<< animals[P2][i]->getCurrentHP() << " ";
			else
				cout << animals[P2][i]->getName() << ":" << "DEAD" << " ";
		}
		cout << endl;

		//Switch player turn
		if (currentPlayer == P1)
			currentPlayer = P2;
		else
			currentPlayer = P1;
	}
}
int Game::count_for(int species, Player currentPlayer, Animal * animals[2][5]) {
	int temp = 0;
	for (int i = 0; i < 5; i++) {
		if (animals[currentPlayer][i]->getAttribute()[species]
				&& !animals[currentPlayer][i]->isDead())
			temp++;
	}
	//std::cout << "TEMP: " << temp << std::endl;
	return temp;
}
void Game::spe_attack(int species, int number_require, Animal* animals[2][5],
		Player currentPlayer) {
	if (count_for(species, currentPlayer, animals) >= number_require) {
		if (species == 0 && !has_cerberus(animals, currentPlayer)) {
			//std::cout<<"no cerberus so dog is useless" << std::endl;
			return;
		}
		for (int i = 0; i < 5; i++) {
			if (animals[currentPlayer][i]->getAttribute()[species] == 1
					&& !animals[currentPlayer][i]->isDead()) {
				if (animals[currentPlayer][i]->getName() == "Dog"
						|| animals[currentPlayer][i]->getName() == "Cerberus")
					std::cout << animals[currentPlayer][i]->getName()
							<< " gives a group attack" << std::endl;
				if (animals[currentPlayer][i]->getName() == "Dragon"
						|| animals[currentPlayer][i]->getName() == "Bat"
						|| animals[currentPlayer][i]->getName() == "Hawk"
						|| animals[currentPlayer][i]->getName() == "Phoenix")
					std::cout << animals[currentPlayer][i]->getName()
							<< " harasses the others" << std::endl;
				if (animals[currentPlayer][i]->getName() == "ArmyAnt")
					std::cout << animals[currentPlayer][i]->getName()
							<< "s march and conquer" << std::endl;
				if (animals[currentPlayer][i]->getName() == "Shark"
						|| animals[currentPlayer][i]->getName() == "Turtle")
					std::cout << animals[currentPlayer][i]->getName()
							<< " summons a Tsunami! " << std::endl;
				//std::cout<<animals[currentPlayer][i]->getName()<< "SPECIAL ATTACK!!" <<std::endl;
				animals[currentPlayer][i]->special_attack();
			}
		}
	}
}
//Specialized special for Legend_animal
void Game::Legend_attack(int number_require, Animal* animals[2][5],
		Player currentPlayer) {
	int special_damage = 3;		//for Legend Animal
	int count_of_Legend = count_for(4, currentPlayer, animals);
	if (count_of_Legend >= 3) {
		for (int i = 0; i < count_of_Legend; i++) {
			for (int pos = 0; pos < 5; pos++) {
				if (!animals[currentPlayer][pos]->isDead()) {
					animals[!currentPlayer][pos]->takeDamage(special_damage);
				}
			}
			std::cout << "STORM!" << std::endl;
		}
	}
}
bool Game::has_cerberus(Animal* animals[2][5], Player currentPlayer) {
	for (int pos = 0; pos < 5; pos++) {
		if (!animals[currentPlayer][pos]->isDead()
				&& animals[currentPlayer][pos]->getName() == "Cerberus") {
			//std::cout<< "CERBERUS IS EXIST!" <<std::endl;
			return true;
		}
	}
	return false;
}
