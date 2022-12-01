#ifndef PROGRAM4_CARD_H
#define PROGRAM4_CARD_H

#include <string>

using std::string;

enum SUIT { HEART, DIAMOND, SPADE, CLUB };
enum RANK { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

class Card {
public:
    Card();
    Card(int, int);

    int getRank() const;
    int getSuit() const;
    int getScore() const;
    string getRankString() const;
    string getSuitString() const;

private:
    int rank;
    int suit;
    
};


#endif