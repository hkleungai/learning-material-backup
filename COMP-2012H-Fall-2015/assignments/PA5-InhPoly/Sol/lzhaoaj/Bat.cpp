/*
 * Bat.cpp
 *
 *  Created on: 2015Äê11ÔÂ20ÈÕ
 *      Author: Lucen
 */

#include "Bat.h"

Bat::Bat(Game* game, int player, int position): AnimalAtk(game,player,position),SkyAnimal(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Bat";
}

Bat::~Bat() {

}

void Bat::attack() {
	AnimalAtk::attack();
	if (!this->isDead() && this->getCurrentHP() < MAX_HP)
		hp++;
}

void Bat::defend(Animal* opponent, int damage) {
	takeDamage(damage * 0.8);
}

void Bat::Harass() {
	SkyAnimal::Harass();
	if (this->canHarass()) {
		if (this->getCurrentHP() < MAX_HP)
			hp++;
	}
}
