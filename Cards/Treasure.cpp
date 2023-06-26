//
// Created by omar_ on 25/06/2023.
//


#include "Treasure.h"
#define TREASURE_LOOT 10

void Treasure::apply(Player& player) {
    printTreasureMessage();
    player.addCoins(TREASURE_LOOT);
}