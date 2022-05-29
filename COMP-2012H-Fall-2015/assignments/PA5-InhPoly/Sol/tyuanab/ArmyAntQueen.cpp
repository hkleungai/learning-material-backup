/*
 * ArmyAntQueenQueen.cpp
 *
 *  Created on: 2015年11月14日
 *      Author: user
 */
/*
 * ArmyAntQueen.cpp
 *
 *  Created on: 2015年11月14日
 *      Author: user
 */
#include "ArmyAntQueen.h"
ArmyAntQueen::ArmyAntQueen(Game* game, int player, int position) :
Animal(game, player, position),
Normal_att_animal(game, player, position) {
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "ArmyAntQueen";
	Attribute[3] = 1;
}

ArmyAntQueen::~ArmyAntQueen() {

}

void ArmyAntQueen::attack() {

	//std::cout << "debug: ARMYANT QUEEN CANT ATTACT !" << std::endl;
	return;

}
void ArmyAntQueen::defend(Animal* opponent, int damage) {
	int ArmyAnt_count = -1;
	for (unsigned i = 0; i < 5; i++) {
		if (allies[i]->getAttribute()[3] == 1 && !allies[i]->isDead())
			ArmyAnt_count++;
	}
	revenge_damage = 2 * ArmyAnt_count;
	takeDamage(damage);
	if (!this->isDead())
		revenge(opponent, revenge_damage);

}

void ArmyAntQueen::special_attack() {
	for (int i = 0; i < 5; i++) {
		if (allies[i]->getAttribute()[3] == 1 && i!=pos)
			Animal::heal(heal_amount, 15, i);
	}
}

