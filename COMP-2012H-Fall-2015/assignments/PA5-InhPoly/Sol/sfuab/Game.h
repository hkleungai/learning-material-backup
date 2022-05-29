#ifndef GAME_H_
#define GAME_H_

#include "Animal.h"
#include <cstdlib>
class Animal;


class Game {
public:
	enum Player {P1 = 0, P2 = 1 };
	enum AnimalIds {DOG, CAT, HAWK, BAT, TURTLE, SHARK, ARMY_ANT, ARMY_ANT_QUEEN, DRAGON, PHOENIX, CERBERUS, BOACONSTRICTOR };
	Animal* animals[2][5];

	Game(std::string file);
	virtual ~Game();

	void load(std::string file);
	bool isEnd();
	void start();

	/**
	 * You may add data members and functions to this class to help you implement the Special Moves part.
	 */

private:
	bool have_queen[2], have_boa[2];
	void harass(Player currentPlayer, int grab_position);
	void summonTsunami(Player currentPlayer, int grab_position);
	void marchAndConquer(Player currentPlayer, int grab_position);
	void storm(Player currentPlayer, int grab_position);
	void groupAttack(Player currentPlayer, int grab_position);
	 
};

#endif /* GAME_H_ */
