 //
//  Player.cpp
//  PA1_OOP
//
//  Created by Yre on 14/9/15.
//  Copyright (c) 2015 Yre. All rights reserved.
//

#include "Player.h"


#include<iostream>
using namespace std;


Player::Player(){
    splitable = true;
    Blackjack = false;
}

void Player::display(){
    cout << "> " << getName() << " : ";
    for (int j = 1; j <= getCardSize(); j++ )
        cout << ca[j].getNumb() << ca[j].getSuit() << ' ';
    cout << endl;
    
}

bool Player::checkSplitibility(){
	if (!splitable) return false;      // if the player have been asked and rejected before, then this time the dealer skip it
	if (ca[1].getNumb() == ca[2].getNumb() && getCardSize()==2 )
		return true;
	return false;
}


void Player::split(Player& player){
	player.Draw(this->splitAway());       // the player draw the card that came from the splitAway function from this(player)
}
