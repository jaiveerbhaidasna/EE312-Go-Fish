// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides myFile and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);

int main( )
{

    int numCards = 7;
    int turn = 1;
    Player p1("Makenzie");
    Player p2("Jason");
    Deck d;
    Card book1;
    Card book2;
    Card chosen;
    Card drawn;
    ofstream myFile;
    myFile.open("output.txt");

    d.shuffle();
    d.shuffle();
    d.shuffle();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    myFile << p1.getName() << "'s Opening Hand: " << p1.showHand() << "\n";
    myFile << p2.getName() << "'s Opening Hand: " << p2.showHand() << "\n\n";

    while(p1.getHandSize() > 0 || p2.getHandSize() > 0 || d.size() > 0){

        while(p1.checkHandForBook(book1,book2)){
            p1.bookCards(p1.removeCardFromHand(book1),p1.removeCardFromHand(book2));
        }

        while(p2.checkHandForBook(book1,book2)){
            p2.bookCards(p2.removeCardFromHand(book1),p2.removeCardFromHand(book2));
        }

        myFile << p1.getName() << "'s Cards: " << p1.showHand() << "\n";
        myFile << p2.getName() << "'s Cards: " << p2.showHand() << "\n\n";
        myFile << p1.getName() << "'s Books:\n" << p1.showBooks() << "\n";
        myFile << p2.getName() << "'s Books:\n" << p2.showBooks() << "\n";

        while(turn == 1){
            if(p1.getHandSize() == 0 && d.size() > 0) {
                    drawn = d.dealCard();
                    p1.addCard(drawn);
                    myFile << p1.getName() << " draws " << drawn << "\n";
            }
            else
                {
                    if(p1.getHandSize() > 0) {
                        chosen = p1.chooseCardFromHand();
                        myFile << p1.getName() << " asks if " << p2.getName() << " has a "
                             << chosen.rankString(chosen.getRank())
                             << "?\n";
                        if (p2.rankInHand(chosen)) {
                            myFile << p2.getName() << " says yes, I have a " << chosen.rankString(chosen.getRank())
                                 << "\n";
                            myFile << p1.getName() << " books the cards\n\n";
                            book1 = p1.removeCardFromHand(chosen);
                            book2 = p2.removeCardFromHand(chosen.getRank(), chosen);
                            p1.bookCards(book1, book2);
                        } else {
                            myFile << p2.getName() << " says Go Fish\n";
                            if (d.size() > 0) {
                                drawn = d.dealCard();
                                p1.addCard(drawn);
                                myFile << p1.getName() << " draws " << drawn << "\n\n";
                            }
                            if (p1.checkHandForBook(book1, book2)) {
                                book1 = p1.removeCardFromHand(book1);
                                book2 = p1.removeCardFromHand(book2);
                                p1.bookCards(book1, book2);
                            }
                            turn = 2;
                        }
                    }
                    else
                        turn = 2;
                }
        }

        while(turn == 2)
        {
            if(p2.getHandSize() == 0 && d.size() > 0) {
                    drawn = d.dealCard();
                    p2.addCard(drawn);
                    myFile << p2.getName() << " draws " << drawn << "\n";
            }
            else
                {
                    if(p2.getHandSize() > 0) {
                        chosen = p2.chooseCardFromHand();
                        myFile << p2.getName() << " asks if " << p1.getName() << " has a "
                             << chosen.rankString(chosen.getRank())
                             << "?\n";
                        if (p1.rankInHand(chosen)) {
                            myFile << p1.getName() << " says yes, I have a " << chosen.rankString(chosen.getRank())
                                 << "\n";
                            myFile << p2.getName() << " books the cards\n\n";
                            book1 = p2.removeCardFromHand(chosen);
                            book2 = p1.removeCardFromHand(chosen.getRank(), chosen);
                            p2.bookCards(book1, book2);
                        } else {
                            myFile << p1.getName() << " says Go Fish\n";
                            if (d.size() > 0) {
                                drawn = d.dealCard();
                                p2.addCard(drawn);
                                myFile << p2.getName() << " draws " << drawn << "\n\n";
                            }
                            if (p2.checkHandForBook(book1, book2)) {
                                book1 = p2.removeCardFromHand(book1);
                                book2 = p2.removeCardFromHand(book2);
                                p2.bookCards(book1, book2);
                            }
                            turn = 1;
                        }
                    }
                    else
                        turn = 1;
                }
        }
    }
    myFile << p1.getName() << "'s Books:\n" << p1.showBooks() << "\n";
    myFile << p2.getName() << "'s Books:\n" << p2.showBooks() << "\n";
    if(p1.getBookSize() == p2.getBookSize())
        myFile << "The game between " << p1.getName() << " and " << p2.getName() << " in a tie! 13 books each!";
    else
        if(p1.getBookSize() > p2.getBookSize())
        {
            myFile << p1.getName() << " won the game against " << p2.getName() << " with " << p1.getBookSize() <<
            " books to " << p2.getBookSize() << "!";

        }
        else
        {
            myFile << p2.getName() << " won the game against " << p1.getName() << " with " << p2.getBookSize() <<
            " books to " << p1.getBookSize() << "!";
        }
    myFile.close();
    return EXIT_SUCCESS;
}


void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}



