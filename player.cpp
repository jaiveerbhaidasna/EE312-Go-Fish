//
// Created by Jaiveer Bhaidasna on 11/8/2019.
//

#include "player.h"
#include "deck.h"

using namespace std;

    string Player::showHand() const {
        string hand;
        for(int i = 0; i < myHand.size(); i++)
            hand += myHand[i].toString() +  " ";
        return hand;
    }

    string Player::showBooks() const {
        string books;
        for(int i = 0; i < myBook.size(); i+=2)
            books += myBook[i].toString() + " & " + myBook[i+1].toString() + "\n";
        return books;
    }

    void Player::addCard(Card c) {
        myHand.push_back(c);
    }

    void Player::bookCards(Card c1, Card c2) {
        myBook.push_back(c1);
        myBook.push_back(c2);
    }

    bool Player::rankInHand(Card c) const {
        for(int i = 0; i < myHand.size(); i++)
            if(c.getRank() == myHand[i].getRank())
                return true;
            return false;
    }

    bool Player::cardInHand(Card c) const {
        for(int i = 0; i < myHand.size(); i++)
            if(c == myHand[i])
                return true;
            return false;
    }

    Card Player::removeCardFromHand(Card c) {
        for(int i = 0; i < myHand.size(); i++)
            if (c == myHand[i])
                myHand.erase(myHand.begin() + i);
        return c;
    }

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

    Card Player::chooseCardFromHand() const {
        return myHand[rand() % myHand.size()];
    }