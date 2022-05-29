/*
 * Dragon.cpp
 *
 *  Created on: 12 Nov 2015
 *      Author: sfuab
 */

#include "Dragon.h"

Dragon::Dragon(Game* game, int player, int position): Animal(game,player,position),
FlyAnimal(game,player,position), LegendaryAnimal(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Dragon";
	harass_damage = HARASS_DAMAGE;
	damage_rate = DAMAGE_RATE;
}

Dragon::~Dragon() {

}

void Dragon::attack()
{
	for(int i = -1; i <= 1; i++){
		if((pos + i) >= 0 && (pos + i) < 5 && !enemies[pos + i]->isDead())
			enemies[pos+i]->defend(this, atk_damage);
	}
}


