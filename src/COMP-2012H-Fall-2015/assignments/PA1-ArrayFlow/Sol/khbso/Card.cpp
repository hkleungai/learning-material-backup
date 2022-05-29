#include "Card.h"

Card::Card(Suit suit, int rank) : rank(rank), suit(suit)
{
}
Card::Card(string cardStr)
{
    int length = (int)cardStr.length();
    if(length == 2){
        suit = (Suit)cardStr[1];
        switch (cardStr[0]) {
            case 'A':
                rank = 1;
                break;
            case 'J':
                rank = 11;
                break;
            case 'Q':
                rank = 12;
                break;
            case 'K':
                rank = 13;
                break;
            default:
                rank = cardStr[0] - 48;
                break;
        }
    }else if(length == 3){
        suit = (Suit)cardStr[2];
        rank = 10;
    }
}

int Card::getRank() const{
    return this->rank;
}

ostream& operator<<(ostream& out, const Card& card){
    
    switch(card.getRank()){
        case 1:
            out << 'A';
            break;
        case 11:
            out << 'J';
            break;
        case 12:
            out << 'Q';
            break;
        case 13:
            out << 'K';
            break;
        default:
            out << card.getRank();
            break;
    }
    out << (char)card.suit;
    return out;
}
ostream& operator<<(ostream& out, const Cards& cards){
    
    if(!cards.size())
        return out;
    
    out << cards[0];
    
    for(unsigned int i = 1;i<cards.size();i++){
        out << ' ' << cards[i];
    }
    return out;
}


int Cards::totalPoints(){
    int points = 0;
    
    bool aceEncountered = false;
    
    for(int i = 0; i < this->size();i++){
        Card& card = this->at(i);
        int rank = card.getRank();
        if(rank > 10)rank = 10;
        points += rank;
        if(rank == 1){
            aceEncountered = true;
        }
    }
    
    if(aceEncountered && points + 10 <= 21){
        points += 10;
    }
    return points;
}

int Cards::lowerPoints(){
    
    int points = 0;
    
    for(int i = 0; i < this->size();i++){
        Card& card = this->at(i);
        int rank = card.getRank();
        if(rank > 10)rank = 10;
        points += rank;
    }
    return points;
}

int Cards::higherPoints(){
    
    int points = 0;
    
    bool aceEncountered = false;
    
    for(int i = 0; i < this->size();i++){
        Card& card = this->at(i);
        int rank = card.getRank();
        if(rank > 10)rank = 10;
        points += rank;
        if(rank == 1){
            aceEncountered = true;
        }
    }
    
    if(aceEncountered){
        points += 10;
    }
    return points;
}