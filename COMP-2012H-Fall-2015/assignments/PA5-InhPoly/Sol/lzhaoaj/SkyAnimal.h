/*
 * SkyAnimal.h
 *
 *  Created on: 2015Äê11ÔÂ20ÈÕ
 *      Author: Lucen
 */

#ifndef SKYANIMAL_H_
#define SKYANIMAL_H_

#include "AnimalAtk.h"

class SkyAnimal: public virtual AnimalAtk{
public:
	virtual ~SkyAnimal();
	//overrided, return true here (since it's the base class for all sky animals)
	virtual bool isSkyAnimal() const;
	//check whether can harass
	virtual bool canHarass() const;
	//function for special move (derived from SpecialAttack() in AnimalAtk class)
	virtual void Harass();

protected:
	SkyAnimal(Game* game, int player, int position);
};



#endif /* SKYANIMAL_H_ */
