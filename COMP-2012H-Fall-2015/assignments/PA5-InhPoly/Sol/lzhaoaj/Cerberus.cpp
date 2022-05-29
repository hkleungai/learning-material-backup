/*
 * Cerberus.cpp
 *
 *  Created on: 2015Äê11ÔÂ21ÈÕ
 *      Author: Lucen
 */

#include "Cerberus.h"

Cerberus::Cerberus(Game* game, int player, int position) :
		AnimalAtk(game,player,position),LegendAnimal(game, player, position), DogAnimal(game, player, position) {
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Cerberus";
}

Cerberus::~Cerberus() {

}

//since Cerberus guards the gates to the underworld,
//Cerberus can kill its opponent immediately (inevitable) when its opponent's hp is lower than or equal to 7
//Since Cerberus has three heads, when its hp is lower than 10, one head is chopped off.
//In this case, its atk_damage will reduce to 4 and cannot kill opponent inevitable.
void Cerberus::attack() {
	//when hp lower than 10, atk_damage reduce to 4
	if (getCurrentHP() < 10)
		atk_damage = 4;
	else
		atk_damage = DEFAULT_ATK_DAMAGE;

	//choose opponent
	Animal* opponent = NULL;
	if (!enemies[pos]->isDead())
		opponent = enemies[pos];
	else {
		for (int i = 1; i < 5; i++) {
			if (pos - i >= 0 && !enemies[pos - i]->isDead()) {
				opponent = enemies[pos - i];
				break;
			} else if (pos + i < 5 && !enemies[pos + i]->isDead()) {
				opponent = enemies[pos + i];
				break;
			}
		}
	}

	//avoid when all opponents are dead
	if (opponent == NULL)
		return;

	//attack opponent
	if (opponent->getCurrentHP() <= 7 && this->getCurrentHP() >= 10)
		opponent->takeDamage(7);
	else
		opponent->defend(this, atk_damage);
}

//After being attacked, it will revenge and deals with 1 indefensible damage
void Cerberus::defend(Animal* opponent, int damage) {
	this->takeDamage(damage);
	if (!this->isDead()) {
		opponent->takeDamage(1);
	}
}

//When the Cerberus is "dying" (current hp less than or equal to 7),
//it can "eat" the nearest dog, and add the hp to itself.
//(But its HP cannot exceed the maximum value)
void Cerberus::takeDamage(int damage){
	hp -= damage;
	if (hp <= 0)
		die();
	//when it's not dead after an attack
	else if (this->getCurrentHP() <= 7) {
		for (int i = 1; i < 5; i++) {  //search for nearest alive dog in its allies
			if (pos - i >= 0 && !allies[pos - i]->isDead()
					&& allies[pos - i]->getName() == "Dog") {
				hp += allies[pos - i]->getCurrentHP();  //add the same amount of hp with the dog
				allies[pos - i]->die();  //the dog dies
				break;
			} else if (pos + i < 5 && !allies[pos + i]->isDead()
					&& allies[pos + i]->getName() == "Dog") {
				hp += allies[pos + i]->getCurrentHP();
				allies[pos + i]->die();
				break;
			}
		}
		if (this->getCurrentHP() > MAX_HP)  //check whether HP exceed maximum
			hp = MAX_HP;
	}
}
