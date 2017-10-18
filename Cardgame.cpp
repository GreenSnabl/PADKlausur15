#include "Cardgame.h"

std::string Card::toString() 
{
    std::ostringstream os;
    switch(suit) {
        case Suit::Karo : os << "Karo "; break; 
        case Suit::Herz : os << "Herz"; break;
        case Suit::Pik : os << "Pik"; break;
        case Suit::Kreuz : os << "Kreuz"; break;    
    }
    switch(face) {
        case Face::SIEBEN : os << "SIEBEN"; break;
        case Face::ACHT : os << "ACHT"; break;
        case Face::NEUN : os << "NEUN"; break;
        case Face::ZEHN : os << "ZEHN"; break;
        case Face::BUBE : os << "BUBE"; break;
        case Face::DAME : os << "DAME"; break;
        case Face::KOENIG : os << "KÖNIG"; break;
        case Face::ASS : os << "ASS"; break;    
    }
    return os.str();
}

Player::Player(int i) : id{i}, sumOfPoints{0} {}

void Player::push_back(Card c)
{
    playerDeck.push_back(c);
}
void Player::pop_back() 
{
    playerDeck.pop_back();
}
Card Player::back()
{
    return playerDeck[playerDeck.size()];
}
/*
CardGame::CardGame()
{
    //players{Player(1), Player(2), Player(3), Player(4)};
    
    for (int i = 0; i < nrP; ++i)       // initialize 4 players
        players[i] = Player(i+1);       // with ID 1, 2 ,3 ,4 respectively
    
    
    for (int i = 0; i < 4; ++i)         // initialize deck with 32 cards
        for(int j = 0; j < 8; ++j)      // each face once per suit  
            deck[i*8 + j] = Card((Suit)i, (Face)j);
}*/

bool const Card::operator<(Card &a)
{
    if(suit == a.suit) return face < a.face;
    return suit < a.suit; 
    
}