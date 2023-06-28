//
// Created by omar_ on 25/06/2023.
//

#include "Well.h"
#define WELL_DAMAGE 10

void Well::apply(Player& player) {
    if (!dynamic_cast<Ninja*>(&player)) {
        printWellMessage(false);
        player.damage(WELL_DAMAGE);
    }
    else{
        printWellMessage(true);
    }
}
