//
// Created by omar_ on 25/06/2023.
//

#include "Mana.h"
#include "../Players/Healer.h"


void Mana::apply(Player& player) {
    if (dynamic_cast<Healer*>(&player)) {
        printManaMessage(true);
        player.heal(10);
    }
    else {
        printManaMessage(false);
    }
}
