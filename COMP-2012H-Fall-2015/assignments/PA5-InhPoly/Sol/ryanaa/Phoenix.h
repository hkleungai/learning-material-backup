#ifndef PHOENIX_H_
#define PHOENIX_H_

#include "Flying_Animals.h"
#include "Legendary_Animals.h"
class Phoenix: public Flying_Animals, public Legendary_Animals {
public:
	Phoenix(Game* game, int player, int position);
	virtual ~Phoenix();

	virtual void attack();
	virtual void defend(Animal* opponent, int damage);
	virtual void harass();
	virtual void takeDamage(int damage);
	void revive();
	virtual void storm();
	
private:
	static const int MAX_HP = 50;
	static const int DEFAULT_ATK_DAMAGE = 5;
	int reviveCnt;
};

#endif /* PHOENIX_H_ */
