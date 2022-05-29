//
//  Player.h
//  PA1_OOP
//
//  Created by Yre on 14/9/15.
//  Copyright (c) 2015 Yre. All rights reserved.
//

#ifndef __PA1_OOP__Player__
#define __PA1_OOP__Player__


#include "BJPlayer.h"
#include "Card.h"
#include <string>
using namespace std;


class Player: public BJPlayer{
public:
    Player();
    void display();
    bool checkSplitibility();
    void split(Player& player);
    bool splitable;
    bool Blackjack;


};

#endif /* defined(__PA1_OOP__Player__) */
