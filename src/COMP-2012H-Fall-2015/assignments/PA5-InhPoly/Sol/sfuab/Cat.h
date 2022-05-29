/*
 * Cat.h
 *
 *  Created on: 12 Nov 2015
 *      Author: sfuab
 */

#ifndef CAT_H_
#define CAT_H_

#include "Animal.h"

class Cat: public Animal {
public:
	Cat(Game* game, int player, int position);
	virtual ~Cat();

	virtual void attack();

private:
	static const int MAX_HP = 25;
	static const int DEFAULT_ATK_DAMAGE = 6;
	static const float ATTACK_RATE = 1.5;
};



#endif /* CAT_H_ */
