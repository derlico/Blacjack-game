#ifndef PROGRAM4_HAND_H
#define PROGRAM4_HAND_H

#include <vector>
#include "Card.h"

class Hand {
public:
    Hand();

    int getScore(Card& dealCard);
    void addCard(Card c);

private:
    std::vector<Card> cards;
    Card hand;
};


#endif //PROGRAM4_HAND_H
