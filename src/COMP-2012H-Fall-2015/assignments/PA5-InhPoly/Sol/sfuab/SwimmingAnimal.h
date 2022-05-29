/*
 * SwimmingAnimal.h
 *
 *  Created on: 14 Nov 2015
 *      Author: sfuab
 */

#ifndef SWIMMINGANIMAL_H_
#define SWIMMINGANIMAL_H_

#include "Animal.h"

class SwimmingAnimal: public Animal {
public:
	SwimmingAnimal(Game* game, int player, int position);
	virtual ~SwimmingAnimal();

	virtual void attack();
	virtual void summonTsunami();

protected:
	int summon_damage;
	const static int SUMMON_DAMAGE = 1;
};



#endif /* SWIMMINGANIMAL_H_ */
