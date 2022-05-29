#ifndef SHARK_H_
#define SHARK_H_

#include "Swimming_Animals.h"

class Shark: public Swimming_Animals {
public:
	Shark(Game* game, int player, int position);
	virtual ~Shark();

	virtual void attack();
	virtual void defend(Animal* opponent, int damage);
	virtual void summonTsunami();

private:
	static const int MAX_HP = 30;
	static const int DEFAULT_ATK_DAMAGE = 7;
};

#endif /* SHARK_H_ */
