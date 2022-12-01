//
// Created by Erik Gabrielsen on 10/23/22.
//

#include "Blackjack.h"
#include "Deck.cpp"
#include "Deck.h"
#include <fstream>
#include<iostream>
#include"Hand.h"
#include"Hand.cpp"


using std::ifstream;
using namespace std;

Blackjack::Blackjack() {

}

void Blackjack::play() {
    // TODO: Implement play (Play the game of blackjack)
    // HINT: I would break this up into other functions to make life easier. Maybe comment out the logic FIRST then implement each piece!
    cout << "Welcome to Blackjack! Let's Play!\n" << std::endl;
    cout << "Loading Bank balance..."<<endl;
    Blackjack::getBalance();
    Blackjack::placeBets();
    

}
//Getting Initial balance 
void Blackjack::getBalance(){
    ifstream indata;
    
    indata.open("balance.txt");

    while (!indata.eof()){

    if(!indata){
        //Unable to open file
        cerr <<"Cannot retrieve account balance"<<endl;
        exit(1);    }
    indata >> balance;

            cout<<"Your balance is $"<< balance<<endl;
        indata >> balance;
    }
    indata.close();
}

void Blackjack::placeBets(){
    char reply = 'c';
    while (balance > 0 && reply == 'c'){
        temp = temp +  1;
        cout<<endl;
        cout<<"----- Hand "<<temp<<" -----"<<endl;
        cout<<"Place your bets: ";
        cin>>betValue;
        if (betValue > balance){
            cerr<<"The bet amount is more than the available balance";
            exit(1);
        }else{
            cout<<"Dealing cards...."<<endl;
            cout<<'\n';
            cout<<"Dealers Hand :"<<endl;
            
            string shown = Blackjack::deal();
            cout<<shown<<endl;
            tempValue2 = hand.getScore(dealCard);
            string hidden = Blackjack::deal();
            tempValue2 = tempValue2 + hand.getScore(dealCard);

            cout<<'\n';

            cout<<'\n';
            cout<<"Players Hand :"<<endl;

            cout<<Blackjack::deal()<<endl;
            tempVal = hand.getScore(dealCard);
            cout<<Blackjack::deal()<<endl;

            tempVal = tempVal + hand.getScore(dealCard);
            cout<<"Hand Value :"<<tempVal<<endl;
            cout<<'\n';

            char response = 's';
             cout<<"Enter 's' to stay or 'h' to hit: ";
             cin>>response;
             if (response == 's'){
                cout<<"Dealers Hand: "<<endl;
                cout<<shown<<endl;
                cout<<hidden<<endl;
                cout<<'\n';

                cout<<"Hand Value :"<<tempValue2<<endl;

                Blackjack::reward();
                
             }

             while (response == 'h' && tempVal<21){
                cout<<"New Card: "<<endl;
                cout<<Blackjack::deal()<<endl;
                tempVal = tempVal + hand.getScore(dealCard);
                cout<<"Hand Value :"<<tempVal<<endl;
                cout<<'\n';
                if (tempVal > 21){
                    cout<<"You are busted"<<'\n';
                }else if(tempVal == 21){
                    cout<<"You win Blackjack \n";
                }             
                else{
                    cout<<"Enter 's' to stay or 'h' to hit: ";
                    cin>>response;
                    if (response == 's'){
                        cout<<'\n';
                        cout<<"Dealers Hand: "<<endl;
                        cout<<shown<<endl;
                        cout<<hidden<<endl;
                        cout<<'\n';

                        cout<<"New Card: "<<endl;
                        cout<<Blackjack::deal()<<endl;
                        tempValue2 = tempValue2 + hand.getScore(dealCard);
                        cout<<"Hand Value :"<<tempValue2<<endl;
                        cout<<'\n';
                        if (tempValue2 > 21){
                            cout<<"Dealer busted; you win"<<'\n';
                            Blackjack::regularWin();
                            balance = balance + win;
                            Blackjack::updateBalance();

                        }else if(tempValue2 == 21){
                            cout<<"Dealer Blackjack win, You Loose \n";
                        }             
                        else if (tempValue2 > tempVal && tempValue2 <= 21){
                            cout<<"Dealer won"<<'\n';

                        }
                    cout<<"Hand Value :"<<tempValue2<<endl;
                        Blackjack::reward();

                    }
                    }
                }
             }
        
        cout<<'\n';
        cout<<"Enter 'c' to continue or 'q' to quit: ";
        cin>>reply; 
        }
    balance = balance - betValue;
    Blackjack::updateBalance();    

    cout<<'\n';
    cout<<"Enter 'c' to continue or 'q' to quit: ";
    cin>>reply;    

    }

string Blackjack::deal(){
   
    deck.shuffle(deck, 30);
    dealCard = deck.dealCard(deck);
    string myhand = dealCard.getRankString() + " of " + dealCard.getSuitString();
    //cout<<dealCard.getScore();
    return myhand;
    
}

void Blackjack::updateBalance(){
     ofstream file;
    file.open ("balance.txt");
    file << balance;
    file.close(); 
}

void Blackjack::regularWin(){
    win = betValue;
    cout<<"You have won: "<<win<<'\n';
    win = win + betValue;
}
void Blackjack::blackJackWin(){
    win = betValue * 1.5;
    cout<<"You have won: "<<win<<'\n';
    win = win + betValue;
}

void Blackjack::reward(){
    if (tempVal > 21){
        cout<<"You are busted"<<'\n';
        balance = balance - betValue;
        Blackjack::updateBalance();
                    
    }else if(tempVal == 21){
        Blackjack::blackJackWin(); 
        balance = balance + win;
        Blackjack::updateBalance();

    } else if (tempVal > tempValue2 && tempVal < 21){
        Blackjack::regularWin();
        balance = balance + win;
        Blackjack::updateBalance();
    }else if(tempValue2 > tempVal && tempValue2 <= 21){
        cout<<"You loose"<<'\n';
        balance = balance - betValue;
        Blackjack::updateBalance();
    }

}