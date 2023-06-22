#include "Card.h"
#include "Player.h"
#include <iostream>

void BattleCard::apply(Player& player) {
    playerWinsFight(player) ? applyVictory(player) : applyDefeat(player);
}

bool BattleCard::playerWinsFight(Player& player) {
    return (player.getAttackStrength() >= this->power);
}

void BattleCard::applyVictory(Player& player) {
    player.addCoins(this->loot);
    player.levelUp();
}

void Gremlin::applyDefeat(Player& player) {
    player.damage(10);
}

void Witch::applyDefeat(Player& player) {
    player.damage(10);
    player.buff(-1);
}

void Dragon::applyDefeat(Player& player) {
    player.kill();
}

void Treasure::apply(Player& player) {
    player.addCoins(10);
}

void Well::apply(Player& player) {
    if (!dynamic_cast<Ninja*>(&player)) {
        player.damage(10);
    }
}

void Barfight::apply(Player& player) {
    if (!dynamic_cast<Warrior*>(&player)) {
        player.damage(8);
    }
}

void Mana::apply(Player& player) {
    if (dynamic_cast<Healer*>(&player)) {
        player.heal(10);
    }
}

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
        } catch (std::invalid_argument) {}
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