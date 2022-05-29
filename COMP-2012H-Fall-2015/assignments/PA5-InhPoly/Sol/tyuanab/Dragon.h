/*
 * Dragon.h
 *
 *  Created on: 2015年11月14日
 *      Author: user
 */

#ifndef DRAGON_H_
#define DRAGON_H_

#include "Flying_animal.h"
#include "Legend_animal.h"

class Dragon: public Flying_animal, public Legend_animal {
public:
	Dragon(Game* game, int player, int position);
	virtual ~Dragon();
	virtual void attack();	void setDragonMode(int damage);
private:
	static const int MAX_HP = 40;
	static const int DEFAULT_ATK_DAMAGE = 4;
};

#endif /* DRAGON_H_ */



