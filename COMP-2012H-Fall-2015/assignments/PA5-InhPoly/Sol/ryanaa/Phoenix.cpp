#include "Phoenix.h"
#include <iostream>
using namespace std;
Phoenix::Phoenix(Game* game, int player, int position): Animal(game,player,position),Flying_Animals(game,player,position),Legendary_Animals(game,player,position) {
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Phoenix";
	reviveCnt = 0;

}

Phoenix::~Phoenix() {
	
}

void Phoenix::attack()
{
	for(int i = pos-1; i <= pos+1; i++)
		if(i >= 0 && i<5){
			enemies[i]->defend(this, atk_damage);
		}
}

void Phoenix::defend(Animal* opponent, int damage){
	takeDamage((int)damage*0.7);
}
void Phoenix::harass(){
	for(int i = 0; i < 5; i++){
		if(!enemies[i]->isDead())
			enemies[i]->takeDamage(1);
	}
}

void Phoenix::takeDamage(int damage){
	hp -= damage;
	if (hp<=0 && reviveCnt==0)
		revive();
	else if (hp<=0) die();
}

void Phoenix::revive(){
	hp = MAX_HP;
	reviveCnt++;
}

void Phoenix::storm(){
	for(int i = 0; i < 5; i++){
		if(!enemies[i]->isDead())
			enemies[i]->takeDamage(3);
	}
}