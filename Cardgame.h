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


class Card{
    Suit suit;
    Face face;
    int points;
public:
    Card(Suit su, Face fa) : suit{su}, face{fa}, points{(int)face} {}
    std::string toString();
    bool const operator<(Card&);
    

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
    
    void setId(int);
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
    
private:
    std::array<Player,nrP> players;
    std::array<Card, deckSize> deck;


};


#endif /* CARDGAME_H */

