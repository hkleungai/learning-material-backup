/*
 * DogAnimal.h
 *
 *  Created on: 2015Äê11ÔÂ21ÈÕ
 *      Author: Lucen
 */

#ifndef DOGANIMAL_H_
#define DOGANIMAL_H_

#include "AnimalAtk.h"

class DogAnimal: public virtual AnimalAtk{
public:
	virtual ~DogAnimal();
	//overrided, return true here (since it's the base class for all dog animals)
	virtual bool isDogAnimal() const;
	//check whether can group attack
	virtual bool canGroupAttack() const;
	//function for special move (derived from SpecialAttack() in AnimalAtk class)
	virtual void GroupAttack();
protected:
	DogAnimal(Game* game, int player, int position);
};



#endif /* DOGANIMAL_H_ */
