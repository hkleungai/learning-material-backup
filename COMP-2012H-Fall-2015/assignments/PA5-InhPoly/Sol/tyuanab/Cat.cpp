/*
 * Cat.cpp
 *
 *  Created on: 2015年11月14日
 *      Author: user
 */
#include "Cat.h"

Cat::Cat(Game* game, int player, int position):
Animal(game, player, position),
Normal_att_animal(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Cat";
	setSpecialDamage(0);
}

Cat::~Cat() {

}

void Cat::attack()
{
	if(hp < 13)
		atk_damage *= 1.5;
	Normal_att_animal::attack();
}
void Cat::special_attack(){//No special_attack for cat
	return;
}



