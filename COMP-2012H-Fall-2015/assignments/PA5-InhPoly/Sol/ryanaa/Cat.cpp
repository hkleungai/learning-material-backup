#include "Cat.h"
Cat::Cat(Game* game, int player, int position): Animal(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Cat";

}

Cat::~Cat() {
	
}

void Cat::attack()
{
	Animal* target=0;
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
	if (hp<13){
		if (target!=NULL)
			target->defend(this, (int)atk_damage*1.5);
	}
	else
		if (target!=NULL)
			target->defend(this, atk_damage);
}

