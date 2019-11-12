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

    int choice;
    int numCards = 5;                                               //Instantiation of the number of cards a player
    int turn = 1;                                                   //gets, the number of players, and the turn of
    Player p1("Makenzie");                                          //a player
    Player p2("Jason");
    Player p3("Nick");
    Deck d;                                                         //Creates a deck as well as some temporary
    Card book1;                                                     //card variables to be used in implementation
    Card book2;
    Card chosen;
    Card drawn;
    ofstream myFile;                                                //Opening of a file to be written to
    myFile.open("gofish_results.txt");

    d.shuffle();                                                    //Give the deck of cards a good shuffle
    d.shuffle();
    d.shuffle();
    
    dealHand(d, p1, numCards);                                      //Dealing each player cards
    dealHand(d, p2, numCards);
    dealHand(d, p3, numCards);

    myFile << p1.getName() << "'s Opening Hand: " << p1.showHand() << "\n";         //Displaying each players
    myFile << p2.getName() << "'s Opening Hand: " << p2.showHand() << "\n";         //opening hand
    myFile << p3.getName() << "'s Opening Hand: " << p3.showHand() << "\n\n";

    while(p1.checkHandForBook(book1,book2)){                                        //Both players check for books
        p1.bookCards(p1.removeCardFromHand(book1),p1.removeCardFromHand(book2));    //in their opening hands and book
    }                                                                               //cards if one is found

    while(p2.checkHandForBook(book1,book2)){
        p2.bookCards(p2.removeCardFromHand(book1),p2.removeCardFromHand(book2));
    }

    while(p3.checkHandForBook(book1,book2)){
        p3.bookCards(p3.removeCardFromHand(book1),p3.removeCardFromHand(book2));
    }

    myFile << "Booking opening cards...\n\n";

    myFile << p1.getName() << "'s Cards: " << p1.showHand() << "\n";                //Displaying both player's hands
    myFile << p2.getName() << "'s Cards: " << p2.showHand() << "\n";                //and books after opening cards
    myFile << p3.getName() << "'s Cards: " << p3.showHand() << "\n\n";              //are booked
    myFile << p1.getName() << "'s Books:\n" << p1.showBooks() << "\n";
    myFile << p2.getName() << "'s Books:\n" << p2.showBooks() << "\n";
    myFile << p3.getName() << "'s Books:\n " << p3.showBooks() << "\n";

    myFile << "Beginning Game...\n\n";

    while(p1.getHandSize() > 0 || p2.getHandSize() > 0 || p3.getHandSize() > 0 ||
        d.size() > 0){                                                              //Play as long as the deck has cards
                                                                                    //or at least one player has cards
        while(turn == 1){                                                           //in hand
            if(p1.getHandSize() == 0 && d.size() > 0) {
                    drawn = d.dealCard();
                    p1.addCard(drawn);
                    myFile << p1.getName() << " draws " << drawn << "\n\n";         //During a player's turn, check if
            }                                                                       //they have cards in hand to
            else                                                                    //choose from, draw otherwise
                {
                    if(p1.getHandSize() > 0) {
                        chosen = p1.chooseCardFromHand();
                        choice = rand() % 2;                                        //Randomly select another player
                        if(choice == 0) {                                           //to ask
                            myFile << p1.getName() << " asks if " << p2.getName() << " has a "
                                   << chosen.rankString(chosen.getRank())
                                   << "?\n";
                            if (p2.rankInHand(chosen)) {
                                myFile << p2.getName() << " says yes, I have a " << chosen.rankString(chosen.getRank())
                                       << "\n";
                                myFile << p1.getName()
                                       << " books the cards\n\n";                   //If the other player
                                book1 = p1.removeCardFromHand(chosen);              //has a card of the
                                book2 = p2.removeCardFromHand(chosen);              //chosen rank, it is
                                p1.bookCards(book1, book2);                         //given and booked
                            } else {
                                myFile << p2.getName() << " says Go Fish\n";
                                if (d.size() > 0) {                                 //Otherwise, Go Fish
                                    drawn = d.dealCard();
                                    p1.addCard(drawn);
                                    myFile << p1.getName() << " draws " << drawn << "\n\n";
                                }
                                if (p1.checkHandForBook(book1,
                                                        book2)) {               //After drawing, check
                                    book1 = p1.removeCardFromHand(
                                            book1);                             //if drawn card made a
                                    book2 = p1.removeCardFromHand(
                                            book2);                             //book with another card
                                    p1.bookCards(book1, book2);
                                }
                                turn = 2;                                       //Next turn is played who was asked
                            }
                        }
                        else {
                            myFile << p1.getName() << " asks if " << p3.getName() << " has a "
                                   << chosen.rankString(chosen.getRank())
                                   << "?\n";
                            if (p3.rankInHand(chosen)) {
                                myFile << p3.getName() << " says yes, I have a " << chosen.rankString(chosen.getRank())
                                       << "\n";
                                myFile << p1.getName()
                                       << " books the cards\n\n";                   //If the other player
                                book1 = p1.removeCardFromHand(chosen);              //has a card of the
                                book2 = p3.removeCardFromHand(chosen);              //chosen rank, it is
                                p1.bookCards(book1, book2);                         //given and booked
                            } else {
                                myFile << p3.getName() << " says Go Fish\n";
                                if (d.size() > 0) {                                 //Otherwise, Go Fish
                                    drawn = d.dealCard();
                                    p1.addCard(drawn);
                                    myFile << p1.getName() << " draws " << drawn << "\n\n";
                                }
                                if (p1.checkHandForBook(book1,
                                                        book2)) {               //After drawing, check
                                    book1 = p1.removeCardFromHand(
                                            book1);                             //if drawn card made a
                                    book2 = p1.removeCardFromHand(
                                            book2);                             //book with another card
                                    p1.bookCards(book1, book2);
                                }
                                turn = 3;                                       //Next players turn
                            }
                        }
                    }
                    else
                        turn = 2;
                }
            myFile << p1.getName() << "'s Cards: " << p1.showHand() << "\n";                    //Displaying both
            myFile << p2.getName() << "'s Cards: " << p2.showHand() << "\n";                    //player's hands after
            myFile << p3.getName() << "'s Cards: " << p3.showHand() << "\n\n";                  //each's turn
        }

        while(turn == 2)
        {
            if(p2.getHandSize() == 0 && d.size() > 0) {
                    drawn = d.dealCard();
                    p2.addCard(drawn);
                    myFile << p2.getName() << " draws " << drawn << "\n\n";
            }
            else
                {
                    if(p2.getHandSize() > 0) {
                        chosen = p2.chooseCardFromHand();
                        choice = rand() % 2;
                        if (choice == 0) {
                            myFile << p2.getName() << " asks if " << p3.getName() << " has a "
                                   << chosen.rankString(chosen.getRank())
                                   << "?\n";
                            if (p3.rankInHand(chosen)) {
                                myFile << p3.getName() << " says yes, I have a " << chosen.rankString(chosen.getRank())
                                       << "\n";
                                myFile << p2.getName() << " books the cards\n\n";
                                book1 = p2.removeCardFromHand(chosen);
                                book2 = p3.removeCardFromHand(chosen);
                                p2.bookCards(book1, book2);
                            } else {
                                myFile << p3.getName() << " says Go Fish\n";
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
                                turn = 3;
                            }
                        }
                        else {
                            myFile << p2.getName() << " asks if " << p1.getName() << " has a "
                                   << chosen.rankString(chosen.getRank())
                                   << "?\n";
                            if (p1.rankInHand(chosen)) {
                                myFile << p1.getName() << " says yes, I have a " << chosen.rankString(chosen.getRank())
                                       << "\n";
                                myFile << p2.getName() << " books the cards\n\n";
                                book1 = p2.removeCardFromHand(chosen);
                                book2 = p1.removeCardFromHand(chosen);
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
                    }
                    else
                        turn = 3;
                }
            myFile << p1.getName() << "'s Cards: " << p1.showHand() << "\n";
            myFile << p2.getName() << "'s Cards: " << p2.showHand() << "\n";
            myFile << p3.getName() << "'s Cards: " << p3.showHand() << "\n\n";
        }

        while(turn == 3)
        {
            if(p3.getHandSize() == 0 && d.size() > 0) {
                drawn = d.dealCard();
                p3.addCard(drawn);
                myFile << p3.getName() << " draws " << drawn << "\n\n";
            }
            else
            {
                if(p3.getHandSize() > 0) {
                    chosen = p3.chooseCardFromHand();
                    choice = rand() % 2;
                    if (choice == 0) {
                        myFile << p3.getName() << " asks if " << p1.getName() << " has a "
                               << chosen.rankString(chosen.getRank())
                               << "?\n";
                        if (p1.rankInHand(chosen)) {
                            myFile << p1.getName() << " says yes, I have a " << chosen.rankString(chosen.getRank())
                                   << "\n";
                            myFile << p3.getName() << " books the cards\n\n";
                            book1 = p3.removeCardFromHand(chosen);
                            book2 = p1.removeCardFromHand(chosen);
                            p3.bookCards(book1, book2);
                        } else {
                            myFile << p1.getName() << " says Go Fish\n";
                            if (d.size() > 0) {
                                drawn = d.dealCard();
                                p3.addCard(drawn);
                                myFile << p3.getName() << " draws " << drawn << "\n\n";
                            }
                            if (p3.checkHandForBook(book1, book2)) {
                                book1 = p3.removeCardFromHand(book1);
                                book2 = p3.removeCardFromHand(book2);
                                p3.bookCards(book1, book2);
                            }
                            turn = 1;
                        }
                    }
                    else {
                        myFile << p3.getName() << " asks if " << p2.getName() << " has a "
                               << chosen.rankString(chosen.getRank())
                               << "?\n";
                        if (p2.rankInHand(chosen)) {
                            myFile << p2.getName() << " says yes, I have a " << chosen.rankString(chosen.getRank())
                                   << "\n";
                            myFile << p3.getName() << " books the cards\n\n";
                            book1 = p3.removeCardFromHand(chosen);
                            book2 = p2.removeCardFromHand(chosen);
                            p3.bookCards(book1, book2);
                        } else {
                            myFile << p2.getName() << " says Go Fish\n";
                            if (d.size() > 0) {
                                drawn = d.dealCard();
                                p3.addCard(drawn);
                                myFile << p3.getName() << " draws " << drawn << "\n\n";
                            }
                            if (p3.checkHandForBook(book1, book2)) {
                                book1 = p3.removeCardFromHand(book1);
                                book2 = p3.removeCardFromHand(book2);
                                p3.bookCards(book1, book2);
                            }
                            turn = 2;
                        }
                    }
                }
                else
                    turn = 1;
            }
            myFile << p1.getName() << "'s Cards: " << p1.showHand() << "\n";
            myFile << p2.getName() << "'s Cards: " << p2.showHand() << "\n";
            myFile << p3.getName() << "'s Cards: " << p3.showHand() << "\n\n";
        }
        myFile << p1.getName() << "'s Books:\n" << p1.showBooks() << "\n";              //Displaying all player's books
        myFile << p2.getName() << "'s Books:\n" << p2.showBooks() << "\n";              //after each has a turn
        myFile << p3.getName() << "'s Books:\n" << p3.showBooks() << "\n";
    }

    myFile << "Game Over!\n";                                                           //Check who won based on number
    if(p1.getBookSize() == p2.getBookSize() && p1.getBookSize() > p3.getBookSize())     //of books
        myFile << "The game ended in a tie between " << p1.getName() << " and " << p2.getName() << " who each had "
            << p1.getBookSize() << " books!";
    else
        if(p1.getBookSize() == p3.getBookSize() && p1.getBookSize() > p2.getBookSize())
            myFile << "The game ended in a tie between " << p1.getName() << " and " << p3.getName() << " who each had "
                   << p1.getBookSize() << " books!";
        else
            if(p2.getBookSize() == p3.getBookSize() && p2.getBookSize() > p1.getBookSize())
                myFile << "The game ended in a tie between " << p2.getName() << " and " << p3.getName()
                    << " who each had " << p2.getBookSize() << " books!";
            else
                if(p1.getBookSize() > p2.getBookSize() && p1.getBookSize() > p3.getBookSize())
                    myFile << p1.getName() << " won with " << p1.getBookSize() << " books!";
                else
                    if(p2.getBookSize() > p1.getBookSize() && p2.getBookSize() > p3.getBookSize())
                        myFile << p2.getName() << " won with " << p2.getBookSize() << " books!";
                    else
                        myFile << p3.getName() << " won with " << p3.getBookSize() << " books!";

    myFile.close();                                                                     //Close the output file
    return EXIT_SUCCESS;
}


void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}



