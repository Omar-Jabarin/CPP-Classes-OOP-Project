//
// Created by omar_ on 25/06/2023.
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"

class Merchant : public Card {
    void apply(Player& player) override;
    int getRequest();
    std::string getName() const override{ return "Merchant"; }
};



#endif //EX4_MERCHANT_H
