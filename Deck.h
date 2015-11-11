using namespace std;

#ifndef Deck_h
#define Deck_h
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Card.h"
#include <iostream>

class Deck
{
public:
    Deck();
    void Shuffle();
    void printDeck();
    Card GetNextCard();
    const int max_ranks = 13;
    const int max_suits = 4;
    const int deck_size = 52;
    
private:
    Card *deck;
    int current_card;
};

//creates the deck
Deck::Deck() {
    //array of strings that holds all of the ranks
    string Ranks[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack",
        "Queen", "King"};
    
    //array of strings that holds all of the suits
    string Suits[] = {"Spades", "Diamonds", "Hearts", "Clubs"};
    
    //creates a new deck
    //deck = new Card[deck_size];
    
    //keeps track of the top card
    current_card = 0;
    
    //populates the deck with 52 cards
    for (int i = 0; i < deck_size; i++)
    {
        deck[i] = Card(Suits[i / 13], Ranks[i % 13]);
    }
}

//shuffles the deck by going through and swapping 2 random cards at a time
void Deck::Shuffle()
{
    current_card = 0;
    for (int i = 0; i < deck_size; i++)
    {
        int j = (rand() + time(0)) % deck_size;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

//returns the current card
Card Deck::GetNextCard()
{
    //if statement to make sure we havent dealt all of the cards already. if so, shuffle them(repopulate deck)
    if (current_card > deck_size)
    {
        //optional: cout << "You are out of cards, redirecting to shuffle" << endl;
        Shuffle();
    }
    if (current_card < deck_size)
    {
        return (deck[current_card++]);
    }
    return (deck[0]);
}

#endif /* Deck_h */
