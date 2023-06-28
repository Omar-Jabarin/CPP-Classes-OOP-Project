//
// Created by omar_ on 25/06/2023.
//

#ifndef EX4_GREMLIN_H
#define EX4_GREMLIN_H
#include "Card.h"

#define GREMLIN_LOOT 2
#define GREMLIN_POWER 5
#define GREMLIN_DAMAGE 10

class Gremlin : public BattleCard {

public:
    Gremlin() : BattleCard(GREMLIN_LOOT, GREMLIN_POWER , GREMLIN_DAMAGE){}

    void applyDefeat(Player&) override;
    std::string getName() const override{ return "Gremlin"; }
};


#endif //EX4_GREMLIN_H
