//
//  Blackjack.h
//  PA1_OOP
//
//  Created by Yre on 14/9/15.
//  Copyright (c) 2015 Yre. All rights reserved.
//

#ifndef __PA1_OOP__Blackjack__
#define __PA1_OOP__Blackjack__


#include "BJPlayer.h"
#include "Card.h"
#include "Dealer.h"
#include "Player.h"


class BJRound{
    
public:
    BJRound(double totalMoney);
    
    int getCardPointer();
    //int moveCardPointer(int k);

    bool checkTestCase();
    void normalCaseDeck();
    void testCaseDeck();
    void reshuffle(int startPoint);

//===============Interactions================
    void display();
    bool checkBlackJackforPlayer(Player& player);
    void askDrawFor(Player& player);
    void askSplitFor(Player& player);
    bool checkInput();
//=================Drawing===================
    int  canSplit();
    void drawForPlayer(Player& player);
    void drawForDealer(Dealer& dealer);
    bool decideForNaiveDealer();
    bool decideForSmartDealer();
//================Judging=====================
    void Announcement();
    void judge(Player& player, int dealerScore);
    void setPay();
    void calcReward();
    void outputTotalMoney();
//================Rundown===============
    int run();

    Dealer dealer;
    Player player[5];
    int totalMoney;
    
    
private:
    int numberOfPlayers,totalBusted;
    Card cardPool[55];
    int cardPoolPointer;
    //starting from testCase[1]
    int testCase[55][2];
    int testCaseNum[55];
    char testCaseSuit[55];
    int curPay;
    bool onWeb;

};

#endif /* defined(__PA1_OOP__Blackjack__) */
