/*
 * Turtle.cpp
 *
 *  Created on: 12 Nov 2015
 *      Author: sfuab
 */

#include "Turtle.h"

Turtle::Turtle(Game* game, int player, int position): SwimmingAnimal(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Turtle";
	summon_damage = SUMMON_DAMAGE;
}

Turtle::~Turtle() {

}

void Turtle::defend(Animal* opponent, int damage){
	takeDamage(DAMAGE_RATE * damage);
}
