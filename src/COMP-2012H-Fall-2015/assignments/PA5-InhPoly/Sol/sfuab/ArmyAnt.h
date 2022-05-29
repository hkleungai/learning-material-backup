/*
 * Army_Ant.h
 *
 *  Created on: 12 Nov 2015
 *      Author: sfuab
 */

#ifndef ARMYANT_H_
#define ARMYANT_H_

#include "Animal.h"
#include <iostream>
using namespace std;

class ArmyAnt: public Animal{
public:
	ArmyAnt(Game* game, int player, int position);
	virtual ~ArmyAnt();

	virtual void attack();
	virtual void marchAndConquer();
	void setHP(int amount);


protected:
	static const int MAX_HP = 15;
	static const int DEFAULT_ATK_DAMAGE = 1;
	static const int CONQUER_DAMAGE = 3;
};





#endif /* ARMYANT_H_ */
