#include "Card.h"


BattleCard::BattleCard(int loot, int power, int damage)
        : m_loot(loot), m_power(power), m_damage(damage) {}

void BattleCard::apply(Player& player) {
    playerWinsFight(player) ? applyVictory(player) : applyDefeat(player);
}

bool BattleCard::playerWinsFight(Player& player) const {
    return (player.getAttackStrength() >= this->m_power);
}

void BattleCard::applyVictory(Player& player) {
    printWinBattle(player.getName(), getName());
    player.addCoins(this->m_loot);
    player.levelUp();
}

int BattleCard::getAttackStrength() const {
    return m_power;
}
int BattleCard::getLoot() const {
    return m_loot;
}

int BattleCard::getDamage() const {
    return m_damage;
}

void BattleCard::printCard(std::ostream &out) const {
    printCardDetails(out, getName());
    printMonsterDetails(out, getAttackStrength(), getDamage(), getLoot(), false);
    printEndOfCardDetails(out);
}



void Card::printCard(std::ostream &out) const {
    printCardDetails(out, getName());
    printEndOfCardDetails(out);
}

std::ostream& operator<<(std::ostream& out, const Card& card){
    card.printCard(out);
    return out;
}
