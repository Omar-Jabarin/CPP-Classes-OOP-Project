//
// Created by omar_ on 25/06/2023.
//

#include "Player.h"
#include "Warrior.h"



Warrior::Warrior(std::string name, int hp) : Player(name, hp) {}

int Warrior::getAttackStrength() const {
    return m_stats.level + 2*m_stats.force;
}