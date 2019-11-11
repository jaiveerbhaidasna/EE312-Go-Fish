//
// Created by Jaiveer Bhaidasna on 11/8/2019.
//

#include "card.h"
#include <string>

using namespace std;

    //Default constructor
    Card::Card(){
        myRank = 1;
        mySuit = spades;
    }

    //Overloaded constructor
    Card::Card(int rank, Card::Suit s){
        myRank = rank;
        mySuit = s;
    }

    //Returns a given card in string form
    string Card::toString() const {
        return rankString(this->myRank) + suitString(this->mySuit);
    }

    //Returns true if two cards have the same suit, false otherwise
    bool Card::sameSuitAs(const Card &c) const {
        if(this->mySuit == c.mySuit)
            return true;
        return false;
    }

    //Returns the rank of a given card
    int Card::getRank() const {
        return myRank;
    }

    //Determines the string output of a given card's suit
    string Card::suitString(Card::Suit s) const {
        if(s == spades)
            return "s";
        if(s == hearts)
            return "h";
        if(s == diamonds)
            return "d";

        return "c";
    }

    //Determines the string output of a given card's rank
    string Card::rankString(int r) const {
        switch (r)
        {
            case 1: return "A";
            case 2: return "2";
            case 3: return "3";
            case 4: return "4";
            case 5: return "5";
            case 6: return "6";
            case 7: return "7";
            case 8: return "8";
            case 9: return "9";
            case 10: return "10";
            case 11: return "J";
            case 12: return "Q";
            default: return "K";
        }
    }

    //Overloaded operator which returns true if two cards are equal in both suit and rank, false otherwise
    bool Card::operator==(const Card &rhs) const {
        return (this->mySuit == rhs.mySuit && this->myRank == rhs.myRank);
    }

    //Overloaded operator which returns true if two cards are not equal in suit or rank, false otherwise
    bool Card::operator!=(const Card &rhs) const {
        return (this->myRank != rhs.mySuit || this->myRank != rhs.myRank);
    }

    //Output of a Card object
    ostream& operator << (ostream& out, const Card& c){
        out << c.toString();
        return out;
    }




