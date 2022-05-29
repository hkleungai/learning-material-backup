/*
 * Hawk.cpp
 *
 *  Created on: 2015Äê11ÔÂ19ÈÕ
 *      Author: Lucen
 */

#include "Hawk.h"

Hawk::Hawk(Game* game, int player, int position): AnimalAtk(game,player,position),SkyAnimal(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Hawk";
}

Hawk::~Hawk() {

}

void Hawk::attack() {
	if (!enemies[pos]->isDead())
		enemies[pos]->takeDamage(atk_damage);
	else {
		for (int i = 1; i < 5; i++) {
			if (pos - i >= 0 && !enemies[pos - i]->isDead()) {
				enemies[pos - i]->takeDamage(atk_damage);
				break;
			} else if (pos + i < 5 && !enemies[pos + i]->isDead()) {
				enemies[pos + i]->takeDamage(atk_damage);
				break;
			}
		}
	}
}

void Hawk::defend(Animal* opponent, int damage) {
	takeDamage(damage * 0.7);
	if (!this->isDead()){
		opponent->takeDamage(1);}
}

