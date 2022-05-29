/*
 * Shark.cpp
 *
 *  Created on: 12 Nov 2015
 *      Author: sfuab
 */

#include "Shark.h"

Shark::Shark(Game* game, int player, int position): SwimmingAnimal(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Shark";
	summon_damage = SUMMON_DAMAGE;

}

Shark::~Shark() {

}

void Shark::attack()
{
	SwimmingAnimal::attack();
	if(!isDead())
		takeDamage(SELF_DAMAGE);
}

void Shark::defend(Animal* opponent, int damage){
	takeDamage(damage);
	if(!isDead())
		opponent->takeDamage(REVENGE_DAMAGE);
}

void Shark::summonTsunami(){
	SwimmingAnimal::summonTsunami();
	takeDamage(SUMMON_SELF_DAMAGE);
}
