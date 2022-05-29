#ifndef LEGENDARY_ANIMALS_H_
#define LEGENDARY_ANIMALS_H_

#include "Animal.h"


class Legendary_Animals: virtual public Animal {
public:
	Legendary_Animals(Game* game, int player, int position);
	virtual ~Legendary_Animals();
	virtual void storm()=0;
};

#endif /* LEGENDARY_ANIMALS_H_ */
