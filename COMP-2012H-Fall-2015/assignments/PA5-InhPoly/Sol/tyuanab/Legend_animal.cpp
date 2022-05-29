/*
 * Legend_animal.cpp
 *
 *  Created on: 2015年11月17日
 *      Author: user
 */
#include "Legend_animal.h"

Legend_animal::Legend_animal(Game* game, int player, int position)
:Animal(game, player, position),
 Normal_att_animal(game, player, position){
	Attribute[4] = 1;
	setSpecialDamage(3);
}
Legend_animal::~Legend_animal(){
}
