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

	//pure virtual functions
	virtual bool isSkyAnimal() const = 0;
	virtual bool isMarineAnimal() const = 0;
	virtual bool isLegendAnimal() const = 0;
	virtual bool isAntAnimal() const = 0;
	virtual bool isDogAnimal() const = 0;
	virtual bool canHarass() const = 0;
	virtual bool canSummonTsunami() const = 0;
	virtual bool canWeatherStorm() const = 0;
	virtual bool canMarchAndConquer() const = 0;
	virtual bool canGroupAttack() const = 0;
	virtual int SkyAnimalNumber() const = 0;
	virtual int MarineAnimalNumber() const = 0;
	virtual int LegendAnimalNumber() const = 0;
	virtual int AntAnimalNumber() const = 0;
	virtual int DogAnimalNumber() const = 0;
	virtual bool haveCerberus() const = 0;
	virtual bool haveArmyAntQueen() const = 0;
	virtual void Harass() = 0;
	virtual void SummonTsunami() = 0;
	virtual void WeatherStorm() = 0;
	virtual void MarchAndConquer() = 0;
	virtual void GroupAttack() = 0;

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
