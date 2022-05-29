/*
 * Army_Ant.cpp
 *
 *  Created on: 12 Nov 2015
 *      Author: sfuab
 */

#include "ArmyAnt.h"

ArmyAnt::ArmyAnt(Game* game, int player, int position): Animal(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "ArmyAnt";

}

ArmyAnt::~ArmyAnt() {

}

void ArmyAnt::attack()
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

void ArmyAnt::marchAndConquer(){
	for(int i = 0; i < 5; i++)
		if(!enemies[i]->isDead())
			enemies[i]->takeDamage(CONQUER_DAMAGE);
}

void ArmyAnt::setHP(int amount){
	if(amount <= 0){
		is_dead = true;
	}else if(amount > MAX_HP)
		hp = MAX_HP;
	else
		hp = amount;
}



