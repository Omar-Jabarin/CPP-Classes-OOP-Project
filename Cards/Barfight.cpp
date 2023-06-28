//
// Created by omar_ on 25/06/2023.
//

#include "Barfight.h"
#include "../Players/Warrior.h"

#define BARFIGHT_DAMAGE 10

void Barfight::apply(Player& player) {
    if (!dynamic_cast<Warrior*>(&player)) {
        printBarfightMessage(false);
        player.damage(BARFIGHT_DAMAGE);
    }
    else{
        printBarfightMessage(true);
    }
}