/*
 * Hawk.h
 *
 *  Created on: 12 Nov 2015
 *      Author: sfuab
 */

#ifndef HAWK_H_
#define HAWK_H_

#include "FlyAnimal.h"
#include <iostream>

class Hawk: public FlyAnimal {
public:
	Hawk(Game* game, int player, int position);
	virtual ~Hawk();

	virtual void attack();
	virtual void defend(Animal* opponent, int damage);

private:
	static const int MAX_HP = 25;
	static const int DEFAULT_ATK_DAMAGE = 5;
	static const float DAMAGE_RATE = 0.7;
	static const int REVENGE_DAMAGE = 1;
};




#endif /* HAWK_H_ */
