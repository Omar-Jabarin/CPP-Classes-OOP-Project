#include "Player.h"
#include <string>
#include <iostream>
#include <cmath>
#include "../utilities.h"

Player::Player(std::string name, int hp) : m_stats({name, hp, hp, 1, 5, 10}) {}


std::string Player::getName() const {
    return m_stats.name;
}

void Player::levelUp() {
    m_stats.level = std::fmin(m_stats.level + 1, MAX_LEVEL);
}

int Player::getLevel() const {
    return m_stats.level;
}

void Player::buff(int points) {
    m_stats.force += points;
    if (m_stats.force < 0){
        m_stats.force = 0;
    }
}

void Player::heal(int points) {
    if (points > 0) {
        m_stats.hp = std::fmin(m_stats.hp + points, m_stats.maxHP);
    }
}

void Player::damage(int points) {
    if (points > 0) {
        m_stats.hp = std::fmax(m_stats.hp - points, 0);
    }
}

bool Player::isKnockedOut() const {
    return (m_stats.hp == 0);
}

void Player::addCoins(int coins) {
    m_stats.coins += coins;
}

bool Player::pay(int coins) {
    if (coins > m_stats.coins) {
        return false;
    }
    m_stats.coins -= coins;
    return true;
}

int Player::getAttackStrength() const {
        return m_stats.level + m_stats.force;
    }

void Player::kill() {
    m_stats.hp = 0;
}

int Player::getCurrentHP() const {
    return m_stats.hp;
}

int Player::getCoins() const {
    return m_stats.coins;
}

int Player::getForce() const {
    return m_stats.force;
}


std::ostream& operator<<(std::ostream& out, const Player& player) {
    printPlayerDetails(out, player.getName(),player.getJob(),player.getLevel()
                       ,player.getForce(),player.getCurrentHP(), player.getCoins());
    return out;
}