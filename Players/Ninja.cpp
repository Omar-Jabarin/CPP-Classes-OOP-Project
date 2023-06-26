//
// Created by omar_ on 25/06/2023.
//

#include "Ninja.h"

Ninja::Ninja(std::string name, int hp) : Player(name, hp) {}

void Ninja::addCoins(int coins) {
    Player::addCoins(2*coins);
    // m_stats["coins"] += 2*coins;
}


