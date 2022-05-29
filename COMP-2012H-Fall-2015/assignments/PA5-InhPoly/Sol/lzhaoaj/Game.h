#ifndef GAME_H_
#define GAME_H_

#include "Animal.h"
class Animal;


class Game {
public:
	enum Player {P1 = 0, P2 = 1 };
	enum AnimalIds {DOG, CAT, HAWK, BAT, TURTLE, SHARK, ARMY_ANT, ARMY_ANT_QUEEN, DRAGON, PHOENIX, CERBERUS };
	Animal* animals[2][5];

	Game(std::string file);
	virtual ~Game();

	void load(std::string file);
	bool isEnd();
	void start();

	/**
	 * You may add data members and functions to this class to help you implement the Special Moves part.
	 */


	 
};

#endif /* GAME_H_ */
