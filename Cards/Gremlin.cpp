//
// Created by omar_ on 25/06/2023.
//

#include "Gremlin.h"

void Gremlin::applyDefeat(Player& player) {
    printLossBattle(player.getName(),getName());
    player.damage(10);
}
