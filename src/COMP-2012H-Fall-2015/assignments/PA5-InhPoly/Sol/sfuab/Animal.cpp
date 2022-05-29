/**
 *  You SHOULD NOT modify this file
 */
#include "Animal.h"

Animal::Animal(Game* game, int player, int position) {
	allies = game->animals[player];
	enemies = game->animals[!player];
	pos = position;
	is_dead = false;
}

Animal::~Animal() {
	
}


void Animal::defend(Animal* opponent, int damage)
{
	takeDamage(damage);
}

void Animal::die()
{
	is_dead = true;
}

void Animal::takeDamage(int damage)
{
	hp -= damage;
	if( hp <= 0 )
		die();
}

bool Animal::isDead() const
{
	return is_dead;
}

std::string Animal::getName() const
{
	return name;
}

int Animal::getCurrentHP() const
{
	return hp;
}
