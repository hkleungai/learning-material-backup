#ifndef A1_CARD_H
#define A1_CARD_H

#include <iostream>
#include <deque>
using namespace std;

enum Suit{
    Hearts = 'H',
    Diamonds = 'D',
    Clubs = 'C',
    Spades = 'S'
};

// Card
class Card{
    int rank;
    Suit suit;
public:
    Card(Suit suit,int rank);
    Card(string cardStr);
    int getRank() const;
    
    friend ostream& operator<<(ostream&, const Card&); // allow cout << operation
};

// class of cards
class Cards : public deque<Card>
{
public:
    
    // calculate best point;
    int totalPoints();
    
    // count A as 1 point
    int lowerPoints();
    
    // coutn A as 10 point
    int higherPoints();
    
    friend ostream& operator<<(ostream&, const Cards&); // allow cout << operation
};

#endif