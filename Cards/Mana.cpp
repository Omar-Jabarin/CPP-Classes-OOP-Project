//
// Created by omar_ on 25/06/2023.
//

#include "Mana.h"
#include "../Players/Healer.h"
#define MANA_HEAL_POWER 10


void Mana::apply(Player& player) {
    if (dynamic_cast<Healer*>(&player)) {
        printManaMessage(true);
        player.heal(MANA_HEAL_POWER);
    }
    else {
        printManaMessage(false);
    }
}
