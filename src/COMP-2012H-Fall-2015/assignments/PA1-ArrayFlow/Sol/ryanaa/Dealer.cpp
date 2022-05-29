//
//  Dealer.cpp
//  PA1_OOP
//
//  Created by Yre on 14/9/15.
//  Copyright (c) 2015 Yre. All rights reserved.
//

#include "Dealer.h"
#include <iostream>
using namespace std;


Dealer::Dealer(){

}

void Dealer::display(){
    cout << "> " << getName() << " : ";
    cout << "* ";                  // do not reveal the first one
    for (int j = 2; j <= getCardSize(); j++ )
        cout << ca[j].getNumb() << ca[j].getSuit() << ' ';
    cout << endl;
}

void Dealer::final_display(){
    cout << "> " << getName() << " : ";   //reveal the first one
    for (int j = 1; j <= getCardSize(); j++ )
        cout << ca[j].getNumb() << ca[j].getSuit() << ' ';
    cout << endl;
}