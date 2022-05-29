/*
 * Normal_att_animal.cpp
 *
 *  Created on: 2015年11月15日
 *      Author: user
 */

#include "Normal_att_animal.h"

Normal_att_animal::Normal_att_animal(Game* game, int player, int position)
	:Animal(game, player, position){
	special_damage = 1;
}
Normal_att_animal::~Normal_att_animal(){

}
//Normal attack
void Normal_att_animal::attack()
{

	if(!enemies[pos]->isDead())
		enemies[pos]->defend(this, atk_damage);
	else {
		for(int i = 1; i < 5; i++)
		{
			if(pos-i >= 0 && !enemies[pos-i]->isDead())
			{
				enemies[pos-i]->defend(this, atk_damage);
				break;
			}
			else if(pos+i < 5 && !enemies[pos+i]->isDead())
			{
				enemies[pos+i]->defend(this, atk_damage);
				break;
			}
		}
	}
}
void Normal_att_animal::special_attack() {
	for (int pos = 0; pos < 5; pos++) {
		if (!enemies[pos]->isDead())
			enemies[pos]->takeDamage(special_damage);
	}
}
void Normal_att_animal::setSpecialDamage(int k){
	special_damage = k;
}

