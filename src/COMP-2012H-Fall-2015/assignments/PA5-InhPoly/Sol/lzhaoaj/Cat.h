/*
 * Cat.h
 *
 *  Created on: 2015Äê11ÔÂ19ÈÕ
 *      Author: Lucen
 */


#ifndef CAT_H_
#define CAT_H_

#include "AnimalAtk.h"

class Cat: public AnimalAtk {
public:
	Cat(Game* game, int player, int position);
	virtual ~Cat();
	virtual void attack();

private:
	static const int MAX_HP = 25;
	static const int DEFAULT_ATK_DAMAGE = 6;
};

#endif /* CAT_H_ */
