#include "Player.h"
#include <string>
#include <iostream>
#include <cmath>

Player::Player(std::string name, int hp) : m_stats({name, hp, hp, 1, 5, 0}) {}

Warrior::Warrior(std::string name, int hp) : Player(name, hp) {};

Ninja::Ninja(std::string name, int hp) : Player(name, hp) {};

Healer::Healer(std::string name, int hp) : Player(name, hp) {};

std::string Player::getName() {
    return m_stats.name;
}

void Player::levelUp() {
    m_stats.level = std::fmin(m_stats.level + 1, 10);
}

int Player::getLevel() {
    return m_stats.level;
}

void Player::buff(int points) {
    m_stats.force += points;
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

bool Player::isKnockedOut() {
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

int Player::getAttackStrength() {
        return m_stats.level + m_stats.force;
    }

void Player::kill() {
    m_stats.hp = 0;
}

void Ninja::addCoins(int coins) {
    Player::addCoins(2*coins);
    // m_stats["coins"] += 2*coins;
}

void Healer::heal(int points) {
    Player::heal(2*points);
}

int Warrior::getAttackStrength() {
    return m_stats.level + 2*m_stats.force;
}

std::ostream& operator<<(std::ostream& out, Player& player) {
    out << player.getName();
    return out;
}