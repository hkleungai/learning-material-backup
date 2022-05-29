/*
 * Dragon.cpp
 *
 *  Created on: 2015Äê11ÔÂ20ÈÕ
 *      Author: Lucen
 */

#include "Dragon.h"

Dragon::Dragon(Game* game, int player, int position):AnimalAtk(game,player,position), SkyAnimal(game,player,position), LegendAnimal(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Dragon";
}

Dragon::~Dragon() {

}

void Dragon::attack() {
	for (int i = -1; i <= 1; i++) {
		if (pos + i >= 0 && pos + i < 5 && !enemies[pos + i]->isDead())
			enemies[pos + i]->defend(this, atk_damage);
	}
}

void Dragon::defend(Animal* opponent, int damage) {
	takeDamage(damage * 0.8);
}

