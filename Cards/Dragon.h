//
// Created by omar_ on 25/06/2023.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H
#define INFINITY 9001
#define DRAGON_LOOT 1000
#define DRAGON_POWER 25

#include "Card.h"

class Dragon : public BattleCard {

public:
    Dragon() : BattleCard(DRAGON_LOOT, DRAGON_POWER, INFINITY){}
    void applyDefeat(Player&) override;
    std::string getName() const override{ return "Dragon"; }
    void printCard(std::ostream &out) const override;
};

#endif //EX4_DRAGON_H
