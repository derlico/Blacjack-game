#include <iostream>
#include "Blackjack.h"
#include "Blackjack.cpp"
#include <ctime>

int main() {
    srand(time(nullptr)); // seeded for your shuffle

    Blackjack game;
    game.play();

    return 0;
}