#ifndef BAT_H_
#define BAT_H_

#include "Flying_Animals.h"

class Bat: public Flying_Animals {
public:
	Bat(Game* game, int player, int position);
	virtual ~Bat();

	virtual void attack();
	virtual void defend(Animal* opponent, int damage);
	virtual void harass();

private:
	static const int MAX_HP = 20;
	static const int DEFAULT_ATK_DAMAGE = 4;
	void heal();
};

#endif /* BAT_H_ */
