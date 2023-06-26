//
// Created by omar_ on 25/06/2023.
//

#include "Well.h"

void Well::apply(Player& player) {
    if (!dynamic_cast<Ninja*>(&player)) {
        player.damage(10);
    }
}
