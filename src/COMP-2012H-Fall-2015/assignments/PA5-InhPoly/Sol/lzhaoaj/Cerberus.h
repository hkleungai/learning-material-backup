/*
 * Cerberus.h
 *
 *  Created on: 2015Äê11ÔÂ21ÈÕ
 *      Author: Lucen
 */

#ifndef CERBERUS_H_
#define CERBERUS_H_

#include "LegendAnimal.h"
#include "DogAnimal.h"

class Cerberus: public LegendAnimal, public DogAnimal{
public:
	Cerberus(Game* game, int player, int position);
	virtual ~Cerberus();

	virtual void attack();
	virtual void defend(Animal* opponent, int damage);
	virtual void takeDamage(int damage);
	void Cannibal();
private:
	static const int MAX_HP = 35;
	static const int DEFAULT_ATK_DAMAGE = 7;
};


#endif /* CERBERUS_H_ */
