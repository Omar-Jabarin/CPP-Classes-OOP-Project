//
// Created by omar_ on 25/06/2023.
//

#ifndef EX4_MANA_H
#define EX4_MANA_H

#include "Card.h"




class Mana : public Card {
    void apply(Player& player) override;
    std::string getName() const override{ return "Mana"; }
};



#endif //EX4_MANA_H
