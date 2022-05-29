/*
 * BoaConstrictor.cpp
 *
 *  Created on: 18 Nov 2015
 *      Author: sfuab
 */

#include "BoaConstrictor.h"
#include <iostream>
using namespace std;

BoaConstrictor::BoaConstrictor(Game* game, int player, int position):
Animal(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "BoaConstrictor";
	is_grabbing = false;
	grab_pos = -1;
}

BoaConstrictor::~BoaConstrictor() {

}

void BoaConstrictor::attack(){
	if(isGrab() && !enemies[grab_pos]->isDead()){
		damageIncrease();												// increase the damage if it is still grabbing
		enemies[grab_pos]->takeDamage(atk_damage);
		takeDamage(SELF_DAMAGE);
	}else{																// else, choose another prey
		atk_damage = DEFAULT_ATK_DAMAGE;
		if(!enemies[pos]->isDead()){
				enemies[pos]->takeDamage(atk_damage);
				is_grabbing = true;
				grab_pos = pos;
				takeDamage(SELF_DAMAGE);
		}else {
			for(int i = 1; i < 5; i++)
			{
				if(pos-i >= 0 && !enemies[pos-i]->isDead())
				{
					enemies[pos-i]->takeDamage(atk_damage);
					grab_pos = pos-i;
					is_grabbing = true;
					takeDamage(SELF_DAMAGE);
					break;
				}
				else if(pos+i < 5 && !enemies[pos+i]->isDead())
				{
					enemies[pos+i]->takeDamage(atk_damage);
					grab_pos = pos+i;
					is_grabbing = true;
					takeDamage(SELF_DAMAGE);
					break;
				}
			}
		}
	}
	if(isGrab() && enemies[grab_pos]->getName() == "BoaConstrictor"){	// if the enemy is also a boa constrictor, then it will begin to attack this boa constrictor
		BoaConstrictor* temp = dynamic_cast<BoaConstrictor*> (enemies[grab_pos]);
		if(temp)
			temp->setGrabPos(getPos());
	}
	if(isGrab() && enemies[grab_pos]->isDead())						// release the prey if the prey is dead
		is_grabbing = false;
}

void BoaConstrictor::defend(Animal* opponent, int damage){
	takeDamage(damage);
	if(!isDead() && !isGrab())
		opponent->takeDamage(REVENGE_DAMAGE);
}

bool BoaConstrictor::isGrab()const{
	return is_grabbing;
}

int BoaConstrictor::getGrabPos()const{
	if(isGrab())
		return grab_pos;
	else return -1;
}

void BoaConstrictor::setGrabPos(int position){
	if(position >= 0 && position < 5){
		grab_pos = position;
		is_grabbing = true;
	}else{
		grab_pos = -1;
		is_grabbing = false;
	}
}

int BoaConstrictor::getPos()const{
	for(int i = 0; i < 5; i++)
		if(allies[i] == this)
			return i;
	cout << "Error: cannot get current position." << endl;
}

void BoaConstrictor::damageIncrease(){
	if(atk_damage < MAX_ATK_DAMAGE)
		atk_damage++;
}



