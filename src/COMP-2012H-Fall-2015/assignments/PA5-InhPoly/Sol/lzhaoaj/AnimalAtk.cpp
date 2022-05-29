/*
 * AnimalAtk.cpp
 *
 *  Created on: 2015Äê11ÔÂ20ÈÕ
 *      Author: Lucen
 */

#include "AnimalAtk.h"

AnimalAtk::AnimalAtk(Game* game, int player, int position) :
		Animal(game, player, position) {

}

AnimalAtk::~AnimalAtk() {

}

//the basic attack bahaviour (which is exactly the attack of dog, armyant and turtle)
void AnimalAtk::attack() {
	if (!enemies[pos]->isDead())  //check whether the opponent is alive and deal damage
		enemies[pos]->defend(this, atk_damage);
	else {
		for (int i = 1; i < 5; i++) {  //find alive opponent and deal damage
			if (pos - i >= 0 && !enemies[pos - i]->isDead()) {
				enemies[pos - i]->defend(this, atk_damage);
				break;
			} else if (pos + i < 5 && !enemies[pos + i]->isDead()) {
				enemies[pos + i]->defend(this, atk_damage);
				break;
			}
		}
	}
}

//check whether one animal belongs to a certain type.
//Here, these functions return false. However they are overrided in corrseponding classes, where the functions return true.
bool AnimalAtk::isAntAnimal() const {
	return false;
}

bool AnimalAtk::isDogAnimal() const {
	return false;
}

bool AnimalAtk::isSkyAnimal() const {
	return false;
}

bool AnimalAtk::isMarineAnimal() const {
	return false;
}

bool AnimalAtk::isLegendAnimal() const {
	return false;
}

//return the number of alive animals for a certain type.
int AnimalAtk::AntAnimalNumber() const {
	int result = 0;
	for (int i = 0; i < 5; i++) {
		if (allies[i]->isAntAnimal() && !allies[i]->isDead())
			result++;
	}
	return result;
}

int AnimalAtk::DogAnimalNumber() const {
	int result = 0;
	for (int i = 0; i < 5; i++) {
		if (allies[i]->isDogAnimal() && !allies[i]->isDead())
			result++;
	}
	return result;
}

int AnimalAtk::SkyAnimalNumber() const {
	int result = 0;
	for (int i = 0; i < 5; i++) {
		if (allies[i]->isSkyAnimal() && !allies[i]->isDead())
			result++;
	}
	return result;
}

int AnimalAtk::MarineAnimalNumber() const {
	int result = 0;
	for (int i = 0; i < 5; i++) {
		if (allies[i]->isMarineAnimal() && !allies[i]->isDead())
			result++;
	}
	return result;
}

int AnimalAtk::LegendAnimalNumber() const {
	int result = 0;
	for (int i = 0; i < 5; i++) {
		if (allies[i]->isLegendAnimal() && !allies[i]->isDead())
			result++;
	}
	return result;
}

//check whether there is an alive cerberus in the allies
bool AnimalAtk::haveCerberus() const {
	for (int i = 0; i < 5; i++) {
		if (allies[i]->getName() == "Cerberus" && !allies[i]->isDead())
			return true;
	}
	return false;
}
//when there is a queen, all ArmyAnts can be healed. Hence check whether there is queen
bool AnimalAtk::haveArmyAntQueen() const {
	for (int i = 0; i < 5; i++) {
		if (allies[i]->getName() == "ArmyAntQueen" && !allies[i]->isDead())
			return true;
	}
	return false;
}

//check whether a special move can be triggered
//Here, these functions return false. However they are overrided in corrseponding classes, where the functions return true when certain conditions are met.
bool AnimalAtk::canHarass() const {
	return false;
}

bool AnimalAtk::canSummonTsunami() const {
	return false;
}

bool AnimalAtk::canMarchAndConquer() const {
	return false;
}

bool AnimalAtk::canGroupAttack() const {
	return false;
}

bool AnimalAtk::canWeatherStorm() const {
	return false;
}

//The basic behaviour of special move (deal damage to all alive enemies)
void AnimalAtk::SpecialAttack(int damage) {
	for (int i = 0; i < 5; i++) {
		if (!enemies[i]->isDead())
			enemies[i]->takeDamage(damage);
	}
}

//Functions for each special move, which are overrided (empty functions here, overrided functions which shows the behaviours in corresponding derived classes).
void AnimalAtk::Harass() {

}

void AnimalAtk::SummonTsunami() {

}

void AnimalAtk::WeatherStorm() {

}

void AnimalAtk::MarchAndConquer() {

}

void AnimalAtk::GroupAttack() {

}
