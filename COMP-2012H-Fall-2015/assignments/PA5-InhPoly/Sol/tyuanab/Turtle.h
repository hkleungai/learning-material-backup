/*
 * Turtle.h
 *
 *  Created on: 2015年11月14日
 *      Author: user
 */
#ifndef TURTLE_H_
#define TURTLE_H_

#include "defence_animal.h"
#include "Swimming_animal.h"

class Turtle: public Swimming_animal, public defence_animal {
public:
	Turtle(Game* game, int player, int position);
	virtual ~Turtle();
private:
	static const int MAX_HP = 35;
	static const int DEFAULT_ATK_DAMAGE = 2;
};

#endif /* TURTLE_H_ */




