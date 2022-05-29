/*
 * Dragon.h
 *
 *  Created on: 12 Nov 2015
 *      Author: sfuab
 */

#ifndef DRAGON_H_
#define DRAGON_H_

#include "FlyAnimal.h"
#include "LegendaryAnimal.h"

class Dragon: public FlyAnimal, public LegendaryAnimal {
public:
	Dragon(Game* game, int player, int position);
	virtual ~Dragon();

	virtual void attack();

private:
	static const int MAX_HP = 40;
	static const int DEFAULT_ATK_DAMAGE = 4;
	static const int HARASS_DAMAGE = 2;
};




#endif /* DRAGON_H_ */
