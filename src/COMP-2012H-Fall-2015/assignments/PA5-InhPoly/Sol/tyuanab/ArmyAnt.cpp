/*
 * ArmyAnt.cpp
 *
 *  Created on: 2015年11月14日
 *      Author: user
 */
#include "ArmyAnt.h"

ArmyAnt::ArmyAnt(Game* game, int player, int position):
Animal(game, player, position),
Normal_att_animal(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "ArmyAnt";
	Attribute[3] = 1;
	setSpecialDamage(3);
}

ArmyAnt::~ArmyAnt() {
}





