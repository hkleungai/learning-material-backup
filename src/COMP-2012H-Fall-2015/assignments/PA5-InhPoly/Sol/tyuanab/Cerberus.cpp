/*
 * Cerberus.cpp
 *
 *  Created on: 2015年11月20日
 *      Author: user
 */
#include "Cerberus.h"
Cerberus::Cerberus(Game* game, int player, int position) :
		Animal(game, player, position), Normal_att_animal(game, player,
				position), Legend_animal(game, player, position), defence_animal(
				game, player, position) {
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Cerberus";
	Normal_att_animal::special_damage = 2;
	Attribute[0] = 1;
	set_defend_ratio(0.9);
	bleed_possible = 33; //33% of causing a bleed
}

Cerberus::~Cerberus() {
}
void Cerberus::Bite() {
	bool causebleed = 0;
	int random_number = 0;
	random_number = rand() % 100;
	if (random_number < bleed_possible)
		causebleed = 1;
	if (causebleed) {
		if (causebleed) {
			if (!enemies[pos]->isDead()) {
				enemies[pos]->Buff[2] = 1;
				enemies[pos]->remaining_turn[2] += 2;
			} else {
				for (int i = 1; i < 5; i++) {
					if (pos - i >= 0 && !enemies[pos - i]->isDead()) {
						enemies[pos - i]->Buff[2] = 1;
						enemies[pos - i]->remaining_turn[2] += 2;
						break;
					} else if (pos + i < 5 && !enemies[pos + i]->isDead()) {
						enemies[pos + i]->Buff[2] = 1;
						enemies[pos + i]->remaining_turn[2] += 2;
						break;
					}
				}
			}
		}
	}
}
void Cerberus::attack() {
	Normal_att_animal::attack();
	Bite();
}
void Cerberus::defend(Animal* opponent, int damage) {
	defence_animal::defend(opponent, damage);
	if (hp <= 40) {
		for (int i = 0; i != pos && i < 5; i++) {
			if (allies[i]->getAttribute()[0] == 1) {
				allies[i]->Buff[0] = 1;
			}
		}
	}

}
