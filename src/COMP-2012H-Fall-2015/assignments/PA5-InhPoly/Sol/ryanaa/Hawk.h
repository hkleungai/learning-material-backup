#ifndef HAWK_H_
#define HAWK_H_

#include "Flying_Animals.h"

class Hawk: public Flying_Animals {
public:
	Hawk(Game* game, int player, int position);
	virtual ~Hawk();

	virtual void attack();
	virtual void defend(Animal* opponent, int damage);
	virtual void harass();

private:
	static const int MAX_HP = 25;
	static const int DEFAULT_ATK_DAMAGE = 5;
};

#endif /* HAWK_H_ */
