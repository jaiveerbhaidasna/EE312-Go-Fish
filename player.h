// FILE:  player.h
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "card.h"
using namespace std;

class Player
{
  public:
    Player();                   //Default construcdtor

    //Overloaded constructor to give a name to a player
    Player(string name) {
       myName = name;
    }

    //Get method which returns the name of a given player
    string getName() const {
       return myName;
    }
    
    void addCard(Card c);  //adds a card to the hand
    void bookCards(Card c1, Card c2);   //Books two cards and adds them to the Player's books

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair. 
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

    bool checkHandForBook(Card &c1, Card &c2);

    //OPTIONAL
    // comment out if you decide to not use it    
    //Does the player have a card with the same rank as c in her hand?
    bool rankInHand(Card c) const; 
    
    //uses some strategy to choose one card from the player's
    //hand so they can say "Do you have a 4?"
    Card chooseCardFromHand() const;
    
    //Does the player have the card c in her hand?
    bool cardInHand(Card c) const; 
    
    //Remove the card c from the hand and return it to the caller
    Card removeCardFromHand(Card c);
    
    string showHand() const;                //Displays the cards in hand of a given player
    string showBooks() const;               //Displays the books of a given player

    //Returns the number of cards in a given player's hand
    int getHandSize() const{
        return myHand.size();
    }

    //Returns the number of books a given player has
    int getBookSize() const{
        return myBook.size()/2;
    };
       
    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair. 
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
    //bool checkHandForPair(Card &c1, Card &c2);

    //OPTIONAL
    // comment out if you decide to not use it    
    //Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c
    //bool sameRankInHand(Card c) const;
    
    
  private:
          
    vector <Card> myHand;
    vector <Card> myBook;
    
    string myName;     
   
};


#endif