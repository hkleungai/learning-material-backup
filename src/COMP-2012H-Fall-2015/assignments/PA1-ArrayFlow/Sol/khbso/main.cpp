//
//  main.cpp
//  Blackjack
//
//  Created by SoKa Ho on 1/9/15.
//  Copyright (c) 2015 Brian. All rights reserved.
//

#include "Blackjack.h"
#include <ctime>
#include <stdlib.h>

int main(){
    
    // initialize seed
    srand((unsigned)time(NULL));
    Blackjack().start();
    
    return 0;
}
