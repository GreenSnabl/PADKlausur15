#include "Cardgame.h"

Card::Card(Suit su, Face fa) : suit{su}, face{fa}
{
    switch((int)face)
    {
        case 0: case 1: case 2: points = 0; break;
        case 3: points = 10; break;
        case 4: points = 2; break;
        case 5: points = 3; break;
        case 6: points = 4; break;
        case 7: points = 11; break;
    }
}


std::string Card::toString() 
{
    std::ostringstream os;
    switch(suit) {
        case Suit::KARO : os << "\"KARO "; break; 
        case Suit::HERZ : os << "\"HERZ "; break;
        case Suit::PIK : os << "\"PIK "; break;
        case Suit::KREUZ : os << "\"KREUZ "; break;    
    }
    switch(face) {
        case Face::SIEBEN : os << "SIEBEN\""; break;
        case Face::ACHT : os << "ACHT\""; break;
        case Face::NEUN : os << "NEUN\""; break;
        case Face::ZEHN : os << "ZEHN\""; break;
        case Face::BUBE : os << "BUBE\""; break;
        case Face::DAME : os << "DAME\""; break;
        case Face::KOENIG : os << "KÖNIG\""; break;
        case Face::ASS : os << "ASS\""; break;    
    }
    return os.str();
}

int Card::getPoints()
{
    return points;
}


Player::Player(int i) : id{i}, sumOfPoints{0} {}

void Player::addPoints(int points)
{
    sumOfPoints += points;
}

int Player::getSumOfPoints()
{
    return sumOfPoints;
}

void Player::clearSumOfPoints()
{
    sumOfPoints = 0;
}

void Player::clearPlayerDeck() {
    while(playerDeck.size() > 0)
    playerDeck.pop_back();
}


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
    return playerDeck.back();
}

void Player::sort()
{
    std::sort(playerDeck.begin(), playerDeck.end());
}

int Player::getId()
{
    return id;
}

std::string Player::toString()
{
    std::ostringstream os;
    os << "Player " << getId() << " cards:\n";
    for(int i = 0; i < playerDeck.size(); ++i)
        os << playerDeck[i].toString() << "\t";
    os << "\n";
    for(int i = 0; i < playerDeck.size(); ++i)
        os << playerDeck[i].getPoints() << " Points\t";
    os << "\n";
    return os.str();
}

int Player::size()
{
    return playerDeck.size();
}


CardGame::CardGame()
{

    for(int i = 0; i < nrP; ++i){
        players.push_back(Player(i+1));
       // std::cout << "created Player " << players[i].getId() << " with " << players[i].getSumOfPoints()
       //         << " Points and " << players[i].size() << " Cards\n";
    
    }
    for (int i = 1; i < 5; ++i)         // initialize deck with 32 cards
        for(int j = 0; j < 8; ++j){      // each face once per suit  
            deck.push_back(Card((Suit)(i-1), (Face)j));
           // std::cout << "created " << i*8 + (j-7) << ". Card: " << deck.back().toString() <<"\n";
        }
    //std::cout << "\nneue Runde\n\n";
    //for(int i = 0; i < deck.size(); ++i) std::cout << "created Card: " << deck[i].toString() << "\n";
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

void CardGame::deal()
{
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 4; ++j){
            players[j].push_back(deck.back());
            deck.pop_back();
            //std::cout << "inside CardGame::deal() created Card for Player " << j+1 << " " << players[j].back().toString() << "\n";
    }    
    
    //for(int i = 0; i < nrP; ++i)
    //std::cout << "Size of player " << players[i].getId() << "s deck is " << players[i].size() << "\n";
    //for (int i = 0; i < 4; ++i)
    //    players[i].sort();
}

void CardGame::play(bool mode)
{
    int winnerId = zeroId;
    int highest = 0;
    int pointSum = 0;
    int round = 0;
    while(round < deckSize/nrP)
    {
        for(int i = 0; i < nrP; ++i){
            pointSum += players[i].back().getPoints();
            if(highest < players[i].back().getPoints()){highest = players[i].back().getPoints(); winnerId = players[i].getId();}
        }
        for(int i = 0; i < nrP; ++i)
            players[i].pop_back();
        players[winnerId-1].addPoints(pointSum);
        pointSum = 0;
        highest = 0;
        winnerId = zeroId;
        ++round;
    }
    if(mode)
    {
        for (int i = 0; i < players.size(); ++i)
            players[i].clearSumOfPoints();
    } 
}

std::string CardGame::showPlayers()
{
    std::ostringstream os;
    for (int i = 0; i < nrP; ++i) {
        os << players[i].toString();    
        }
    return os.str();
}

std::string CardGame::showResult()
{
    
    std::ostringstream os;
    os << "The winner is Player " << getWinnerId() << "\n";
    for(int i = 0; i < nrP; ++i)
    {
        os << "Player " << players[i].getId() << ": " << players[i].getSumOfPoints() << " Points\n";    
    }
    return os.str();
}


int CardGame::getWinnerId()
{
    int winnerId;
    int highest = 0;
    for (int i = 0; i < nrP; ++i)
        if(highest < players[i].getSumOfPoints()) { highest = players[i].getSumOfPoints(); winnerId = players[i].getId();}
    
    return winnerId;
}

