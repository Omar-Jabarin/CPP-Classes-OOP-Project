//
// Created by omar_ on 25/06/2023.
//

#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H
#include "Card.h"

class Treasure : public Card {
    void apply(Player& player) override;
    std::string getName() const override{ return "Treasure"; }
};


#endif //EX4_TREASURE_H
