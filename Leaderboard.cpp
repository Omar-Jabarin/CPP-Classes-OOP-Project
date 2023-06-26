//
// Created by omar_ on 23/06/2023.
//

#include "Leaderboard.h"

Leaderboard::Leaderboard(const std::vector <std::shared_ptr<Player>>& playerList) {
    for (std::vector<std::shared_ptr<Player>>::const_iterator it = playerList.begin(); it != playerList.end(); ++it) {
        Rank rank;
        rank.m_player = *it;
        rank.m_status = Status::Playing;
        m_rankings.push_back(rank);
    }
    m_nextWinnerPosition=m_rankings.begin();
    m_nextLoserPosition=m_rankings.end();
}

void Leaderboard::updateLeaderboard(std::shared_ptr<Player> player, Status playerStatus) {
    std::vector<Rank>::iterator playerPosition;

    for (std::vector<Rank>::iterator it=m_rankings.begin(); it!=m_rankings.end(); ++it){
        if (it->m_player == player){
            playerPosition=it;
            break;
        }
    }
    if (playerStatus == Status::Finished){
        playerPosition->m_status=Status::Finished;
        if (playerPosition != m_nextWinnerPosition) {
            Rank temp = *playerPosition;
            for (std::vector<Rank>::iterator it = playerPosition; it != m_nextWinnerPosition; --it) {
                *it = *(it - 1);
            }
            *m_nextWinnerPosition = temp;
        }
        ++m_nextWinnerPosition;
    }
    if (playerStatus == Status::Dead){
        playerPosition->m_status=Status::Dead;
        if (playerPosition + 1 != m_nextLoserPosition){
            Rank temp=*playerPosition;
            for (std::vector<Rank>::iterator it = playerPosition; it + 1 != m_nextLoserPosition; ++it){
                *it = *(it + 1);
            }
            *(m_nextLoserPosition-1)=temp;
        }
        --m_nextLoserPosition;
    }
}

