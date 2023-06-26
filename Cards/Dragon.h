//
// Created by omar_ on 25/06/2023.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H
#define INFINITY 9001

#include "Card.h"

class Dragon : public BattleCard {

public:
    Dragon() : BattleCard(1000, 25, INFINITY){}
    void applyDefeat(Player&) override;
    std::string getName() const override{ return "Dragon"; }
    void printCard(std::ostream &out) const override;
};

#endif //EX4_DRAGON_H
