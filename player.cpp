//
// Created by Jaiveer Bhaidasna on 11/8/2019.
//

#include <cstdlib>
#include "player.h"
#include "deck.h"

using namespace std;

    //Returns a concatenated string with the cards in a given player's hand
    string Player::showHand() const {
        string hand;
        for(int i = 0; i < myHand.size(); i++)
            hand += myHand[i].toString() +  " ";
        return hand;
    }

    //Returns a concatenated string with a given player's books
    string Player::showBooks() const {
        string books;
        for(int i = 0; i < myBook.size(); i+=2)
            books += myBook[i].toString() + " & " + myBook[i+1].toString() + "\n";
        return books;
    }

    //Adds a card to a given player's hand
    void Player::addCard(Card c) {
        myHand.push_back(c);
    }

    //Takes two cards and adds them to a given player's books
    void Player::bookCards(Card c1, Card c2) {
        myBook.push_back(c1);
        myBook.push_back(c2);
    }

    //Checks if a given player has a card with the same rank as the input parameter Card
    bool Player::rankInHand(Card c) const {
        for(int i = 0; i < myHand.size(); i++)
            if(c.getRank() == myHand[i].getRank())
                return true;
            return false;
    }

    //Checks if a given player has a card that is the exact same as the input parameter Card
    bool Player::cardInHand(Card c) const {
        for(int i = 0; i < myHand.size(); i++)
            if(c == myHand[i])
                return true;
            return false;
    }

    //Removes a card from a player's hand based on if the Card is what is being looked for, or if a Card has the same
    //rank as the given Card
    Card Player::removeCardFromHand(Card c) {
        for(int i = 0; i < myHand.size(); i++)
            if (c == myHand[i]) {
                myHand.erase(myHand.begin() + i);
                return c;
            }

        for(int i = 0; i < myHand.size(); i++)
            if (myHand[i].getRank() == c.getRank()) {
                c = myHand[i];
                myHand.erase(myHand.begin() + i);
            }
        return c;
    }

    //Returns true if a given player's hand contains a book, AKA two cards of the same rank, false otherwise
    //If a book is fond, populates the two inputs with those cards
    bool Player::checkHandForBook(Card &c1, Card &c2) {
        for(int i = 0; i < myHand.size()-1; i++)
            for(int j = i + 1; j < myHand.size(); j++)
            {
                if(myHand[i].getRank() == myHand[j].getRank())
                {
                    c1 = myHand[i];
                    c2 = myHand[j];
                    return true;
                }
            }
        return false;
    }

    //Returns a selected card from a Player's hand
    Card Player::chooseCardFromHand() const {
        return myHand[rand() % myHand.size()];
    }