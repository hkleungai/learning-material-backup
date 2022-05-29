/*
 * Land_animal.h
 *
 *  Created on: 2015年11月15日
 *      Author: user
 */
#ifndef NORMAL_ATT_ANIMAL_H_
#define NORMAL_ATT_ANIMAL_H_
#include "Animal.h"
//attack normally
class Normal_att_animal: public virtual Animal{
public:
	Normal_att_animal(Game* game, int player, int position);
	virtual ~Normal_att_animal();
	virtual void attack();
	virtual void special_attack();
	void setSpecialDamage(int k);
protected:
	int special_damage;
};
#endif






