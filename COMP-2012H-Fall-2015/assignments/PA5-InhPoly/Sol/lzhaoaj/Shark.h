/*
 * Shark.h
 *
 *  Created on: 2015Äê11ÔÂ20ÈÕ
 *      Author: Lucen
 */

#ifndef SHARK_H_
#define SHARK_H_

#include "MarineAnimal.h"

class Shark: public MarineAnimal{
public:
	Shark(Game* game, int player, int position);
	virtual ~Shark();

	virtual void attack();
	virtual void defend(Animal* opponent, int damage);

private:
	static const int MAX_HP = 30;
	static const int DEFAULT_ATK_DAMAGE = 7;
};



#endif /* SHARK_H_ */
