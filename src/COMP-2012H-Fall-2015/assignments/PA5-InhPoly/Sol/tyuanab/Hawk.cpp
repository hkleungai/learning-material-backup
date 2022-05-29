/*
 * Hawk.cpp
 *
 *  Created on: 2015年11月14日
 *      Author: user
 */

#include "Hawk.h"

Hawk::Hawk(Game* game, int player, int position):
Animal(game, player, position),
Normal_att_animal(game, player, position),
defence_animal(game,player,position),
Flying_animal(game, player, position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Hawk";
	revenge_damage = 1;
	set_defend_ratio(0.7);
}

Hawk::~Hawk() {

}
void Hawk::attack()
{
	if(!enemies[pos]->isDead())
		enemies[pos]->takeDamage(atk_damage);
	else {
		for(int i = 1; i < 5; i++)
		{
			if(pos-i >= 0 && !enemies[pos-i]->isDead())
			{
				enemies[pos-i]->takeDamage(atk_damage);
				break;
			}
			else if(pos+i < 5 && !enemies[pos+i]->isDead())
			{
				enemies[pos+i]->takeDamage(atk_damage);
				break;
			}
		}
	}
}
void Hawk::defend(Animal * opponent, int damage)
{
	defence_animal::defend(opponent, damage);
	if(!this->isDead())
		revenge(opponent, revenge_damage);
}


