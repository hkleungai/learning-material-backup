/*
 * MarineAnimal.cpp
 *
 *  Created on: 2015Äê11ÔÂ20ÈÕ
 *      Author: Lucen
 */

#include "MarineAnimal.h"

MarineAnimal::MarineAnimal(Game* game, int player, int position): AnimalAtk(game,player,position){

}

MarineAnimal::~MarineAnimal(){

}

bool MarineAnimal::isMarineAnimal() const{
	return true;
}

bool MarineAnimal::canSummonTsunami() const{
	if (MarineAnimalNumber() >= 3) //check the condition
		return true;
	else
		return false;
}

void MarineAnimal::SummonTsunami(){
	if (this->canSummonTsunami()){
		if (this->getName() == "Shark")
			SpecialAttack(2);
		else
			SpecialAttack(1);
		if (this->getName() == "Shark") //shark will hurt itself as well
			this->takeDamage(2);
	}
}
