#include "Cardgame.h"



int main() {
    
    
    Player p(1);
    Card c(Suit::HERZ, Face::ACHT);
    std::cout << c.toString() << "\n";
    p.push_back(c);
    p.push_back(c);
    p.push_back(c);
    p.push_back(c);
    std::cout << p.toString();
    

    return 0;
}

