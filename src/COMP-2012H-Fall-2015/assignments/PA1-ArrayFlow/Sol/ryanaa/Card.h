//
//  Card.h
//  PA1_OOP
//
//  Created by Yre on 14/9/15.
//  Copyright (c) 2015 Yre. All rights reserved.
//

#ifndef __PA1_OOP__Card__ 
#define __PA1_OOP__Card__


class Card{
private:
    int number,suit;
    int Rank[14];
public:
	Card();
    int getRank();
    int getNumb();
    char getSuit();

    void setNumb(int k);
    void setSuit(int k);

};

#endif /* defined(__PA1_OOP__Card__) */
