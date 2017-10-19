#ifndef CARDGAME_H
#define CARDGAME_H
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

enum class Suit{KARO, HERZ, PIK, KREUZ};
enum class Face{SIEBEN, ACHT, NEUN, ZEHN, BUBE, DAME, KOENIG, ASS};
const int zeroId = -1; 

class Card{
    Suit suit;
    Face face;
    int points;
public:
    Card(Suit, Face);
    std::string toString();
    bool const operator<(Card&);
    int getPoints();
};


class Player{
private:
    int id;
    int sumOfPoints;
    std::vector<Card> playerDeck;
public:
    Player(int);
    void clearPlayerDeck();
    void push_back(Card);
    void pop_back();
    Card back();
    int size();
    void clearSumOfPoints();
    void addPoints(int);
    std::string toString();
    void sort();
    
    int getSumOfPoints();
    int getId();
};

class CardGame{
    
public:   
    const static int nrP = 4;
    const static int deckSize = 32;
    CardGame();
    void shuffle();
    void deal();
    void play(bool);
    std::string showPlayers();
    std::string showResult();
    
    int getWinnerId();
    
private:
   std::vector<Player> players;
   std::vector<Card> deck;
};


#endif /* CARDGAME_H */

