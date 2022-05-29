/*
 * Phoenix.cpp
 *
 *  Created on: 2015年11月20日
 *      Author: user
 */
#include "Phoenix.h"
Phoenix::Phoenix(Game* game, int player, int position) :
		Animal(game, player, position), Normal_att_animal(game, player,
				position), defence_animal(game, player, position), Flying_animal(
				game, player, position), Legend_animal(game, player, position) {
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Phoenix";
	Life = 2;
	ignite_possibility = 60;
}
Phoenix::~Phoenix() {

}
void Phoenix::takeDamage(int damage) {
	hp -= damage;
	//std::cout<< "Phoenix takedamage:"<<hp <<std::endl;
	if (hp <= 0) {
		Life -= 1;
		if (Life  == 0)
			die();
		else revive();
	}
}
void Phoenix::defend(Animal* opponent, int damage) {
	defence_animal::defend(opponent, damage);
	//onfire buff
	opponent->Buff[1] = 1;
	opponent->remaining_turn[1] += 3;
}
void Phoenix::attack() {
	bool will_put_in_fire = 0;
	int random_number = 0;
	random_number = rand() % 100;
	if (random_number < ignite_possibility)
		will_put_in_fire = 1;
	Normal_att_animal::attack();
;	if (will_put_in_fire) {
		ignite();
	}
	//std::cout<< "Phoenix ATTACK(IGNITE)."<<std::endl;
}
void Phoenix::revive() {
	bool _Revenge_ = 0;
	hp = MAX_HP;
	int random_number = rand() % 100;
	if (random_number < 10)
		_Revenge_ = 1;
	if (_Revenge_)
		enemies[pos]->takeDamage(20);
	std::cout << "Phoenix revive!" << std::endl;
}
void Phoenix::ignite() {
	if (!enemies[pos]->isDead()) {
		enemies[pos]->Buff[1] = 1;
		enemies[pos]->remaining_turn[1] += 3;
	} else {
		for (int i = 1; i < 5; i++) {
			if (pos - i >= 0 && !enemies[pos - i]->isDead()) {
				enemies[pos - i]->Buff[1] = 1;
				enemies[pos - i]->remaining_turn[1] += 3;
				break;
			} else if (pos + i < 5 && !enemies[pos + i]->isDead())
				enemies[pos + i]->Buff[1] = 1;
			enemies[pos + i]->remaining_turn[1] += 3;
			break;
		}
	}
}
