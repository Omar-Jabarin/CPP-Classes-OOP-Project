//
// Created by omar_ on 28/06/2023.
//

#include "Mtmchkin.h"

int main(){
    try {
        Mtmchkin game("deck.txt");
        while (!game.isGameOver()) {
            game.playRound();
            game.printLeaderBoard();
        }
    } catch(std::runtime_error& e){
        std::cout<<e.what();
        return 0;
    }
    catch(...){ //should never reach this point but better safe than sorry
        return 0;
    }

    return 0;

}