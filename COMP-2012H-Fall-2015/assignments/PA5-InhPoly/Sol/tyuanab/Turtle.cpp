/*
 * Turtle.cpp
 *
 *  Created on: 2015年11月14日
 *      Author: user
 */
#include "Turtle.h"

Turtle::Turtle(Game* game, int player, int position):
Animal(game,player,position),
Normal_att_animal(game,player,position),
Swimming_animal(game,player,position),
defence_animal(game,player,position)
{
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Turtle";
	set_defend_ratio (0.5);
}

Turtle::~Turtle() {
}


