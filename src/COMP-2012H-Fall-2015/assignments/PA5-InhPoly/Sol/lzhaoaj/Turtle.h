/*
 * Turtle.h
 *
 *  Created on: 2015Äê11ÔÂ20ÈÕ
 *      Author: Lucen
 */

#ifndef TURTLE_H_
#define TURTLE_H_

#include "MarineAnimal.h"

class Turtle: public MarineAnimal {
public:
	Turtle (Game* game, int player, int position);
	virtual ~Turtle();

	virtual void defend(Animal* opponent, int damage);

private:
	static const int MAX_HP = 35;
	static const int DEFAULT_ATK_DAMAGE = 2;
};

#endif /* TURTLE_H_ */
