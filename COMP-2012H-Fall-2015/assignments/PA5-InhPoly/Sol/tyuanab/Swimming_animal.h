/*
 * Swimming_animal.h
 *
 *  Created on: 2015年11月20日
 *      Author: user
 */
#ifndef SWIMMING_ANIMAL_H_
#define SWIMMING_ANIMAL_H_
#include "Normal_att_animal.h"

class Swimming_animal: public virtual Normal_att_animal{
public:
	Swimming_animal(Game* game, int player, int position);
	virtual ~Swimming_animal();
};
#endif




