/*
 * ArmyAntQueenQueen.h
 *
 *  Created on: 2015年11月14日
 *      Author: user
 */

#ifndef ARMYANTQUEEN_H_
#define ARMYANTQUEEN_H_

#include "Normal_att_animal.h"

class ArmyAntQueen: public Normal_att_animal {
public:
	ArmyAntQueen(Game* game, int player, int position);
	virtual ~ArmyAntQueen();
	virtual void attack();
	virtual void defend(Animal* opponent, int damage);
	void heal_ArmyAnt(int); //heal for one ArmyAnt
	virtual void special_attack();
private:
	static const int MAX_HP = 15;
	static const int DEFAULT_ATK_DAMAGE = 0;
	static const int heal_amount = 2;
};

#endif /* ARMYANTQUEEN_H_ */








