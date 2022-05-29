/*
 * Cerberus.cpp
 *
 *  Created on: 16 Nov 2015
 *      Author: sfuab
 */

#include "Cerberus.h"

Cerberus::Cerberus(Game* game, int player, int position): Animal(game,player,position),
Dog(game,player,position), LegendaryAnimal(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Cerberus";
	group_damage = GROUP_DAMAGE;
}

Cerberus::~Cerberus(){}





