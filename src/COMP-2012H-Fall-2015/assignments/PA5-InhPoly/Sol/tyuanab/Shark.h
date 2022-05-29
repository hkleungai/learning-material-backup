/*
 * Shark.h
 *
 *  Created on: 2015年11月14日
 *      Author: user
 */
#ifndef SHARK_H_
#define SHARK_H_

#include "Swimming_animal.h"

class Shark: public Swimming_animal {
public:
	Shark(Game* game, int player, int position);
	virtual ~Shark();

	virtual void attack();
	virtual void defend(Animal * opponent, int damage);
	virtual void special_attack();
private:
	static const int MAX_HP = 30;
	static const int DEFAULT_ATK_DAMAGE = 7;
};

#endif /* SHARK_H_ */




