#ifndef DOG_H_
#define DOG_H_

#include "Animal.h"

class Dog: public virtual Animal {
public:
	Dog(Game* game, int player, int position);
	virtual ~Dog();

	virtual void attack();
	virtual void groupAttack();
	virtual int getGDamage()const{return group_damage;}

protected:
	int group_damage;

private:
	static const int MAX_HP = 30;
	static const int DEFAULT_ATK_DAMAGE = 5;
	static const int DEFAULT_GROUP_DAMAGE = 1;
};

#endif /* DOG_H_ */
