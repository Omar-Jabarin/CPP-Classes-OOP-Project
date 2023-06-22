#ifndef PROVIDED_PLAYER_H
#define PROVIDED_PLAYER_H

#include <string>

typedef struct {
    std::string name;
    int hp;
    int maxHP;
    int level;
    int force;
    int coins;
} PlayerStats;

class Player {
protected:
    PlayerStats m_stats;

public:
    Player(std::string name, int hp = 100);

    void levelUp();

    int getLevel();

    void buff(int points);

    virtual void heal(int points);

    void damage(int points);

    bool isKnockedOut();

    virtual void addCoins(int coins);

    bool pay(int coins);

    virtual int getAttackStrength();

    void kill();

    std::string getName();
};

class Ninja : public Player {
public:
    Ninja(std::string name, int hp = 100);
    void addCoins(int coins) override;
};

class Healer : public Player {
public:
    Healer(std::string name, int hp = 100);
    void heal(int points) override;
};

class Warrior : public Player {
public:
    Warrior(std::string name, int hp = 100);

    int getAttackStrength() override;
};

std::ostream& operator<<(std::ostream& out, Player& player);

#endif