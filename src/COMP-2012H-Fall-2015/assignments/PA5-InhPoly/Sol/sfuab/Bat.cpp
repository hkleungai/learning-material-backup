/*
 * Bat.cpp
 *
 *  Created on: 12 Nov 2015
 *      Author: sfuab
 */

#include "Bat.h"

Bat::Bat(Game* game, int player, int position):
Animal(game,player,position),FlyAnimal(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Bat";
	damage_rate = DAMAGE_RATE;
	harass_damage = HARASS_DAMAGE;
}

Bat::~Bat() {

}

void Bat::attack()
{
	FlyAnimal::attack();
	drain();
}

int Bat::harass(){
	int count = FlyAnimal::harass();
	for(int i = 0; i < count; i++)
		drain();
	return 0;
}

void Bat::drain(){
	if(!isDead()){
		hp = MAX_HP > (hp+1)? (hp+1) : MAX_HP;
	}
}




