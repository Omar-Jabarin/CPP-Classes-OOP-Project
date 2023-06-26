#ifndef PROVIDED_CARD_H
#define PROVIDED_CARD_H

#include "../Players/Player.h"
#include <iostream>
#include "../utilities.h"

class Card {
public:
    virtual void apply(Player& player) = 0;
    virtual ~Card() = default;
    virtual std::string getName() const = 0;
    virtual void printCard(std::ostream& out) const;
};

class BattleCard : public Card {
protected:
    int m_loot;
    int m_power;
    int m_damage;
    BattleCard(int loot, int power, int damage);
public:
    void apply(Player& player) override;
    bool playerWinsFight(Player& player);
    virtual void applyVictory(Player&);
    virtual void applyDefeat(Player&)=0;
    void printCard(std::ostream& out) const override;
    virtual int getAttackStrength() const;
    virtual int getLoot() const;
    virtual int getDamage() const;
};

std::ostream& operator<<(std::ostream& out, const Card& card);

#endif