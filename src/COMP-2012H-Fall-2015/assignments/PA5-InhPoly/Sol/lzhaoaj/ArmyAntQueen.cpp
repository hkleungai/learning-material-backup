/*
 * ArmyAntQueen.cpp
 *
 *  Created on: 2015Äê11ÔÂ20ÈÕ
 *      Author: Lucen
 */

#include "ArmyAntQueen.h"

ArmyAntQueen::ArmyAntQueen(Game* game, int player, int position): AnimalAtk(game,player,position), AntAnimal(game,player,position) {
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "ArmyAntQueen";
}

ArmyAntQueen::~ArmyAntQueen() {

}

void ArmyAntQueen::attack() {

}

void ArmyAntQueen::defend(Animal* opponent, int damage) {
	takeDamage(damage);
	for (int i = 0; i < 5; i++) {
			if (allies[i]->getName() == "ArmyAnt" && !allies[i]->isDead() && !opponent->isDead())
				opponent->takeDamage(2);
	}
}
