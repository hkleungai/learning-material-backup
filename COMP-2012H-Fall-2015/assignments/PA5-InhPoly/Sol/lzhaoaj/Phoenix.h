/*
 * Phoenix.h
 *
 *  Created on: 2015Äê11ÔÂ21ÈÕ
 *      Author: Lucen
 */

#ifndef PHOENIX_H_
#define PHOENIX_H_

#include "LegendAnimal.h"
#include "SkyAnimal.h"

class Phoenix: public LegendAnimal, public SkyAnimal{
public:
	Phoenix(Game* game, int player, int position);
	virtual ~Phoenix();

	//all revenges are useless to Phoenix, which means its hp will not decrease after a revenge
	virtual void attack();
	//Takes only 70% of the damages as flying animals are agile
	virtual void defend(Animal* opponent, int damage);
	//overrided takeDamage. When it dies, if revived == false, it will be revived.
	virtual void takeDamage(int damage);
	//function for revive. Get full hp and change revived to true.
	void revive();

private:
	bool revived;
	static const int MAX_HP = 25;
	static const int DEFAULT_ATK_DAMAGE = 5;
};


#endif /* PHOENIX_H_ */
