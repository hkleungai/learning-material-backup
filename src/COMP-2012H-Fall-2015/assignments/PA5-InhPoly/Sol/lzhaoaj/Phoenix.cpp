/*
 * Phoenix.cpp
 *
 *  Created on: 2015Äê11ÔÂ21ÈÕ
 *      Author: Lucen
 */

#include "Phoenix.h"

Phoenix::Phoenix(Game* game, int player, int position): AnimalAtk(game,player,position),LegendAnimal(game,player,position),SkyAnimal(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Phoenix";
	revived = false;
}

Phoenix::~Phoenix(){

}

//all revenges are useless to Phoenix, which means its hp will not decrease after a revenge
void Phoenix::attack(){
	int currentHP = hp;  //record current HP
	//after one attack, recover all its attributes to the status before this attack
	if (revived == false){
	AnimalAtk::attack();
	hp = currentHP;
	if (revived)
		revived = false;
	}
	else{
		AnimalAtk::attack();
		hp = currentHP;
		if (this->isDead())
			is_dead = false;
	}
}

//Takes only 70% of the damages as flying animals are agile
void Phoenix::defend(Animal* opponent, int damage){
	this->takeDamage(damage*0.7);
}

//overrided takeDamage
void Phoenix::takeDamage(int damage){
	hp -= damage;
	if (hp <= 0){  //when it dies, if revived == false, it will be revived.
		if (!revived)
			revive();
		else
			die();
	}
}

void Phoenix::revive(){
	hp = MAX_HP;
	revived = true;
}

