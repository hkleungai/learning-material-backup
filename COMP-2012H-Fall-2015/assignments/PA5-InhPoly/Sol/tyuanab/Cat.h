/*
 * Cat.h
 *
 *  Created on: 2015年11月14日
 *      Author: user
 */
#ifndef CAT_H_
#define CAT_H_

#include "Normal_att_animal.h"

class Cat: public Normal_att_animal {
public:
	Cat(Game* game, int player, int position);
	virtual ~Cat();
	virtual void attack();
	virtual void special_attack();
private:
	static const int MAX_HP = 25;
	static const int DEFAULT_ATK_DAMAGE = 6;
};

#endif /* CAT_H_ */




