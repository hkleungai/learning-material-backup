/*
 * defenceing_animal.cpp
 *
 *  Created on: 2015年11月15日
 *      Author: user
 */

#include "defence_animal.h"

defence_animal::defence_animal(Game* game, int player, int position)
	:Animal(game, player, position){
	defend_ratio = 1;
}
defence_animal::~defence_animal()
{
}
void defence_animal::defend(Animal* opponent, int damage)
{
	takeDamage(defend_ratio * damage);
}
void defence_animal::set_defend_ratio(double dr){
	defend_ratio = dr;
}

