/*
 * LegendAnimal.cpp
 *
 *  Created on: 2015Äê11ÔÂ21ÈÕ
 *      Author: Lucen
 */

#include "LegendAnimal.h"

LegendAnimal::LegendAnimal(Game* game, int player, int position):AnimalAtk(game,player,position){

}

bool LegendAnimal::isLegendAnimal() const{
	return true;
}

LegendAnimal::~LegendAnimal(){

}

bool LegendAnimal::canWeatherStorm() const {
	if (this->LegendAnimalNumber() >= 3) //check the condition
		return true;
	else
		return false;
}

void LegendAnimal::WeatherStorm(){
	if (this->canWeatherStorm()){
		SpecialAttack(3);
	}
}
