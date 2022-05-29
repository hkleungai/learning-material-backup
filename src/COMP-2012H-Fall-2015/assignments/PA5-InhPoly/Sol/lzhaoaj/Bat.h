/*
 * Bat.h
 *
 *  Created on: 2015Äê11ÔÂ20ÈÕ
 *      Author: Lucen
 */


#ifndef BAT_H_
#define BAT_H_

#include "SkyAnimal.h"

class Bat: public SkyAnimal{
public:
	Bat(Game* game, int player, int position);
	virtual ~Bat();

	virtual void attack();
	virtual void defend(Animal* opponent, int damage);

	virtual void Harass();

private:
	static const int MAX_HP = 20;
	static const int DEFAULT_ATK_DAMAGE = 4;
};



#endif /* BAT_H_ */
