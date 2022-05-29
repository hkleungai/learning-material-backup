#include "Blackjack.h"
#include <iostream>

using namespace std;

void Blackjack::start(){
    player.setMoney(100);
    
    char again;
    while(true){
        this->startRound();
        if(player.getMoney() > 0){
            cout << "> Again? (Y/N): ";
            cin >> again;
            if(again != 'Y' && again != 'y'){
                break;
            }
        }else{
            cout << "You have no money. ";
            break;
        }
    }
    cout << "Game Over!" << endl;
}

void Blackjack::startRound(){
    
    cout << "Player: $" << player.getMoney() << endl
    << "Pay for this round : ";
    
    wagerForThisRound = this->inputWager();
    player.setMoney(player.getMoney() - wagerForThisRound);
    
    // Test case enabling
    {
        cout << "Test case? (Y/N): ";
        char input;
        cin >> input;
        isInTestCase = (input == 'Y' || input == 'y');
    }
    //initialize stage
    
    if(isInTestCase){
        deck = Deck("2D 2H 3C 7D 5C 9D 10H 2C 4D 3S 4H JD");// replace with test case Deck;
    }else{
        deck = Deck();// replace with new Deck
        deck.shuffle();
    }
    dealerCards = Cards();// replace with new Cards
    
    
    
    player.clearHands();
    player.newHand();
    
    // draw initial cards
    
    player.getHand(0).push_back(deck.drawCard());
    player.getHand(0).push_back(deck.drawCard());
    
    dealerCards.push_back(deck.drawCard());
    dealerCards.push_back(deck.drawCard());
    
    displayCards();
    
    // player split decision
    splitDecision(0,0);
    
    // player draw decision
    drawCardDecision();
    
    // dealer draw decision
    // only draw when player have at least one deck not busted.
    for(int i = 0;i < player.totalHands();i++){
        if(player.getHand(i).totalPoints() <= 21){
            
            dealerDrawDecision();
            break;
        }
    }
    
    // calculate points
    displayCards(true);
    
    // calculate point and wager for ending a round of Blackjack;
    finailizeResult();
}


// get the wager of a round from user input
int Blackjack::inputWager(){
    
    int wager;
    cin >> wager;
    
    if(wager <= 0){
        cout << "please enter value larger than 0: ";
        return this->inputWager();
    }else if(wager > player.getMoney()){
        cout << "you have not enough money! Please input again: ";
        return this->inputWager();
    }
    
    return wager;
}

// display all the cards
// @param forResult - if true, it reveal all face down cards
void Blackjack::displayCards(bool forResult){
    cout << endl;
    if(forResult){
        cout << "> Dealer : " << dealerCards << endl;
    }else{
        cout << "> Dealer : * " << dealerCards[1] << endl;
    }

    cout << "> Player : " << player.getHand(0) << endl;
    for(unsigned int i = 1;i<player.totalHands();i++){
        cout << "> Split" << i << " : " << player.getHand(i) << endl;
    }
}

// let user decide whether draw a card or not for sepcific hand
// @param handPosition - the position of the hand
void Blackjack::drawCardDecisionForHand(int handPostition){
    char ch;
    Cards& hand = player.getHand(handPostition);
    while(hand.size() < 5 && hand.lowerPoints() <= 21){
        if(handPostition == 0){
            cout << "> Draw? (Y/N): ";
        }else{
            cout << "> Draw for split" << handPostition << "? (Y/N): ";
        }
        
        cin >> ch;
        if(ch == 'Y' || ch == 'y'){
            hand.push_back(deck.drawCard());
            displayCards();
        }else{
            return;
        }
    }
}

