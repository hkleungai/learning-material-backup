/*
 * ArmyAntQueen.h
 *
 *  Created on: 2015Äê11ÔÂ20ÈÕ
 *      Author: Lucen
 */

#ifndef ARMYANTQUEEN_H_
#define ARMYANTQUEEN_H_

#include "AntAnimal.h"

class ArmyAntQueen: public AntAnimal{
public:
	ArmyAntQueen(Game* game, int player, int position);
	virtual ~ArmyAntQueen();

	virtual void attack();
	virtual void defend(Animal* opponent, int damage);

private:
	static const int MAX_HP = 15;
	static const int DEFAULT_ATK_DAMAGE = 0;
};



#endif /* ARMYANTQUEEN_H_ */
