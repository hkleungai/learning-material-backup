/*
 * Flying_animal.cpp
 *
 *  Created on: 2015年11月16日
 *      Author: user
 */
/*
 * Flying_animal.cpp
 *
 *  Created on: 2015年11月15日
 *      Author: user
 */

#include "Flying_animal.h"

Flying_animal::Flying_animal(Game* game, int player, int position) :
	Animal(game, player, position),
	Normal_att_animal(game, player, position),
defence_animal(game,player,position){
	Attribute[1] = 1;
	set_defend_ratio(0.8);
}
Flying_animal::~Flying_animal() {
}
//Normal attack

