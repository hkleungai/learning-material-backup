/*
 * Turtle.cpp
 *
 *  Created on: 2015Äê11ÔÂ20ÈÕ
 *      Author: Lucen
 */

#include "Turtle.h"

Turtle::Turtle(Game* game, int player, int position): AnimalAtk(game,player,position),MarineAnimal(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Turtle";
}

Turtle::~Turtle() {

}

void Turtle::defend(Animal* opponent, int damage){
	takeDamage(damage*0.5);
}

