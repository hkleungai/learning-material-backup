#ifndef TURTLE_H_
#define TURTLE_H_

#include "Swimming_Animals.h"

class Turtle: public Swimming_Animals {
public:
	Turtle(Game* game, int player, int position);
	virtual ~Turtle();

	virtual void attack();
	virtual void defend(Animal* opponent, int damage);
	virtual void summonTsunami();

private:
	static const int MAX_HP = 35;
	static const int DEFAULT_ATK_DAMAGE = 2;
};

#endif /* TURTLE_H_ */
