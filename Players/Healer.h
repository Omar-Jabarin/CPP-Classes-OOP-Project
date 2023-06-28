//
// Created by omar_ on 25/06/2023.
//

#ifndef EX4_HEALER_H
#define EX4_HEALER_H
#include "Player.h"

class Healer : public Player {
public:
    explicit Healer(std::string name, int hp = DEFAULT_HP);
    void heal(int points) override;
    std::string getJob() const override { return "Healer"; }
};


#endif //EX4_HEALER_H
