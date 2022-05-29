//
//  BJPlayer.cpp
//  PA1_OOP
//
//  Created by Yre on 14/9/15.
//  Copyright (c) 2015 Yre. All rights reserved.
//

#include "BJPlayer.h"
#include "BJRound.h"
#include <iostream>
#include <string>
using namespace std;

BJPlayer::BJPlayer(){
    splitable = true;
    AceFlag = 0;
    cardSize = 0;
    bustedFlag = false;
}


bool BJPlayer::checkBusted(){
//    cout << "checkBusted" << getTotalPoint() << endl;
    if (getTotalPoint() > 21) return true;
    else return false;
}
void BJPlayer::setBustedFlag(bool flag){bustedFlag = flag;}
bool BJPlayer::getBustedFlag(){return bustedFlag;}

string BJPlayer::getName(){return name;}
void BJPlayer::setName(string str){name = str;}   // the name is a private variable so we need a get and set function
Card BJPlayer::getcard(int k){return ca[k];}
void BJPlayer::setCardSize(int k){cardSize = k;}  
int BJPlayer::getCardSize(){return cardSize;}

int BJPlayer::getTotalPoint(){
    int sum=0;
    AceFlag = 0;                    // count the total number of Ace in hand
    for (int i = 1; i <= cardSize; i++){
        sum += ca[i].getRank();
        AceFlag += (ca[i].getRank() == 11);  // if the card's rank is 11 which means it is an Ace, then Aceflag++
    }
    while (sum > 21 && AceFlag > 0){        // save the total point to be less then 21 by sacraficing the ace to be 1 rather than 11
        sum -= 10;
        AceFlag --;
    }
    return sum;
}

//========================
void BJPlayer::Draw(Card c){
//    cout << "Draw"<< c.getNumb() << c.getSuit() << endl;
    ca[++cardSize] = c; // before drawing, the size change first
}

Card BJPlayer::splitAway(){
    return ca[cardSize--];  // after getting out, the size changes
}
    //1C 4D 10H 5H 10S 13D 7C 3D 9D 10D 13H 13C
