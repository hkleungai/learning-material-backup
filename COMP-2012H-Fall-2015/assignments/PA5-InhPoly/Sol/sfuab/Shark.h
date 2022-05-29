/*
 * Shark.h
 *
 *  Created on: 12 Nov 2015
 *      Author: sfuab
 */

#ifndef SHARK_H_
#define SHARK_H_

#include "SwimmingAnimal.h"

class Shark: public SwimmingAnimal {
public:
	Shark(Game* game, int player, int position);
	virtual ~Shark();

	virtual void attack();
	virtual void defend(Animal* opponent, int damage);
	virtual void summonTsunami();

private:
	static const int MAX_HP = 30;
	static const int DEFAULT_ATK_DAMAGE = 7;
	static const int REVENGE_DAMAGE = 2;
	static const int SELF_DAMAGE = 1;
	const static int SUMMON_DAMAGE = 2;
	const static int SUMMON_SELF_DAMAGE = 2;
};




#endif /* SHARK_H_ */
