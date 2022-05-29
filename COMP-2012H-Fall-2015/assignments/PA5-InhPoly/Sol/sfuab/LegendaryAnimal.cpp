/*
 * LegendaryAnimal.cpp
 *
 *  Created on: 16 Nov 2015
 *      Author: sfuab
 */

#include "LegendaryAnimal.h"


LegendaryAnimal::LegendaryAnimal(Game* game, int player, int position):
Animal(game,player,position), storm_damage(STORM_DAMAGE){}

LegendaryAnimal::~LegendaryAnimal(){}


void LegendaryAnimal::storm(){
	for(int i = 0; i < 5; i++)
		if(!enemies[i]->isDead())
			enemies[i]->takeDamage(STORM_DAMAGE);
}
