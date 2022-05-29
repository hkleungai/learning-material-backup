#ifndef A1_BLACKJACK_H
#define A1_BLACKJACK_H

#include "Card.h"
#include "Player.h"
#include "Deck.h"

static const int MAX_SPLIT = 3;

class Blackjack{
public:
    // start the Blackjack game
    void start();
    
    // start a new round. A round means a compelete Blackjack game.
    void startRound();
private:
    bool isInTestCase;
    
    Player player;
    Cards dealerCards;
    Deck deck;
    
    int wagerForThisRound;

    // get the wager of a round from user input
    int inputWager();
    
    //-- belows are helper functions within startRound() --
    
    int splitDecision(int handPosition,int splitCount);
    void drawCardDecision();
    void drawCardDecisionForHand(int handPostition);
    void dealerDrawDecision();
    void finailizeResult();
    float gameResultOfPlayerHand(int handPosition);
    
    // display all the cards
    void displayCards(bool forResult = false);
};

#endif