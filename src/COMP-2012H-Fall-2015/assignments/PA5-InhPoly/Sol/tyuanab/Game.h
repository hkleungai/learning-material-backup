#ifndef GAME_H_
#define GAME_H_

#include "Animal.h"
class Animal;


class Game {
public:
	enum Player {P1 = 0, P2 = 1 };
	enum AnimalIds {DOG, CAT, HAWK, BAT, TURTLE, SHARK, ARMY_ANT, ARMY_ANT_QUEEN, DRAGON, PHOENIX, CERBERUS };
	//enum SpecialMove{Group_attack,Harass,SummonTsunami, marchAndConquer, WeatherStrom};
	Animal* animals[2][5];

	Game(std::string file);
	virtual ~Game();

	void load(std::string file);
	bool isEnd();
	void start();
	//************************************************************************
	//The functions I add in order to implement special move

	//Count for currentPlayer's specific animal by Attributes.
	int count_for(int species, Player currentPlayer, Animal * animals[2][5]);
	//To check if cerberus is exist.
	bool has_cerberus(Animal* animals[2][5], Player currentPlayer);
	//Use an Animal pointer to invoke the virtual special attack.
	void spe_attack(int species, int number_requier, Animal* animals[2][5], Player currentPlayer);
	//Special for Legend animal because of their polymorphic behavior.
	void Legend_attack(int number_require, Animal* animals[2][5],
			Player currentPlayer);
	//************************************************************************
	/**
	 * You may add data members and functions to this class to help you implement the Special Moves part.
	 */
	 
};

#endif /* GAME_H_ */
