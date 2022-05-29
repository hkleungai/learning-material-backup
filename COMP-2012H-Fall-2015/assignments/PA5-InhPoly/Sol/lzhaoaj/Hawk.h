/*
 * Hawk.h
 *
 *  Created on: 2015Äê11ÔÂ19ÈÕ
 *      Author: Lucen
 */


#ifndef HAWK_H_
#define HAWK_H_

#include "SkyAnimal.h"

class Hawk: public SkyAnimal{
public:
	Hawk(Game* game, int player, int position);
	virtual ~Hawk();

	virtual void attack();
	virtual void defend(Animal* opponent, int damage);

private:
	static const int MAX_HP = 25;
	static const int DEFAULT_ATK_DAMAGE = 5;
};



#endif /* HAWK_H_ */
