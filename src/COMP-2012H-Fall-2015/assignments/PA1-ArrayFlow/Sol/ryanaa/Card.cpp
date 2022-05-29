//
//  Card.cpp
//  PA1_OOP
//
//  Created by Yre on 15/9/15.
//  Copyright (c) 2015 Yre. All rights reserved.
//

#include "Card.h"

Card::Card(){
	for (int i=2;i<=10;i++) Rank[i]=i;
	for (int i=11;i<=13;i++) Rank[i]=10;
	Rank[1]=11;
    
}

int Card::getRank(){
    return Rank[number];
}
int Card::getNumb(){
	return number;
}
char Card::getSuit(){
	char suitChar[4]={'H','D','C','S'}; // starting from 0 (only)
	return suitChar[suit];
}

void Card::setNumb(int k){
	number = k;
}

void Card::setSuit(int k){
	suit = k;
}