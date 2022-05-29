/*
 * Swimming_animal.cpp
 *
 *  Created on: 2015年11月20日
 *      Author: user
 */

#include "Swimming_animal.h"

Swimming_animal::Swimming_animal(Game* game, int player, int position) :
Animal(game, player, position),
	Normal_att_animal(game, player, position){
	Attribute[2] = 1;
}
Swimming_animal::~Swimming_animal() {
}




