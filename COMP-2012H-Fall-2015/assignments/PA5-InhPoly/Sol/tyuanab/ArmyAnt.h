/*
 * ArmyAnt.h
 *
 *  Created on: 2015年11月14日
 *      Author: user
 */
#ifndef ARMYANT_H_
#define ARMYANT_H_

#include "Normal_att_animal.h"

class ArmyAnt: public Normal_att_animal {
public:
	ArmyAnt(Game* game, int player, int position);
	virtual ~ArmyAnt();
private:
	static const int MAX_HP = 15;
	static const int DEFAULT_ATK_DAMAGE = 1;
};

#endif /* ARMYANT_H_ */




