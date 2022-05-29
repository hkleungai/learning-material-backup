/*
 * Dragon.cpp
 *
 *  Created on: 2015年11月14日
 *      Author: user
 */

#include "Dragon.h"

Dragon::Dragon(Game* game, int player, int position) :
		Animal(game, player, position),
		Normal_att_animal(game, player, position),
		defence_animal(game, player, position),
		Flying_animal(game, player, position),
		Legend_animal(game, player,position) {
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Dragon";
}
void Dragon::setDragonMode(int damage) {
	setSpecialDamage(damage);
}
Dragon::~Dragon() {

}

void Dragon::attack() {
	if (pos == 0) {
		enemies[pos]->defend(this, atk_damage);
		enemies[pos + 1]->defend(this, atk_damage);
	}
	if (pos == 1 || pos == 2 || pos == 3) {
		enemies[pos]->defend(this, atk_damage);
		enemies[pos - 1]->defend(this, atk_damage);
		enemies[pos + 1]->defend(this, atk_damage);
	}
	if (pos == 4) {
		enemies[pos]->defend(this, atk_damage);
		enemies[pos - 1]->defend(this, atk_damage);
	}

}
