/*
 * AntAnimal.h
 *
 *  Created on: 2015Äê11ÔÂ21ÈÕ
 *      Author: Lucen
 */

#ifndef ANTANIMAL_H_
#define ANTANIMAL_H_

#include "AnimalAtk.h"

class AntAnimal: public virtual AnimalAtk{
public:
	virtual ~AntAnimal();
	//overrided, return true here (since it's the base class for all ant animals)
	virtual bool isAntAnimal() const;
	//check whether can march and conquer
	virtual bool canMarchAndConquer() const;

protected:
	AntAnimal(Game* game, int player, int position);
};



#endif /* ANTANIMAL_H_ */
