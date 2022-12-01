cmake_minimum_required(VERSION 3.23)
project(program4_template)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp Blackjack.cpp Blackjack.h Card.cpp Card.h Hand.cpp Hand.h Deck.cpp Deck.h)
