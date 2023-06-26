#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <vector>
#include <memory>
#include <iostream>
#include "Leaderboard.h"
#include "Cards/Card.h"

#define LOWER_PLAYER_LIMIT 2
#define UPPER_PLAYER_LIMIT 6
#define MIN_DECK_SIZE 5



class Mtmchkin{
public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);
    Mtmchkin& operator=(const Mtmchkin& other)=delete;
    Mtmchkin(const Mtmchkin&)=delete;
    ~Mtmchkin()=default;

    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    std::vector<std::unique_ptr<Card>> m_deck;
    int m_numberOfPlayers;
    std::vector<std::shared_ptr<Player>> m_players;
    Leaderboard m_leaderboard;
    int m_numberOfRounds;

    void moveFirstCardToEnd();
};




#endif /* MTMCHKIN_H_ */
