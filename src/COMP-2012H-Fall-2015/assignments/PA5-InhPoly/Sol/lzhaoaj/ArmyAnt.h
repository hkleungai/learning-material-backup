/*
 * ArmyAnt.h
 *
 *  Created on: 2015Äê11ÔÂ20ÈÕ
 *      Author: Lucen
 */

#ifndef ARMYANT_H_
#define ARMYANT_H_

#include "AntAnimal.h"
#include "AnimalAtk.h"

class ArmyAnt: public AntAnimal {
public:
	ArmyAnt(Game* game, int player, int position);
	virtual ~ArmyAnt();

	virtual void MarchAndConquer();

private:
	static const int MAX_HP = 15;
	static const int DEFAULT_ATK_DAMAGE = 1;
};



#endif /* ARMYANT_H_ */
