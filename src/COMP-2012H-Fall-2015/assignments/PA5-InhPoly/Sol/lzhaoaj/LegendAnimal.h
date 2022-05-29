/*
 * LegendAnimal.h
 *
 *  Created on: 2015Äê11ÔÂ21ÈÕ
 *      Author: Lucen
 */

#ifndef LEGENDANIMAL_H_
#define LEGENDANIMAL_H_

#include "AnimalAtk.h"

class LegendAnimal: public virtual AnimalAtk{
public:
	virtual ~LegendAnimal();

	//overrided, return true here (since it's the base class for all legend animals)
	virtual bool isLegendAnimal() const;
	//check whether can weather storm
	virtual bool canWeatherStorm() const;
	//function for special move (derived from SpecialAttack() in AnimalAtk class)
	virtual void WeatherStorm();
protected:
	LegendAnimal(Game* game, int player, int position);
};



#endif /* LEGENDANIMAL_H_ */
