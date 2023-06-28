//
// Created by omar_ on 25/06/2023.
//

#ifndef EX4_NINJA_H
#define EX4_NINJA_H

#include "Player.h"


class Ninja : public Player {
public:
    explicit Ninja(std::string name, int hp = DEFAULT_HP);
    void addCoins(int coins) override;
    std::string getJob() const override { return "Ninja"; }
};


#endif //EX4_NINJA_H
