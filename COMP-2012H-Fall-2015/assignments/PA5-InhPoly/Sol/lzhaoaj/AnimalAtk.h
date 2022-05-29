/*
 * AnimalAtk.h
 *
 *  Created on: 2015Äê11ÔÂ20ÈÕ
 *      Author: Lucen
 */

//AnimalAtk is the class which defines attack behaviours of animal
#ifndef NORMALANIMAL_H_
#define NORMALANIMAL_H_

#include "Animal.h"
using namespace std;

class AnimalAtk: public Animal{
public:
	virtual ~AnimalAtk();

	//the basic attack bahaviour (which is exactly the attack of dog, armyant and turtle)
	virtual void attack();

	//check whether one animal belongs to a certain type.
	//Here, these functions return false. However they are overrided in corrseponding classes, where the functions return true.
	virtual bool isAntAnimal() const;
	virtual bool isDogAnimal() const;
	virtual bool isSkyAnimal() const;
	virtual bool isMarineAnimal() const;
	virtual bool isLegendAnimal() const;

	//calculate the number of alive animals for a certain type.
	int AntAnimalNumber() const;
	int DogAnimalNumber() const;
	int SkyAnimalNumber() const;
	int MarineAnimalNumber() const;
	int LegendAnimalNumber() const;

	//check whether a special move can be triggered
	//Here, these functions return false. However they are overrided in corrseponding classes, where the functions return true when certain conditions are met.
	virtual bool canHarass() const;
	virtual bool canSummonTsunami() const;
	virtual bool canWeatherStorm() const;
	virtual bool canMarchAndConquer() const;
	virtual bool canGroupAttack() const;
	//The group attack must be triggered with a cerberus. Hence this functions checks whether there is one alive Cerberus.
	virtual bool haveCerberus() const;
	//when there is a queen, all ArmyAnts can be healed. Hence check whether there is queen
	virtual bool haveArmyAntQueen() const;

	//The basic behaviour of special move (deal damage to all alive enemies)
	void SpecialAttack(int damage);
	//Functions for each special move, which are overrided (empty functions here, overrided functions which shows the behaviours in corresponding derived classes).
	virtual void Harass();
	virtual void SummonTsunami();
	virtual void WeatherStorm();
	virtual void MarchAndConquer();
	virtual void GroupAttack();

protected:
	AnimalAtk(Game* game, int player, int position);
};



#endif /* NORMALANIMAL_H_ */
