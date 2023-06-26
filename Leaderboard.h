//
// Created by omar_ on 23/06/2023.
//

#ifndef EX4_LEADERBOARD_H
#define EX4_LEADERBOARD_H
#include <vector>
#include <memory>
#include "Players/Player.h"
#include <exception>
#include <stdexcept>

enum class Status {Playing, Finished, Dead};

struct Rank{
    std::shared_ptr<Player> m_player;
    Status m_status;
};

class Leaderboard{
private:
    std::vector<Rank> m_rankings;
    std::vector<Rank>::iterator m_nextWinnerPosition;
    std::vector<Rank>::iterator m_nextLoserPosition;


public:
    Leaderboard(const std::vector<std::shared_ptr<Player>>& playerList);
    Leaderboard(const Leaderboard&)=delete;
    Leaderboard& operator=(const Leaderboard& other)=delete;
    ~Leaderboard()=default;
    void updateLeaderboard(std::shared_ptr<Player> player, Status playerStatus);
    const std::vector<Rank>& getRankings() const {
        return m_rankings;
    }

    };

#endif //EX4_LEADERBOARD_H
