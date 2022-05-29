/**
 *  You SHOULD NOT modify this file
 */
#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <string>
#include <vector>
#include <iostream>
#include "Game.h"
#include <time.h>
#include <cstdlib>
#include <random>
class Game;

class Animal {
public:
	virtual ~Animal();
	//These are original functions
	//The only thing I add is virtual key work in front of the
	//takeDamage in order to give Phoenix a chance to revive.
	virtual void attack() = 0;
	virtual void defend(Animal* opponent, int damage);
	virtual void takeDamage(int damage);
	void die();
	bool isDead() const;
	std::string getName() const;
	int getCurrentHP() const;

	//These are my functions
	//Heal is to be called by an object and heal allies at ith position
	void heal(int heal, int Max_hp,int i);

	//Every animal special_attack in the same way: deal damage to all the enemies.
	//The difference is their special_attack damage.
	virtual void special_attack() = 0;

	//Public method that get Attribute outside
	std::vector<bool> getAttribute() const;//add
	//get the current buff and calculate the buff effect
	void getBuff();
	//Revenge
	void revenge(Animal* opponent, int revenge_damage);
	//Buff and Debuff
	std::vector<bool> Buff;//{Cerberus's call, onfire, bleeding}
	std::vector<int> remaining_turn;////{Cerberus's bless, onfire, bleeding}

protected:
	int hp;
	int atk_damage;
	bool is_dead;
	int pos;
	std::string name;
	Animal** allies;
	Animal** enemies;

	//***************************Added data***************************************
	//The Attribute of the Animal will be stored here
	std::vector<bool> Attribute; //{DOG,FLYING, WATER, ARMYANT, LEGENG}

	//Can revenge at revenge_damage
	int revenge_damage;

	//****************************************************************************
	Animal(Game *game, int player, int position);


};

#endif /* ANIMAL_H_ */
