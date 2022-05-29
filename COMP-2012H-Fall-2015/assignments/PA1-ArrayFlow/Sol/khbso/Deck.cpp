#include "Deck.h"
#include <utility> // void swap(T,T);
#include <sstream>
#include <stdlib.h>
using namespace std;

Deck::Deck(){
    // initialize the 52 cards
    for(int rank = 1;rank <= 13;rank++){
        this->push_back(Card(Hearts,rank));
        this->push_back(Card(Diamonds,rank));
        this->push_back(Card(Clubs,rank));
        this->push_back(Card(Spades,rank));
    }
}
Deck::Deck(string cards){
    stringstream ss;
    ss << cards;
    string cardStr;
    while(ss >> cardStr){
        this->push_front(Card(cardStr));
    }
}

void Deck::shuffle(){
    Deck& self = (*this);
    int size = (int)self.size();
    for(int i = 1; i < size; i++){
        
        // randomly select a card between position i to size - 1
        int pos = rand() % (size - i) + i;
        
        // swap the card with position i - 1
        std::swap(self[i - 1],self[pos]);
    }
}

Card Deck::drawCard(){
    if(this->size() <= 0){
        throw 1;
    }
    
    Card c = this->back();
    this->pop_back();
    return c;
}