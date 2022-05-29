/*
 * Cerberus.h
 *
 *  Created on: 2015年11月20日
 *      Author: user
 */
#ifndef CERBERUS_H
#define CERBERUS_H

#include "Legend_animal.h"
#include "defence_animal.h"

class Cerberus: public Legend_animal,public defence_animal{
public:
	Cerberus(Game* game, int player, int position);
	virtual ~Cerberus();
	virtual void defend(Animal* opponent, int damage);
	virtual void attack();
	void Bite();
private:
	static const int MAX_HP = 60;
	static const int DEFAULT_ATK_DAMAGE = 6;
	int bleed_possible;
};

#endif



