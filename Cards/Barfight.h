//
// Created by omar_ on 25/06/2023.
//

#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H
#include "Card.h"

class Barfight : public Card {
    void apply(Player& player) override;
    std::string getName() const override{ return "Barfight"; }
};


#endif //EX4_BARFIGHT_H
