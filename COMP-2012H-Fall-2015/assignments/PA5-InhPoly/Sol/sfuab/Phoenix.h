/*
 * Phoenix.h
 *
 *  Created on: 16 Nov 2015
 *      Author: sfuab
 */

#ifndef PHOENIX_H_
#define PHOENIX_H_

#include "FlyAnimal.h"
#include "LegendaryAnimal.h"
#include <iostream>
using namespace std;

class Phoenix:public FlyAnimal, public LegendaryAnimal{
public:
	Phoenix(Game* game, int player, int position);
	virtual ~Phoenix();
	virtual void die();

private:
	bool revive;
	static const int MAX_HP = 35;
	static const int DEFAULT_ATK_DAMAGE = 4;
	static const int HARASS_DAMAGE = 1;
};



#endif /* PHOENIX_H_ */
