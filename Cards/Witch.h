//
// Created by omar_ on 25/06/2023.
//

#ifndef EX4_WITCH_H
#define EX4_WITCH_H

#include "Card.h"

#define WITCH_LOOT 2
#define WITCH_POWER 11
#define WITCH_DAMAGE 10
#define WITCH_DEBUFF -1

class Witch : public BattleCard {

public:
    Witch() : BattleCard(WITCH_LOOT, WITCH_POWER, WITCH_DAMAGE){}
    void applyDefeat(Player&) override;
    std::string getName() const override{ return "Witch"; }
};
#endif //EX4_WITCH_H
