//
// Created by omar_ on 25/06/2023.
//

#ifndef EX4_WELL_H
#define EX4_WELL_H

#include "Card.h"
#include "../Players/Ninja.h"

class Well : public Card {
    void apply(Player& player) override;
    std::string getName() const override{ return "Well"; }
};

#endif //EX4_WELL_H
