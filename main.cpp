#include "Cardgame.h"



int main() {
    
    
    CardGame game;
    game.deal();
    std::cout << game.showPlayers();
    
    CardGame game2;
    //game2.shuffle();
    game2.deal();
    std::cout << game2.showPlayers();
    //game.play(false);
    
    
    /*
    Player p(1);
    Card c(Suit::HERZ, Face::ACHT);
    std::cout << c.toString() << "\n";
    p.push_back(c);
    p.push_back(c);
    p.push_back(c);
    p.push_back(c);
    std::cout << p.toString();
    */

    return 0;
}

