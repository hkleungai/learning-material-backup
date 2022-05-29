/*
 * AntAnimal.cpp
 *
 *  Created on: 2015Äê11ÔÂ21ÈÕ
 *      Author: Lucen
 */

#include "AntAnimal.h"

AntAnimal::AntAnimal(Game* game, int player, int position) :
		AnimalAtk(game, player, position) {

}

AntAnimal::~AntAnimal(){

}

bool AntAnimal::isAntAnimal() const {
	return true;
}

bool AntAnimal::canMarchAndConquer() const {
	if (this->AntAnimalNumber() >= 5)  //check condition
		return true;
	else
		return false;
}
