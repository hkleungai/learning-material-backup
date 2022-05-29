#ifndef FLYING_ANIMALS_H_
#define FLYING_ANIMALS_H_

#include "Animal.h"

class Flying_Animals: virtual public Animal {
public:
	Flying_Animals(Game* game, int player, int position);
	virtual ~Flying_Animals();
	virtual void harass()=0;
	
};

#endif /* FLYING_ANIMALS_H_ */
