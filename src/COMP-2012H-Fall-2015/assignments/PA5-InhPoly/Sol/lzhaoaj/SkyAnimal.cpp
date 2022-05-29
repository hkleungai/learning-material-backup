/*
 * SkyAnimal.cpp
 *
 *  Created on: 2015Äê11ÔÂ20ÈÕ
 *      Author: Lucen
 */

#include "SkyAnimal.h"

SkyAnimal::SkyAnimal(Game* game, int player, int position) :
		AnimalAtk(game, player, position) {

}

SkyAnimal::~SkyAnimal(){

}

bool SkyAnimal::isSkyAnimal() const {
	return true;
}


bool SkyAnimal::canHarass() const {
	if (this->SkyAnimalNumber() >= 3)  //check condition
		return true;
	else
		return false;
}

void SkyAnimal::Harass() {
	if (this->canHarass()) {
		if (this->getName() == "Dragon")
			SpecialAttack(2);
		else
			SpecialAttack(1);
	}
}
