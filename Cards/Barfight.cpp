//
// Created by omar_ on 25/06/2023.
//

#include "Barfight.h"
#include "../Players/Warrior.h"

void Barfight::apply(Player& player) {
    if (!dynamic_cast<Warrior*>(&player)) {
        player.damage(8);
    }
}