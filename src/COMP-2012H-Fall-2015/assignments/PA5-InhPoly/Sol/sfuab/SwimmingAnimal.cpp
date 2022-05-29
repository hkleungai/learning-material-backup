/*
 * SwimmingAnimal.cpp
 *
 *  Created on: 14 Nov 2015
 *      Author: sfuab
 */

#include "SwimmingAnimal.h"

SwimmingAnimal::SwimmingAnimal(Game* game, int player, int position):
	Animal(game,player,position){}

SwimmingAnimal::~SwimmingAnimal() {

}

void SwimmingAnimal::attack()
{
	if(!enemies[pos]->isDead())
		enemies[pos]->defend(this, atk_damage);
	else {
		for(int i = 1; i < 5; i++)
		{
			if(pos-i >= 0 && !enemies[pos-i]->isDead())
			{
				enemies[pos-i]->defend(this, atk_damage);
				break;
			}
			else if(pos+i < 5 && !enemies[pos+i]->isDead())
			{
				enemies[pos+i]->defend(this, atk_damage);
				break;
			}
		}
	}
}

void SwimmingAnimal::summonTsunami(){
	for(int i = 0; i < 5; i++)
		if(!enemies[i]->isDead())
			enemies[i]->takeDamage(summon_damage);
}
