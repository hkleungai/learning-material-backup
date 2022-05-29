#ifndef A1_PLAYER_H
#define A1_PLAYER_H

#include "Card.h"

class Player{
    int money;
    deque<Cards> hands;
public:
    
    // money
    
    int getMoney();
    void setMoney(int money);
    
    // hand
    
    int totalHands();
    Cards& getHand(int position);
    void clearHands();
    
    Cards& newHand();
};
#endif