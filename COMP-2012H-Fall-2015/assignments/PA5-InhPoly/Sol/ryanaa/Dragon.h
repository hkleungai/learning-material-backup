#ifndef DRAGON_H_
#define DRAGON_H_

#include "Flying_Animals.h"
#include "Legendary_Animals.h"
class Dragon: public Flying_Animals, public Legendary_Animals{
public:
	Dragon(Game* game, int player, int position);
	virtual ~Dragon();

	virtual void attack();
	virtual void defend(Animal* opponent, int damage);
	virtual void harass();
	virtual void storm();

private:
	static const int MAX_HP = 40;
	static const int DEFAULT_ATK_DAMAGE = 4
	;
};

#endif /* DRAGON_H_ */
