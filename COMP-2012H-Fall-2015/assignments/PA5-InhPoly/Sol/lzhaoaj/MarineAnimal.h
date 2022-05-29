/*
 * MarineAnimal.h
 *
 *  Created on: 2015Äê11ÔÂ20ÈÕ
 *      Author: Lucen
 */

#ifndef MARINEANIMAL_H_
#define MARINEANIMAL_H_

#include "AnimalAtk.h"

class MarineAnimal: public virtual AnimalAtk{
public:
	virtual ~MarineAnimal();
	//overrided, return true here (since it's the base class for all marine animals)
	virtual bool isMarineAnimal() const;
	//check whether can summon tsunami
	virtual bool canSummonTsunami() const;
	//function for special move (derived from SpecialAttack() in AnimalAtk class)
	virtual void SummonTsunami();

protected:
	MarineAnimal(Game* game, int player, int position);
};



#endif /* MARINEANIMAL_H_ */
