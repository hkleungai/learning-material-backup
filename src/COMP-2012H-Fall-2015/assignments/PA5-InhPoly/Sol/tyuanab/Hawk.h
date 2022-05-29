/*
 * Hawk.h
 *
 *  Created on: 2015年11月14日
 *      Author: user
 */
#ifndef HAWK_H_
#define HAWK_H_

#include "Flying_animal.h"

class Hawk: public Flying_animal {
public:
	Hawk(Game* game, int player, int position);
	virtual ~Hawk();

	virtual void attack();
	virtual void defend(Animal * opponent, int damage);
private:
	static const int MAX_HP = 25;
	static const int DEFAULT_ATK_DAMAGE = 5;
};

#endif /* HAWK_H_ */




