#ifndef DOG_H_
#define DOG_H_

#include "Animal.h"

class Dog: virtual public Animal {
public:
	Dog(Game* game, int player, int position);
	virtual ~Dog();
	virtual void attack();
	virtual void groupAttack();

private:
	static const int MAX_HP = 30;
	static const int DEFAULT_ATK_DAMAGE = 5;
};

#endif /* DOG_H_ */
