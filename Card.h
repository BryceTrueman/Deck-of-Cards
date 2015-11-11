//
//  Card.hpp
//  Deck of Cards
//
//  Created by Bryce Trueman on 11/10/15.
//  Copyright © 2015 ___BRYCETRUEMAN__. All rights reserved.
//

using namespace std;

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <ctime>
#pragma once


class Card {
    
public:
    //creates a card object that has two attributes, suit(1 of 4) and rank(ace-king)
    Card(string card_suit, string card_rank);
    ~Card(){};
//private:
    string suit;
    string rank;
};

Card::Card(string card_suit, string card_rank)
{
    suit = card_suit;
    rank = card_rank;
}







#endif /* Card_hpp */
