/*
 * Army_Ant_Queen.cpp
 *
 *  Created on: 12 Nov 2015
 *      Author: sfuab
 */

#include "ArmyAntQueen.h"

ArmyAntQueen::ArmyAntQueen(Game* game, int player, int position): ArmyAnt(game,player,position){
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "ArmyAntQueen";

}

ArmyAntQueen::~ArmyAntQueen() {

}

void ArmyAntQueen::attack()
{}


void ArmyAntQueen::defend(Animal* opponent, int damage){
	takeDamage(damage);
	for(int i = 0; i < 5; i++){
		if(allies[i]->getName() == "ArmyAnt" && !allies[i]->isDead())
			opponent->takeDamage(REVENGE_DAMAGE);
	}
}

void ArmyAntQueen::marchAndConquer(){
	for(int i = 0; i < 5; i++)
		if(!allies[i]->isDead() && allies[i] != this){
			ArmyAnt* temp = (ArmyAnt* ) allies[i];
			if(temp)
				temp->setHP(allies[i]->getCurrentHP() + HEAL_AMOUNT);
		}
}









