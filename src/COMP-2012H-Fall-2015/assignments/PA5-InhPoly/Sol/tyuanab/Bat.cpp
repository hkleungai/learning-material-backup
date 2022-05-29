/*
 * Bat.cpp
 *
 *  Created on: 2015年11月14日
 *      Author: user
 */
#include "Bat.h"

Bat::Bat(Game* game, int player, int position) :
		Animal(game, player, position),
		Normal_att_animal(game, player, position),
		defence_animal(game, player,position),
		Flying_animal(game, player, position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Bat";
	defence_animal::set_defend_ratio(0.8);

}

Bat::~Bat() {
}
void Bat::drain() {
	if (hp <= MAX_HP)
		hp += 1;
}
void Bat::attack() {
	Normal_att_animal::attack();
	drain();
}
void Bat::special_attack(){
	Normal_att_animal::special_attack();
	std::cout<< "Bat give a Harass!"<<std::endl;
	drain();
}
