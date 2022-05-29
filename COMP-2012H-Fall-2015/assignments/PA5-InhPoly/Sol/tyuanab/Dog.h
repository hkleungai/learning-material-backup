#ifndef DOG_H_
#define DOG_H_

#include "Normal_att_animal.h"

class Dog: public Normal_att_animal {
public:
	Dog(Game* game, int player, int position);
	virtual ~Dog();

private:
	static const int MAX_HP = 30;
	static const int DEFAULT_ATK_DAMAGE = 5;
};

#endif /* DOG_H_ */
