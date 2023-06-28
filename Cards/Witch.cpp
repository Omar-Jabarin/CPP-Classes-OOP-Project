//
// Created by omar_ on 25/06/2023.
//

#include "Witch.h"

void Witch::applyDefeat(Player& player) {
    printLossBattle(player.getName(),getName());
    player.damage(WITCH_DAMAGE);
    player.buff(WITCH_DEBUFF);
}
