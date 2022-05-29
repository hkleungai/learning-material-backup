#include "Cerberus.h"

Cerberus::Cerberus(Game* game, int player, int position):Animal(game,player,position), Dog(game,player,position),Legendary_Animals(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Cerberus";

}

Cerberus::~Cerberus() {
	
}

void Cerberus::attack(){
	for (int i=0; i<5;i++){
		Dog* doge = dynamic_cast< Dog* > (allies[i]);
		if (doge!=NULL && !doge->isDead()){
			doge->groupAttack();
		}
	}
}

void Cerberus::defend(Animal* opponent, int damage){
	takeDamage((int)damage);
}

void Cerberus::groupAttack(){
	for (int i=0;i<5;i++)
		if (!Dog::enemies[i]->isDead())
			Dog::enemies[i]->takeDamage(2);
}

void Cerberus::storm(){
	for(int i = 0; i < 5; i++){
		if(!enemies[i]->isDead())
			enemies[i]->takeDamage(3);
	}
}