/*
 * FlyAnimal.cpp
 *
 *  Created on: 13 Nov 2015
 *      Author: sfuab
 */

#include "FlyAnimal.h"

FlyAnimal::FlyAnimal(Game* game, int player, int position):
	Animal(game,player,position){}

FlyAnimal::~FlyAnimal() {

}

void FlyAnimal::attack()
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


void FlyAnimal::defend(Animal* opponent, int damage){
	takeDamage(damage_rate * damage);
}

int FlyAnimal::harass(){
	int count = 0;
	for(int i = 0; i < 5; i++)
		if(!enemies[i]->isDead()){
			enemies[i]->takeDamage(harass_damage);
			count++;
		}
}












