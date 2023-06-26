#ifndef PROVIDED_PLAYER_H
#define PROVIDED_PLAYER_H

#define MAX_LEVEL 10

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
    explicit Player(std::string name, int hp = 100);

    void levelUp();

    int getLevel() const;

    void buff(int points);

    virtual void heal(int points);

    void damage(int points);

    bool isKnockedOut() const;

    virtual void addCoins(int coins);

    bool pay(int coins);

    virtual int getAttackStrength() const;

    void kill();

    std::string getName() const;

    virtual std::string getJob() const=0;

    int getCurrentHP() const;

    int getCoins() const;

    int getForce() const;
};

std::ostream& operator<<(std::ostream& out, const Player& player);

#endif