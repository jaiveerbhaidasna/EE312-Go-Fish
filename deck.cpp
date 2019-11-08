//
// Created by Jaiveer Bhaidasna on 11/8/2019.
//

#include "deck.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

    Deck::Deck(){
        unsigned int currentTime =  (unsigned)time(0);
        srand(currentTime);
        myIndex = 0;
        for(int i = 0; i < 4; i++)
            for(int j = 1; j < 14; j++)
            {
                myCards[myIndex] = Card(j,(Card::Suit) i);
                myIndex++;
            }
        myIndex = 0;
    }

    int Deck::size() const {
        return SIZE - myIndex;
    }

    Card Deck::dealCard() {
        myIndex++;
        return myCards[myIndex-1];
    }

    void Deck::shuffle() {
        int numCards = size();
        int rand1 = 0, rand2 = 0;

        if(numCards >= 2){
            for(int i = 0; i < numCards * 5; i++)
            {
                rand1 = (rand() % numCards) + myIndex;
                rand2 = (rand() % numCards) + myIndex;

                Card temp = myCards[rand1];
                myCards[rand1] = myCards[rand2];
                myCards[rand2] = temp;
            }
        }
    }
