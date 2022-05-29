#include "Dragon.h"
#include <iostream>
using namespace std;
Dragon::Dragon(Game* game, int player, int position):Animal(game,player,position), Flying_Animals(game,player,position), Legendary_Animals(game,player,position){
	Flying_Animals::hp = MAX_HP;
	Flying_Animals::atk_damage = DEFAULT_ATK_DAMAGE;
	Flying_Animals::name = "Dragon";

}

Dragon::~Dragon() {
	
}

void Dragon::attack()
{

	for(int i = Flying_Animals::pos-1; i <= pos+1; i++)
		if(i >= 0 && i<5 && !enemies[i]->isDead()){
			enemies[i]->defend(allies[pos], atk_damage);
		}
}

void Dragon::defend(Animal* opponent, int damage){
	Flying_Animals::takeDamage((int)damage*0.8);
}

void Dragon::harass(){
	for (int i=0; i<5;i++)
		if (!enemies[i]->isDead())
			enemies[i]->takeDamage(2);
}

void Dragon::storm(){
	for(int i = 0; i < 5; i++){
		if(!enemies[i]->isDead())
			enemies[i]->takeDamage(3);
	}
}