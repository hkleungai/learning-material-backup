/*
 * Cerberus.h
 *
 *  Created on: 16 Nov 2015
 *      Author: sfuab
 */

#ifndef CERBERUS_H_
#define CERBERUS_H_

#include "Dog.h"
#include "LegendaryAnimal.h"

class Cerberus: public Dog, public LegendaryAnimal{
public:
	Cerberus(Game* game, int player, int position);
	virtual ~Cerberus();

private:
	static const int DEFAULT_ATK_DAMAGE = 6;
	static const int MAX_HP = 42;
	static const int GROUP_DAMAGE = 2;

};




#endif /* CERBERUS_H_ */
