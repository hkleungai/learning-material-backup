#ifndef A1_DECK_H
#define A1_DECK_H

#include "Card.h"

class Deck : public Cards{
public:
    Deck();
    Deck(string cards);
    void shuffle();
    
    // draw a card from the deck. The card will be removed from the deck
    Card drawCard();
};

#endif