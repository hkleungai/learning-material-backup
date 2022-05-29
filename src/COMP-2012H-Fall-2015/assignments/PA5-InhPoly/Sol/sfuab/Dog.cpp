#include "Dog.h"

Dog::Dog(Game* game, int player, int position): Animal(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Dog";
	group_damage = DEFAULT_GROUP_DAMAGE;
}

Dog::~Dog() {
	
}

void Dog::attack()
{
	if(!enemies[pos]->isDead())
		enemies[pos]->defend(this, atk_damage);
	else {
		for(int i = 1; i < 5; i++)
		{
			if(pos-i >= 0 && !enemies[pos-i]->isDead())
			{
				enemies[pos-i]->defend(this, atk_damage);
				break;
			}
			else if(pos+i < 5 && !enemies[pos+i]->isDead())
			{
				enemies[pos+i]->defend(this, atk_damage);
				break;
			}
		}
	}
}

void Dog::groupAttack(){
	for(int i = 0; i < 5; i++)
		if(!enemies[i]->isDead())
			enemies[i]->takeDamage(group_damage);
}
