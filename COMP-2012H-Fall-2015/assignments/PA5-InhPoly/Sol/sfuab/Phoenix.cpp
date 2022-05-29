/*
 * Phoenix.cpp
 *
 *  Created on: 16 Nov 2015
 *      Author: sfuab
 */

#include "Phoenix.h"


Phoenix::Phoenix(Game* game, int player, int position): Animal(game,player,position),
FlyAnimal(game,player,position), LegendaryAnimal(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Phoenix";
	harass_damage = HARASS_DAMAGE;
	damage_rate = DAMAGE_RATE;
	revive = false;
}

Phoenix::~Phoenix() {

}

void Phoenix::die(){
	if(!revive){
			hp = MAX_HP;
			revive = true;
			is_dead = false;
	}else
		is_dead = true;
}
