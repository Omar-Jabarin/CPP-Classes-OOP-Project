//
// Created by omar_ on 25/06/2023.
//

#include "Merchant.h"

int Merchant::getRequest() {
    std::cout << "Enter input: ";
    std::string buffer;
    while (true) {
        try {
            std::getline(std::cin, buffer);
            int i = std::stoi(buffer);
            if (0 <= i && i <= 2) {
                return i;
            }
        } catch (const std::invalid_argument&) {}
        std::cout << "Invalid output - enter again: ";
    }
}

void Merchant::apply(Player& player) {
    switch (getRequest()) {
        case 0:
            std::cout << "Didn't buy anything." << std::endl;
            return;
        case 1:
            if (player.pay(5)) {
                player.heal(1);
                std::cout << "Bought 1hp for 5 coins" << std::endl;
            } else {
                std::cout << "Not enough coins!" << std::endl;
            }
            return;
        case 2:
            if (player.pay(10)) {
                player.buff(1);
                std::cout << "Bought 1 force buff for 10 coins" << std::endl;
            } else {
                std::cout << "Not enough coins!" << std::endl;
            }
            return;
    }
}