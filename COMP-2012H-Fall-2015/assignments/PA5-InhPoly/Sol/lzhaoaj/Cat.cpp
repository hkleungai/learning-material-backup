/*
 * Cat.cpp
 *
 *  Created on: 2015Äê11ÔÂ19ÈÕ
 *      Author: Lucen
 */

#include "Cat.h"

Cat::Cat(Game* game, int player, int position): AnimalAtk(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Cat";
}

Cat::~Cat() {

}

void Cat::attack() {
	if (hp < 13)
		atk_damage = 1.5 * DEFAULT_ATK_DAMAGE;
	AnimalAtk::attack();
}

