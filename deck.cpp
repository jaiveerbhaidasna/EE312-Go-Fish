//
// Created by Jaiveer Bhaidasna on 11/8/2019.
//

#include "deck.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

    //Default constructor which creates a deck of 52 cards, seeds a random number generator for shuffling, and sets
    //the index of where to deal from as the top card
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

    //Returns the number of cards remaining in the deck
    int Deck::size() const {
        return SIZE - myIndex;
    }

    //Deals a card to the caller from the top of the deck if there are cards remaining
    Card Deck::dealCard() {
        myIndex++;
        return myCards[myIndex-1];
    }

    //Uses a random number generator to shuffle the deck of cards
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
