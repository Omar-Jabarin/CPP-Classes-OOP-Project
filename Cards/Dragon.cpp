//
// Created by omar_ on 25/06/2023.
//

#include "Dragon.h"

#define INFINITY 9001

void Dragon::applyDefeat(Player& player) {
    printLossBattle(player.getName(),getName());
    player.kill();
}

void Dragon::printCard(std::ostream &out) const {
    printCardDetails(out, getName());
    printMonsterDetails(out, getAttackStrength(), getDamage(), getLoot(), true);
    printEndOfCardDetails(out);
}
