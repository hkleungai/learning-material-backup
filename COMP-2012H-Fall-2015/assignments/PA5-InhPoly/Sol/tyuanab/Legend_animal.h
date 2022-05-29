/*
 * Legend_animal.h
 *
 *  Created on: 2015年11月17日
 *      Author: user
 */

#ifndef LEGEND_ANIMAL_H_
#define LEGEND_ANIMAL_H_

#include "Normal_att_animal.h"

class Legend_animal: public virtual Normal_att_animal{
public:
	Legend_animal(Game* game, int player, int position);
	virtual ~Legend_animal();
};
#endif

