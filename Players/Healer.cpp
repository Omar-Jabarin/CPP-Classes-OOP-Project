//
// Created by omar_ on 25/06/2023.
//

#include "Healer.h"



Healer::Healer(std::string name, int hp) : Player(name, hp) {}


void Healer::heal(int points) {
    Player::heal(2*points);
}