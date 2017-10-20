#include "Cardgame.h"
#include <ctime>



void f() 
{
    
    CardGame game;
    game.shuffle();
    game.deal();
    std::cout << game.showPlayers();
    game.play(false);
    //std::cout << game.showResult();
    game.deal();
    game.play(true);
    game.deal();
    game.play(true);
    //std::cout << game.showResult();
}

int main() {
    std::srand(time(0));
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

