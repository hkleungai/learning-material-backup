#ifndef SWIMMING_ANIMALS_H_
#define SWIMMING_ANIMALS_H_

#include "Animal.h"

class Swimming_Animals: virtual public Animal {
public:
	Swimming_Animals(Game* game, int player, int position);
	virtual ~Swimming_Animals();
	virtual void summonTsunami()=0;
};
#endif /* SWIMMING_ANIMALS_H_ */
