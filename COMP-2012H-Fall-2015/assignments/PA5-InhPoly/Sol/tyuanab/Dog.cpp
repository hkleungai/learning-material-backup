#include "Dog.h"

Dog::Dog(Game* game, int player, int position) :
		Animal(game, player, position), Normal_att_animal(game, player,
				position) {
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Dog";
	Attribute[0] = 1;
	setSpecialDamage(1);
}

Dog::~Dog() {

}
