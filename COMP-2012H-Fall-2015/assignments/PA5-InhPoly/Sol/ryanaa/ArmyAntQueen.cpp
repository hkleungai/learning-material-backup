#include "ArmyAntQueen.h"
#include <iostream>
using namespace std;
ArmyAntQueen::ArmyAntQueen(Game* game, int player, int position):  Animal(game,player,position), ArmyAnt(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Army_Ant_Queen";

}

ArmyAntQueen::~ArmyAntQueen() {
	
}

void ArmyAntQueen::attack()
{
	
}

void ArmyAntQueen::defend(Animal* opponent, int damage){
	takeDamage(damage);
	for (int i=0; i<5;i++){
		ArmyAnt* ant = dynamic_cast< ArmyAnt* > (allies[i]);
		if (ant!=NULL && allies[i]!=this){
			opponent->takeDamage(2);
		}
	}

}

void ArmyAntQueen::marchAndConquer(){
	for (int i=0; i<5;i++){
		ArmyAnt* aa = dynamic_cast< ArmyAnt* > (allies[i]);
		if (aa!=NULL && allies[i]!=this)
			if (!aa->isDead())
				aa->heal(2);
	}
		
}
