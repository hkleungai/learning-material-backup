/*
 * Hawk.cpp
 *
 *  Created on: 12 Nov 2015
 *      Author: sfuab
 */

#include "Hawk.h"

Hawk::Hawk(Game* game, int player, int position):
Animal(game,player,position), FlyAnimal(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Hawk";
	damage_rate = DAMAGE_RATE;
	harass_damage = HARASS_DAMAGE;

}

Hawk::~Hawk() {

}

void Hawk::attack(){
	if(!enemies[pos]->isDead())
			enemies[pos]->takeDamage(atk_damage);
	else {
		for(int i = 1; i < 5; i++)
		{
			if(pos-i >= 0 && !enemies[pos-i]->isDead())
			{
				enemies[pos-i]->takeDamage(atk_damage);
				break;
			}
			else if(pos+i < 5 && !enemies[pos+i]->isDead())
			{
				enemies[pos+i]->takeDamage(atk_damage);
				break;
			}
		}
	}
}

void Hawk::defend(Animal* opponent, int damage){
	FlyAnimal::defend(opponent, damage);
	if(!isDead())
		opponent->takeDamage(REVENGE_DAMAGE);
}










