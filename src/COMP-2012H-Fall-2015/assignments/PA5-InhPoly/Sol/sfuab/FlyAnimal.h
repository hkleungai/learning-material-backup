/*
 * FlyAnimal.h
 *
 *  Created on: 13 Nov 2015
 *      Author: sfuab
 */

#ifndef FLYANIMAL_H_
#define FLYANIMAL_H_

#include "Animal.h"

class FlyAnimal: public virtual Animal {
public:
	FlyAnimal(Game* game, int player, int position);
	virtual ~FlyAnimal();

	virtual void attack();
	virtual void defend(Animal* opponent, int damage);
	virtual int harass();

protected:
	int harass_damage;
	float damage_rate;
	static const float DAMAGE_RATE = 0.8;
	static const int HARASS_DAMAGE = 1;
};



#endif /* FLYANIMAL_H_ */
