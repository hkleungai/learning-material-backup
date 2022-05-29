#include "Bat.h"

Bat::Bat(Game* game, int player, int position): Animal(game,player,position), Flying_Animals(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Bat";

}

Bat::~Bat() {
	
}

void Bat::attack()
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
	if (!is_dead) heal();
}

void Bat::defend(Animal* opponent, int damage){
	takeDamage((int)damage*0.8);
}

void Bat::heal(){
	if (hp+1 <= MAX_HP)
		hp++;
}

void Bat::harass(){
	for(int i = 0; i < 5; i++){
		if(!enemies[i]->isDead())
			enemies[i]->takeDamage(1);
	}
	heal();
}