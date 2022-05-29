/*
 * Phoenix.h
 *
 *  Created on: 2015年11月20日
 *      Author: user
 */
#ifndef PHOENIX_H
#define PHOENIX_H

#include "Flying_animal.h"
#include "Legend_animal.h"

class Phoenix: public Flying_animal, public Legend_animal{
public:
	Phoenix(Game* game, int player, int position);
	virtual ~Phoenix();
	virtual void takeDamage(int damage);
	virtual void defend(Animal* opponent, int damage);
	virtual void attack();
	void revive();
	void ignite();
private:
	static const int MAX_HP = 50;
	static const int DEFAULT_ATK_DAMAGE = 7;
	int Life;
	int ignite_possibility;
};
#endif
