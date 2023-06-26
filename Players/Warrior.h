//
// Created by omar_ on 25/06/2023.
//

#ifndef EX4_WARRIOR_H
#define EX4_WARRIOR_H
#include "Player.h"

class Warrior : public Player {
public:
   explicit Warrior(std::string name, int hp = 100);

    std::string getJob() const override { return "Warrior"; }
    int getAttackStrength() const override;
};

#endif //EX4_WARRIOR_H
