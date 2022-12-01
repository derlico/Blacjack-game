#ifndef PROGRAM4_BLACKJACK_H
#define PROGRAM4_BLACKJACK_H

#include <iostream>
//#include "Deck.cpp"
#include "Deck.h"
#include "Hand.h"

class Blackjack {
public:
    Blackjack();

    void play();
    void getBalance();
    void updateBalance();
    void placeBets();
    void regularWin();
    void blackJackWin();
    void reward();
    string deal();
    int handValue(Card& dealCard);

private:
    int betValue;
    int balance;
    int temp = 0;
    int win;
    int tempValue2;
    int tempVal;
    Deck deck;
    Card dealCard;
    Hand hand;
};


#endif