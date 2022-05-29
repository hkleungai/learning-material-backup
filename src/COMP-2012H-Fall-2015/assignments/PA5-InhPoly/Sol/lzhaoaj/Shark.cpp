/*
 * Shark.cpp
 *
 *  Created on: 2015Äê11ÔÂ20ÈÕ
 *      Author: Lucen
 */

#include "Shark.h"

Shark::Shark(Game* game, int player, int position) :
		AnimalAtk(game,player,position),MarineAnimal(game, player, position) {
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Shark";
}

Shark::~Shark() {

}

void Shark::attack() {
	AnimalAtk::attack();
	takeDamage(1);
}

void Shark::defend(Animal* opponent, int damage) {
	takeDamage(damage);
	if (!this->isDead() && !opponent->isDead()) {
		opponent->takeDamage(2);
	}
}
