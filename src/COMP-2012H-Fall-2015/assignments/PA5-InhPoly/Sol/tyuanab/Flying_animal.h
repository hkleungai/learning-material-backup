/*
 * Flying_animal.h
 *
 *  Created on: 2015年11月16日
 *      Author: user
 */
/*
 * Flying_animal.h
 *
 *  Created on: 2015年11月15日
 *      Author: user
 */
#ifndef FLYING_ANIMAL_H_
#define FLYING_ANIMAL_H_
#include "Normal_att_animal.h"
#include "defence_animal.h"

class Flying_animal: public virtual Normal_att_animal,
		public virtual defence_animal {
public:
	Flying_animal(Game* game, int player, int position);
	virtual ~Flying_animal();
};
#endif

