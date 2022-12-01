#ifndef PROGRAM4_DECK_H
#define PROGRAM4_DECK_H

#include <random>
#include <vector>
#include "Card.h"

class Deck {
public:
    Deck();

    Card dealCard(Deck& deck);
    void addCard(Card);
    void shuffle(Deck& deck, int times = 20);
    void initialize(Deck& deck);
    void printDeck( const Deck& deck);
    //string deckString();

private:
    std::vector<Card> cards;
    int deckSize = 52;
    Card card;
};


#endif