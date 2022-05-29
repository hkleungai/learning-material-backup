#include "ArmyAnt.h"

ArmyAnt::ArmyAnt(Game* game, int player, int position): Animal(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "ArmyAnt";

}

ArmyAnt::~ArmyAnt() {
	
}

void ArmyAnt::attack()
{
	Animal* target=NULL;
	if(!enemies[pos]->isDead()){
		target = enemies[pos];
	}
	else {
		for(int i = 1; i < 5; i++){
			if(pos-i >= 0 && !enemies[pos-i]->isDead()){
				target = enemies[pos-i];
				break;
			}
			else if(pos+i < 5 && !enemies[pos+i]->isDead()){
				target = enemies[pos+i];
				break;
			}
		}
	}
	if (target!=NULL)
		target->defend(this, atk_damage);
}

void ArmyAnt::marchAndConquer(){
	for (int i=0; i<5;i++)
		if (!enemies[i]->isDead())
			enemies[i]->takeDamage(3);
}
void ArmyAnt::heal(int i){
	if (hp+i>MAX_HP) hp=MAX_HP;
	else hp+=i;
}
