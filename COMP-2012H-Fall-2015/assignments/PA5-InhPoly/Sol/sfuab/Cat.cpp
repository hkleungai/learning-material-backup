/*
 * Cat.cpp
 *
 *  Created on: 12 Nov 2015
 *      Author: sfuab
 */

#include "Cat.h"

Cat::Cat(Game* game, int player, int position): Animal(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Cat";

}

Cat::~Cat() {

}

void Cat::attack()
{
	if(hp < 13)
		atk_damage = DEFAULT_ATK_DAMAGE * ATTACK_RATE;
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



