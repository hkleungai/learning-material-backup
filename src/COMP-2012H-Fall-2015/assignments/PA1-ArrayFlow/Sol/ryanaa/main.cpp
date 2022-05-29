//
//  main.cpp
//  PA1_OOP
//
//  Created by Yre on 14/9/15.
//  Copyright (c) 2015 Yre. All rights reserved.
//

#include <iostream>
#include "BJRound.h"
#define MAX_CARD_NUM 5+1
using namespace std;

double totalMoney=100.0,curPay;
char input;


int main() {
	cout << "Player: $" << totalMoney << endl; 
    do{
        BJRound round(totalMoney);
        totalMoney = round.run();
        
        cout << "Again? (Y/N)" << endl;
        cin >> input;
        while(input!='Y' && input!='y' && input!='N' && input!='n'){ // user input check
        	cout << "Wrong input. Input again. " << "Again? (Y/N)" << endl;
        	cin >> input;
        }
    }while(input == 'Y' || input == 'y');
    
    return 0;
}
