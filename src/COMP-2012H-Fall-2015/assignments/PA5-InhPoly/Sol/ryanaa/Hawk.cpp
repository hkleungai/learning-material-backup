#include "Hawk.h"
#include <iostream>
 using namespace std;
Hawk::Hawk(Game* game, int player, int position): Animal(game,player,position), Flying_Animals(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Hawk";

}

Hawk::~Hawk() {
	
}

void Hawk::attack()
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
		target->takeDamage(atk_damage);//special moves is revenge??!!! DK.. 
	//undefensible
	//enemies[pos]->defend(target, atk_damage);
}

void Hawk::defend(Animal* opponent, int damage){
	takeDamage((int)(damage*0.7));
	if(!is_dead){
		opponent->takeDamage(1); //revenge
	}
}

void Hawk::harass(){
	for (int i=0; i<5;i++)
		if (!enemies[i]->isDead())
			enemies[i]->takeDamage(1);
}
