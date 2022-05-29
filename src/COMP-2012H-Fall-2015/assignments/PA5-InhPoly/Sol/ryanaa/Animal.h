/**
 *  You SHOULD NOT modify this file
 */
#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <string>
#include "Game.h"
class Game;

class Animal {
public:
	virtual ~Animal();

	virtual void attack() = 0;
	virtual void defend(Animal* opponent, int damage);
	virtual void takeDamage(int damage);
	void die();
	bool isDead() const;
	std::string getName() const;
	int getCurrentHP() const;
protected:
	int hp;
	int atk_damage;
	bool is_dead;
	int pos;
	std::string name;
	Animal** allies;
	Animal** enemies;

	Animal(Game *game, int player, int position);


};

#endif /* ANIMAL_H_ */
