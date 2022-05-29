/**
 *  You SHOULD NOT modify this file
 */
#include "Animal.h"

Animal::Animal(Game* game, int player, int position) {
	allies = game->animals[player];
	enemies = game->animals[!player];
	pos = position;
	is_dead = false;
	Buff.resize(3);
	revenge_damage = 0;
	remaining_turn.resize(3);
	Attribute.resize(5);
}

Animal::~Animal() {

}

void Animal::defend(Animal* opponent, int damage) {
	takeDamage(damage);
}

void Animal::die() {
	is_dead = true;
}

void Animal::takeDamage(int damage) {
	hp -= damage;
	if (hp <= 0)
		die();
}

bool Animal::isDead() const {
	return is_dead;
}

std::string Animal::getName() const {
	return name;
}

int Animal::getCurrentHP() const {
	return hp;
}
std::vector<bool> Animal::getAttribute() const {
	return Attribute;
}

void Animal::revenge(Animal * opponent, int revenge_damage) {
	opponent->takeDamage(revenge_damage);
}
void Animal::heal(int heal_amount, int Max_hp, int i) { //heal i th for heal_amount
	if (!allies[i]->isDead()) {
		allies[i]->hp += heal_amount;
		if (allies[i]->hp > Max_hp)
			allies[i]->hp = Max_hp;
	}
}
void Animal::getBuff() {

	 if(remaining_turn[1] == 0)
		 Buff[1] = 0;
	 else if(remaining_turn[2] == 0)
		 Buff[2] = 0;

	if (Buff[0] == 1) {

		atk_damage *= 1.2;
	//	std::cout << getName()<<"has damage of"<< atk_damage <<std::endl;
	} else if (Buff[1] == 1) {
		remaining_turn[1] -= 1;
		takeDamage(1);
		//std::cout <<getName() <<" Ignite for" << remaining_turn[1] << " turns" << std::endl;
	} else if (Buff[2] == 1) {
		remaining_turn[1] -= 1;
		//std::cout <<getName() <<" Bleed for" << remaining_turn[2] << " turns" << std::endl;
		takeDamage(2);
	}

}
