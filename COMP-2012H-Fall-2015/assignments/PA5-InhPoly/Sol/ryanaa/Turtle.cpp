#include "Turtle.h"
#include <iostream>
using namespace std;
Turtle::Turtle(Game* game, int player, int position): Animal(game,player,position),Swimming_Animals(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Turtle";

}

Turtle::~Turtle() {
	
}

void Turtle::attack()
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
	if (target!=NULL){
		target->defend(this, atk_damage);
	}
}
void Turtle::defend(Animal* opponent, int damage){
	takeDamage((int)damage*0.5);
}

void Turtle::summonTsunami(){
	for (int i=0; i<5;i++)
		if (!enemies[i]->isDead())
			enemies[i]->takeDamage(1);
}