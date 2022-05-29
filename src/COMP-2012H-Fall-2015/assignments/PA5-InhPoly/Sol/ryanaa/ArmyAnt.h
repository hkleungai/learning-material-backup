#ifndef ARMY_ANT_H_
#define ARMY_ANT_H_

#include "Animal.h"

class ArmyAnt: virtual public Animal {
public:
	ArmyAnt(Game* game, int player, int position);
	virtual ~ArmyAnt();
	virtual void attack();
	virtual void marchAndConquer();
	virtual void heal(int i);

private:
	static const int MAX_HP = 15;
	static const int DEFAULT_ATK_DAMAGE = 1;
};

#endif /* ARMY_ANT_H_ */
