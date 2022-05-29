#ifndef GAME_H_
#define GAME_H_

//#include "Animal.h"
// #include "Flying_Animals.h"
// #include "Swimming_Animals.h"
//#include "ArmyAnt.h"
class Animal;
class Flying_Animals;
class Swimming_Animals;
class Legendary_Animals;
class ArmyAnt;

class Game {
public:
	enum Player {P1 = 0, P2 = 1 };
	enum AnimalIds {DOG, CAT, HAWK, BAT, TURTLE, SHARK, ARMY_ANT, ARMY_ANT_QUEEN, DRAGON, PHOENIX, CERBERUS };
	Animal* animals[2][5];
	ArmyAnt* armyAnts[2][5];
	Flying_Animals* flyAnimals[2][5];
	Swimming_Animals* swimAnimals[2][5];
	Legendary_Animals* legendAnimals[2][5];

	Game(std::string file);
	virtual ~Game();

	void load(std::string file);
	bool isEnd();
	void start();

	/**
	 * You may add data members and functions to this class to help you implement the Special Moves part.
	 */

private:
	int antc[2],flyc[2],swimc[2],legc[2];
	 
};

#endif /* GAME_H_ */
