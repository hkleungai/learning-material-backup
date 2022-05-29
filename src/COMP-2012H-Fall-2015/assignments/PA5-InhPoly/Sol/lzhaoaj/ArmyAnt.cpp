/*
 * ArmyAnt.cpp
 *
 *  Created on: 2015Äê11ÔÂ20ÈÕ
 *      Author: Lucen
 */

#include "ArmyAnt.h"

ArmyAnt::ArmyAnt(Game* game, int player, int position) :
		AnimalAtk(game, player, position), AntAnimal(game, player, position) {
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "ArmyAnt";
}

ArmyAnt::~ArmyAnt() {

}

//the special move for ArmyAnts
void ArmyAnt::MarchAndConquer() {
	if (this->canMarchAndConquer()) {
		SpecialAttack(3); //deal three damages to all enemies
		if (this->haveArmyAntQueen()) {	//when there is a queen alive, it can heals 2 hp for all ArmyAnts
			hp += 2;
			if (getCurrentHP() > MAX_HP) //check whether hp exceeds maximum
				hp = MAX_HP;
		}
	}
}
