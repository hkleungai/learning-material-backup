//
//  BJPlayer.h
//  PA1_OOP
//
//  Created by Yre on 14/9/15.
//  Copyright (c) 2015 Yre. All rights reserved.
//

#ifndef __PA1_OOP__BJPlayer__
#define __PA1_OOP__BJPlayer__


#include "Card.h"
#include <string>
using namespace std;

class BJPlayer{

public:
    BJPlayer();
    
    bool checkBusted();
    void setBustedFlag(bool flag);
    bool getBustedFlag();

    string getName();
    void setName(string str);
    Card getcard(int k);
    void setCardSize(int k);
    int getCardSize();
    int getTotalPoint();
    
    void Draw(Card c);
    int AceFlag;
    Card splitAway();
    Card ca[6];
private:
    int cardSize;
    int totalBusted;
    string name;
    
    bool bustedFlag;
    int splitable;
    
};

#endif /* defined(__PA1_OOP__BJPlayer__) */
