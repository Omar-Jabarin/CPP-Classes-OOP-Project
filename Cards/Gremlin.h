//
// Created by omar_ on 25/06/2023.
//

#ifndef EX4_GREMLIN_H
#define EX4_GREMLIN_H
#include "Card.h"

class Gremlin : public BattleCard {

public:
    Gremlin() : BattleCard(2, 5 , 10){}

    void applyDefeat(Player&) override;
    std::string getName() const override{ return "Gremlin"; }
};


#endif //EX4_GREMLIN_H
