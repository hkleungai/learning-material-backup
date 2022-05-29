#ifndef CERBERUS_H_
#define CERBERUS_H_

#include "Dog.h"
#include "Legendary_Animals.h"
class Cerberus: public Dog, public Legendary_Animals {
public:
	Cerberus(Game* game, int player, int position);
	virtual ~Cerberus();

	virtual void attack();
	virtual void defend(Animal* opponent, int damage);
	virtual void groupAttack();
	virtual void storm();

private:
	static const int MAX_HP = 60;
	static const int DEFAULT_ATK_DAMAGE = 4;
	;
};

#endif /* CERBERUS_H_ */
