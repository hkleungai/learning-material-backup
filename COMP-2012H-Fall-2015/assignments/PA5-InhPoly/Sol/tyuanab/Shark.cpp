/*
 * Shark.cpp
 *
 *  Created on: 2015年11月14日
 *      Author: user
 */
#include "Shark.h"

Shark::Shark(Game* game, int player, int position) :
Animal(game, player, position) ,
Normal_att_animal(game, player, position),
Swimming_animal(game, player, position) {
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Shark";
	revenge_damage = 2;
	setSpecialDamage(2);
}

Shark::~Shark() {

}

void Shark::attack() {
	Normal_att_animal::attack();
	takeDamage(1); //poor reckless shark
}

void Shark::defend(Animal * opponent, int damage) {
	Animal::defend(opponent, damage);
	if (!this->isDead())
		revenge(opponent, revenge_damage);
}
void Shark::special_attack(){
	Normal_att_animal::special_attack();
	takeDamage(2);
}
