/*
 * LegendaryAnimal.h
 *
 *  Created on: 16 Nov 2015
 *      Author: sfuab
 */

#ifndef LEGENDARYANIMAL_H_
#define LEGENDARYANIMAL_H_

#include "Animal.h"

class LegendaryAnimal: public virtual Animal{
public:
	LegendaryAnimal(Game* game, int player, int position);
	virtual ~LegendaryAnimal();
	void storm();

protected:
	int storm_damage;

private:
	static const int STORM_DAMAGE = 3;
};


#endif /* LEGENDARYANIMAL_H_ */
