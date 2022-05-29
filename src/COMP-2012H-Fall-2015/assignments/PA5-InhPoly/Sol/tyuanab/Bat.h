/*
 * Bat.h
 *
 *  Created on: 2015年11月14日
 *      Author: user
 */
#ifndef BAT_H_
#define BAT_H_

#include "Flying_animal.h"

class Bat: public Flying_animal {
public:
	Bat(Game* game, int player, int position);
	virtual ~Bat();
	virtual void attack();
	void drain();
	virtual void special_attack();
private:
	static const int MAX_HP = 20;
	static const int DEFAULT_ATK_DAMAGE = 4;

};

#endif /* BAT_H_ */




