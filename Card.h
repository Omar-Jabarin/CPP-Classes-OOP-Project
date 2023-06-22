#ifndef PROVIDED_CARD_H
#define PROVIDED_CARD_H

#include "Player.h"

class Card {
public:
    virtual void apply(Player& player) = 0;
};

class BattleCard : public Card {
protected:
    int loot;
    int power;
public:
    void apply(Player& player) override;
    bool playerWinsFight(Player& player);
    void applyVictory(Player&);
    virtual void applyDefeat(Player&);
};

class Gremlin : public BattleCard {
    int loot = 2;
    int power = 5;
public:
    void applyDefeat(Player&) override;
};

class Witch : public BattleCard {
    int loot = 2;
    int power = 11;
public:
    void applyDefeat(Player&) override;
};

class Dragon : public BattleCard {
    int loot = 1000;
    int power = 25;
public:
    void applyDefeat(Player&) override;
};

class Merchant : public Card {
    void apply(Player& player) override;
    int getRequest();
};

class Treasure : public Card {
    void apply(Player& player) override;
};

class Well : public Card {
    void apply(Player& player) override;
};

class Barfight : public Card {
    void apply(Player& player) override;
};

class Mana : public Card {
    void apply(Player& player) override;
};

#endif