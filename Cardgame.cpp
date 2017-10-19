#include "Cardgame.h"

std::string Card::toString() 
{
    std::ostringstream os;
    switch(suit) {
        case Suit::KARO : os << "KARO "; break; 
        case Suit::HERZ : os << "HERZ"; break;
        case Suit::PIK : os << "PIK"; break;
        case Suit::KREUZ : os << "KREUZ"; break;    
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

CardGame::CardGame()
{
    for(int i = 0; i < nrP; ++i)
        players.push_back(Player(i+1)); 
    
    for (int i = 0; i < 4; ++i)         // initialize deck with 32 cards
        for(int j = 0; j < 8; ++j)      // each face once per suit  
            deck.push_back(Card((Suit)i, (Face)j));
}

bool const Card::operator<(Card &a)
{
    if(suit == a.suit) return face < a.face;
    return suit < a.suit; 
}

void CardGame::shuffle()
{
    std::random_shuffle(deck.begin(), deck.end()); // random_shuffle aus C++ 98
}                                                  // kein <random> random_generator nötig
                                                   // aber schlechtere Zufallsnummern