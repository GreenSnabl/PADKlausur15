#include "Cardgame.h"
#include <ctime>



void f() 
{
    std::srand(time(0));
    CardGame game;
    game.shuffle();
    game.deal();
    std::cout << game.showPlayers();
    game.play(false);
    std::cout << game.showResult();
}

int main() {
    
    f();


    
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

