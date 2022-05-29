/*
 * BoaConstrictor.h
 *
 *  Created on: 18 Nov 2015
 *      Author: sfuab
 */

#ifndef BOACONSTRICTOR_H_
#define BOACONSTRICTOR_H_

#include "Animal.h"

class BoaConstrictor:public Animal{
public:
	BoaConstrictor(Game* game, int player, int position);
	virtual ~BoaConstrictor();

	virtual void attack();
	virtual void defend(Animal* opponent, int damage);

	bool isGrab()const;
	int getGrabPos()const;
	void setGrabPos(int position);

protected:
	int getPos()const;
	void damageIncrease();
	bool is_grabbing;
	int grab_pos;

private:
	static const int MAX_HP = 30;
	static const int DEFAULT_ATK_DAMAGE = 3;
	static const int MAX_ATK_DAMAGE = 6;
	static const int REVENGE_DAMAGE = 1;
	static const int SELF_DAMAGE = 1;
};



#endif /* BOACONSTRICTOR_H_ */
