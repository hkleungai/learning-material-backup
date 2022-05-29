#include "Shark.h"
#include <iostream>
using namespace std;
Shark::Shark(Game* game, int player, int position): Animal(game,player,position), Swimming_Animals(game,player,position){

	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Shark";

}

Shark::~Shark() {
	
}

void Shark::attack()
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
	takeDamage(1); // by itself
	if (target!=NULL)
		target->defend(this, atk_damage);
	
}
void Shark::defend(Animal* opponent, int damage){
	takeDamage(damage);
	if (!is_dead){ //revenge
		opponent->takeDamage(2);
	}
}

void Shark::summonTsunami(){
	takeDamage(2); // by itself
	for (int i=0; i<5;i++)
		if (!enemies[i]->isDead())
			enemies[i]->takeDamage(2);
}

