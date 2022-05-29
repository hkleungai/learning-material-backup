/*
 * defence_animal.h
 *
 *  Created on: 2015年11月15日
 *      Author: user
 */
#ifndef DEFENCE_ANIMAL_H_
#define DEFENCE_ANIMAL_H_
#include "Animal.h"

class defence_animal: public virtual Animal{
public:
	defence_animal(Game* game, int player, int position);
	virtual ~defence_animal();
	virtual void defend(Animal* opponent, int damage);
	void set_defend_ratio(double);
private:
	double defend_ratio;
};
#endif


