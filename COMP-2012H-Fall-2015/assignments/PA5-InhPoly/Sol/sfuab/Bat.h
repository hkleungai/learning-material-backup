/*
 * Bat.h
 *
 *  Created on: 12 Nov 2015
 *      Author: sfuab
 */

#ifndef BAT_H_
#define BAT_H_

#include "FlyAnimal.h"

class Bat: public FlyAnimal {
public:
	Bat(Game* game, int player, int position);
	virtual ~Bat();

	virtual void attack();
	virtual int harass();
	void drain();

private:
	static const int MAX_HP = 20;
	static const int DEFAULT_ATK_DAMAGE = 4;
};




#endif /* BAT_H_ */
