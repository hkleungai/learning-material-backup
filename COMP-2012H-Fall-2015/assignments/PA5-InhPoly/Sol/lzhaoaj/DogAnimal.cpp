/*
 * DogAnimal.cpp
 *
 *  Created on: 2015Äê11ÔÂ21ÈÕ
 *      Author: Lucen
 */

#include "DogAnimal.h"

DogAnimal::DogAnimal(Game* game, int player, int position) :
		AnimalAtk(game, player, position) {

}

DogAnimal::~DogAnimal() {

}

bool DogAnimal::isDogAnimal() const {
	return true;
}

bool DogAnimal::canGroupAttack() const {
	if (this->DogAnimalNumber() >= 2 && this->haveCerberus()) //check the condition
		return true;
	else
		return false;
}

void DogAnimal::GroupAttack() {
	if (this->canGroupAttack()) {
		if (this->getName() == "Cerberus")
			SpecialAttack(2);
		else
			SpecialAttack(1);
	}
}

