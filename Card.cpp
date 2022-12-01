#include "Card.h"

Card::Card(): rank{-1}, suit{-1} {}

Card::Card(int rank, int suit) {
    this->suit = suit;
    this->rank = rank;
}

string Card::getRankString() const{
    switch(this->rank){
        case TWO:
            return "Two";
        case THREE:
            return "Three";
        case FOUR:
            return "Four";
        case FIVE:
            return "Five";
        case SIX:
            return "Six";
        case SEVEN:
            return "Seven";
        case EIGHT:
            return "Eight";
        case NINE:
            return "Nine";
        case TEN:
            return "Ten";
        case JACK:
            return "Jack";
        case QUEEN:
            return "Queen";
        case KING:
            return "King";
        case ACE:
            return "Ace";
        default:
            return "error";
    }
}

int Card::getRank() const{
    return rank;
}

string Card::getSuitString() const {
    switch(this->suit){
        case HEART:
            return "Hearts";
        case DIAMOND:
            return "Diamonds";
        case SPADE:
            return "Spades";
        case CLUB:
            return "Clubs";
        default:
            return "error";
    }
}

int Card::getSuit() const {
    return suit;
}

int Card::getScore() const {
    switch(this->rank){
        case TWO:
            return 2;
        case THREE:
            return 3;
        case FOUR:
            return 4;
        case FIVE:
            return 5;
        case SIX:
            return 6;
        case SEVEN:
            return 7;
        case EIGHT:
            return 8;
        case NINE:
            return 9;
        case TEN:
        case JACK:
        case QUEEN:
        case KING:
            return 10;
        case ACE:
            return 11;
        default:
            return 0;
    }
}