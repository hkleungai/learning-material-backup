/*
 * Dragon.h
 *
 *  Created on: 2015Äê11ÔÂ20ÈÕ
 *      Author: Lucen
 */


#ifndef DRAGON_H_
#define DRAGON_H_

#include "SkyAnimal.h"
#include "LegendAnimal.h"

class Dragon: public SkyAnimal, public LegendAnimal {
public:
	Dragon(Game* game, int player, int position);
	virtual ~Dragon();

	virtual void attack();
	virtual void defend(Animal* opponent, int damage);

private:
	static const int MAX_HP = 40;
	static const int DEFAULT_ATK_DAMAGE = 4;
};



#endif /* DRAGON_H_ */
