#include "Dog.h"

Dog::Dog(Game* game, int player, int position) :
		AnimalAtk(game, player, position), DogAnimal(game, player, position) {
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Dog";

}

Dog::~Dog() {

}
