//
// Created by omar_ on 25/06/2023.
//

#ifndef EX4_WITCH_H
#define EX4_WITCH_H

#include "Card.h"

class Witch : public BattleCard {

public:
    Witch() : BattleCard(2, 11, 10){}
    void applyDefeat(Player&) override;
    std::string getName() const override{ return "Witch"; }
};
#endif //EX4_WITCH_H
