/*
 * Army_Ant_Queen.h
 *
 *  Created on: 12 Nov 2015
 *      Author: sfuab
 */

#ifndef ARMYANTQUEEN_H_
#define ARMYANTQUEEN_H_

#include "Animal.h"
#include "ArmyAnt.h"
#include <iostream>
using namespace std;

class ArmyAntQueen: public ArmyAnt {
public:
	ArmyAntQueen(Game* game, int player, int position);
	virtual ~ArmyAntQueen();

	virtual void attack();
	virtual void defend(Animal* opponent, int damage);
	virtual void marchAndConquer();

private:
	static const int DEFAULT_ATK_DAMAGE = 0;
	static const int REVENGE_DAMAGE = 2;
	static const int HEAL_AMOUNT = 2;
};




#endif /* ARMYANTQUEEN_H_ */
