#include "Player.h"


int Player::getMoney(){
    return money;
}
void Player::setMoney(int money){
    this->money = money;
}
int Player::totalHands(){
    return (int)hands.size();
}
Cards& Player::getHand(int position){
    return hands[position];
}
void Player::clearHands(){
    hands = deque<Cards>();
}
Cards& Player::newHand(){
    hands.push_back(Cards());
    return hands.back();
}