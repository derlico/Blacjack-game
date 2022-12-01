//
// Created by Erik Gabrielsen on 10/23/22.
//

#include "Deck.h"
#include<vector>
#include "Card.h"
#include "Card.cpp"
#include<iostream>

using namespace std;
Deck::Deck(){
    int count = 0;
    while(count <=deckSize){
         for (int rank = 0; rank < 12; rank++){
            for (int suit = 0; suit < 4; suit++){
                cards.push_back(Card(rank, suit));
                  //cout<<iRank <<":"<<iSuit<<endl;
            }
        }

        count = count + 1;

    }
   
}


void Deck::shuffle(Deck& deck, int times) {

    srand(time(0));
    for (int i=0; i< times ;i++)
    {
        // TODO implement shuffle
        int rNo = i + (rand() % (52 -i));
  
        swap(cards[i], cards[rNo]);
    }
}


Card Deck::dealCard(Deck& deck) {
    // TODO: Implement Deal Card
    // Should remove the "top" card in the deck
    Card result = cards.front();
	cards.pop_back();
	return result;
}
