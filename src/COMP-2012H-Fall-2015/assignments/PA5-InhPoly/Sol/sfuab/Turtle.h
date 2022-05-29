/*
 * Turtle.h
 *
 *  Created on: 12 Nov 2015
 *      Author: sfuab
 */

#ifndef TURTLE_H_
#define TURTLE_H_

#include "SwimmingAnimal.h"

class Turtle: public SwimmingAnimal {
public:
	Turtle(Game* game, int player, int position);
	virtual ~Turtle();

	virtual void defend(Animal* opponent, int damage);

private:
	static const int MAX_HP = 35;
	static const int DEFAULT_ATK_DAMAGE = 2;
	static const float DAMAGE_RATE = 0.5;
};




#endif /* TURTLE_H_ */