//let user decide whether draw a card or not for all hand
void Blackjack::drawCardDecision(){
    for(int i = 0;i < player.totalHands();i++){
        drawCardDecisionForHand(i);
    }
}
//let user decide whether draw a card or not for sepcific hand
void Blackjack::dealerDrawDecision(){
    
    if(dealerCards.lowerPoints() >= 21){
        return;
    }
    if(dealerCards.size() >= 5){
        return;
    }
    
    // Smart Algorithm
    // 1. consider all visible point
    int points = 4 * (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 10 + 10);
    int totalCardsDrawed = (int)dealerCards.size();
    
    for(int i = 0;i<dealerCards.size();i++){
        points -= dealerCards[i].getRank();
    }
    for(int i = 0;i<player.totalHands();i++){
        points -= player.getHand(i)[0].getRank();
        points -= player.getHand(i)[1].getRank();
        totalCardsDrawed += 2;
    }
    
    double averagePoint = points / (double)(52 - totalCardsDrawed);
    
    // 2. consider the Ace to be 1 or 11
    double lowerPoint = dealerCards.lowerPoints();// ace to be 1
    double higherPoint = dealerCards.higherPoints();// ace to be 2
    double bestPoint = dealerCards.totalPoints();
    
    lowerPoint += averagePoint;
    higherPoint += averagePoint;
    
    if(higherPoint <= 21){
        dealerCards.push_back(deck.drawCard());
        return dealerDrawDecision();
    }
    if(lowerPoint <= 21 && lowerPoint > bestPoint){
        dealerCards.push_back(deck.drawCard());
        return dealerDrawDecision();
    }
}

//let user decide whether split or not
// this is an recursive function
// @return splitCount - the total split time
int Blackjack::splitDecision(int handPosition, int splitCount){
    
    // 1. end when split 3 times
    if(splitCount >= MAX_SPLIT){
        return splitCount;
    }
    
    Cards& hand = player.getHand(handPosition);
    
    // 2. end when the 2 cards is not same rank
    if(hand[0].getRank() != hand[1].getRank())
        return splitCount;
    
    // 3. end when the user has not enough money to split
    if(player.getMoney() < wagerForThisRound)
        return splitCount;
    
    if(handPosition == 0){
        cout << "Split ? (Y/N): ";
    }else{
        cout << "Split for split" << handPosition << " ? (Y/N):";
    }
    
    char input;
    cin >> input;
    if(input != 'Y' && input != 'y'){
        return splitCount;
    }
    
    player.setMoney(player.getMoney() - wagerForThisRound);

    // split now !
    // 1. insert a new hand
    Cards& newHand = player.newHand();
    
    // 2. move a card to new hand
    Card card = hand.back();
    hand.pop_back();
    newHand.push_back(card);
    
    // 3. draw a card for each hand
    hand.push_back(deck.drawCard());
    newHand.push_back(deck.drawCard());
    
    // splited !
    
    displayCards();
    
    splitCount++;
    
    splitCount = splitDecision(player.totalHands() - 1,splitCount);
    splitCount = splitDecision(handPosition,splitCount);
    
    return splitCount;
}

// compare the points of a hand to dealer's hand
// @param handPosition - the position of the hand
// @return - the ratio of wager the hand win
//          2.0 when win
//          1.5 when the two cards of the player equals to 21 pts.
//          1.0 when tie
//          0.0 when lose
float Blackjack::gameResultOfPlayerHand(int handPosition){
    int totalPoints = player.getHand(handPosition).totalPoints();
    int dealerPoints = dealerCards.totalPoints();
    
    if(handPosition == 0){
        cout << "> Dealer " << dealerPoints << " points, Player " << totalPoints << " points";
    }else{
        cout << ": and " << totalPoints << " points";
    }
    
    // player busted
    if(totalPoints > 21){
        return 0;
    }
    // the two cards of the player equals to 21 pts
    if(totalPoints == 21 && player.getHand(handPosition).size() == 2){
        return 1.5;
    }
    // win
    //   dealer busted or player get larger point than dealer
    if(dealerPoints > 21 || (totalPoints > dealerPoints)){
        return 2.0;
    }
    // tie
    if(dealerPoints == totalPoints){
        return 1.0;
    }
    
    // remaining case means the player loses
    return 0;
}

void Blackjack::finailizeResult(){

    int win = 0;
    int tie = 0;
    int lose = 0;
    
    float ratio;
    float reward = 0;
    
    for(int i = 0;i < player.totalHands();i++){
        reward += ratio = gameResultOfPlayerHand(i);
        if(ratio > 1.0){
            win++;
        }else if(ratio == 1.0){
            tie++;
        }else{
            lose++;
        }
    }
    
    reward *= wagerForThisRound;
    player.setMoney(player.getMoney() + reward);
    
    cout << endl;
    
    int totalHands = player.totalHands();
    
    if(win == totalHands){
        cout << "Player win!!";
    }else if(tie == totalHands){
        cout << "Tie!!";
    }else if(lose == totalHands){
        cout << "Dealer win!!";
    }else{
        cout << win << " hands win, " << tie << " hands tie, " << lose << " hands lose.";
    }
    cout << endl;
}