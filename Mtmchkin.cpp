//
// Created by omar_ on 21/06/2023.
//

#include <iostream>
#include <exception>
#include "Mtmchkin.h"
#include "utilities.h"
#include <string>
#include "Leaderboard.h"
#include <fstream>
#include "Players/Player.h"
#include "Cards/Card.h"
#include "Cards/Witch.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Mana.h"
#include "Cards/Gremlin.h"
#include "Cards/Merchant.h"
#include "Cards/Well.h"
#include "Cards/Treasure.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
#include "Players/Warrior.h"
#include "Exception.h"

static bool isValidNumber(const std::string& input){
    if (input.size()==0){
        return false;
    }

    for (char c: input){
        if (c < '0' || c > '9'){
            return false;
        }
    }

    int number=std::stoi(input);
    return ((number >= LOWER_PLAYER_LIMIT) && (number <= UPPER_PLAYER_LIMIT));
}

static int getNumberOfPlayers(){
    std::string input;

    while(true){
        printEnterTeamSizeMessage();
        std::getline(std::cin, input);

        std::string result;
        for (char c : input) { //delete whitespace
            if (c != ' ') {
                result += c;
            }
        }
        input = result;

        if (isValidNumber(input)){
            return std::stoi(input);
        }
        else {
            printInvalidTeamSize();
        }
    }
}

static bool isEnglish(const std::string& word){
    for (char c : word) {
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
            return false;
        }
    }
    return true;
}

static char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c -'A' + 'a';
    }
    return c;
}

static std::string toLower(const std::string& s) {
    std::string lowerCaseString;
    for (char c : s) {
        lowerCaseString += toLower(c);
    }
    return lowerCaseString;
}

static bool isValidClass(const std::string& word){
    std::string lowerCaseInput = toLower(word);
    return (lowerCaseInput == "ninja" || lowerCaseInput == "warrior" || lowerCaseInput == "healer");
}

static std::pair<std::string,std::string> getPlayerDetails(){
    std::string playerName;
    std::string playerClass;
    std::string input;

    printInsertPlayerMessage();
    while (true) {
        std::getline(std::cin, input);
        std::vector <std::string> words;
        std::string word;
        for (char c: input) {
            if (c == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }
        if (words.size() == 2){
                playerName=words[0];
                playerClass=words[1];
                if (!isEnglish(playerName) || playerName.size() > 15 ){
                    printInvalidName();
                    continue;
                }
                if (!isValidClass(playerClass)){
                    printInvalidClass();
                    continue;
                }
                return {playerName, toLower(playerClass)};
        }
        else{
            printInvalidInput();
        }
    }
}

static std::shared_ptr<Player> createPlayer(const std::pair<std::string,std::string> &playerDetails){
    if (playerDetails.second == "ninja"){
        std::shared_ptr<Player> product(new Ninja(playerDetails.first));
        return product;
    }
    else if(playerDetails.second == "warrior"){
        std::shared_ptr<Player> product (new Warrior(playerDetails.first));
        return product;
    }
    else if (playerDetails.second == "healer"){
        std::shared_ptr<Player> product (new Healer(playerDetails.first));
        return product;
    }
    throw std::invalid_argument("Cannot create class: " + playerDetails.second);
}
static std::unique_ptr<Card> createCard(const std::string& cardType) {
    if (cardType == "Mana") {
        return std::unique_ptr<Mana>(new Mana);
    }
    else if (cardType == "Dragon") {
        return std::unique_ptr<Dragon>(new Dragon);
    }
    else if (cardType == "Gremlin") {
        return std::unique_ptr<Gremlin>(new Gremlin);
    }
    else if (cardType == "Witch") {
        return std::unique_ptr<Witch>(new Witch);
    }
    else if (cardType == "Merchant") {
        return std::unique_ptr<Merchant>(new Merchant);
    }
    else if (cardType == "Treasure") {
        return std::unique_ptr<Treasure>(new Treasure);
    }
    else if (cardType == "Well") {
        return std::unique_ptr<Well>(new Well);
    }
    else if (cardType == "Barfight") {
        return std::unique_ptr<Barfight>(new Barfight);
    }
    else {
        throw std::invalid_argument("Unknown card type: " + cardType);
    }
}


static std::vector<std::shared_ptr<Player>> getPlayerList(int numberOfPlayers){

    std::vector<std::shared_ptr<Player>> playerList;
    for (int i=0; i<numberOfPlayers; i++){
        std::pair<std::string,std::string> currentPlayerDetails=getPlayerDetails();
        playerList.push_back(createPlayer(currentPlayerDetails));
    }
    return playerList;

}

static std::vector<std::unique_ptr<Card>> welcomeAndGetDeckFromFile(const std::string &fileName){
    printStartGameMessage();
    std::vector<std::unique_ptr<Card>> deck;
    std::ifstream deckFile(fileName);
    int currentLineNum=1;
    std::string currentLine;

    if (!deckFile){
        throw DeckFileNotFound("Deck File Error: File not found");
    }
    while (std::getline(deckFile, currentLine)){
        try {
            deck.push_back(createCard(currentLine));
            currentLineNum++;
        }
        catch (std::invalid_argument&){
            throw DeckFileFormatError("Deck File Error: File format error in line "
                                        +std::to_string(currentLineNum));
        }
    }
    if (currentLineNum<=MIN_DECK_SIZE){
        throw DeckFileInvalidSize("Deck File Error: Deck size is invalid");
    }
    return deck;
}

Mtmchkin::Mtmchkin(const std::string &fileName)
:m_deck(welcomeAndGetDeckFromFile(fileName)),
m_numberOfPlayers(getNumberOfPlayers()),
m_players(getPlayerList(m_numberOfPlayers)),
m_leaderboard(m_players),
m_numberOfRounds(0)
{}

int Mtmchkin::getNumberOfRounds() const {
    return m_numberOfRounds;
}
void Mtmchkin::moveFirstCardToEnd() {
    std::unique_ptr<Card> firstCard = std::move(m_deck[0]);

    for (size_t i = 1; i < m_deck.size(); ++i) {
        m_deck[i - 1] = std::move(m_deck[i]);
    }

    m_deck.back() = std::move(firstCard);
}
void Mtmchkin::playRound() {

    m_numberOfRounds++;
    printRoundStartMessage(m_numberOfRounds);
    //iterate over all players
    for (std::vector<std::shared_ptr<Player>>::iterator it = m_players.begin(); it != m_players.end(); ++it){
        if (!(((*it)->isKnockedOut()) || ((*it)->getLevel() >= MAX_LEVEL))){ // Check if player is still playing.
            printTurnStartMessage((*it)->getName());
            m_deck.front()->apply(*(*it)); //draws the current playing card and applies it to the current player.
            if ((*it)->isKnockedOut()){
                m_leaderboard.updateLeaderboard(*it, Status::Dead);
            }
            else if ((*it)->getLevel()>=MAX_LEVEL){
                m_leaderboard.updateLeaderboard(*it, Status::Finished);
            }
            moveFirstCardToEnd();
        }
    }
    if (isGameOver()){
        printGameEndMessage();
    }
}

bool Mtmchkin::isGameOver() const {
    for (const std::shared_ptr<Player>& player : m_players){
        if (!(player->isKnockedOut()) && (player->getLevel() < MAX_LEVEL)){
            return false;
        }
    }
    return true;
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    int rank=0;
    for (std::vector<Rank>::const_iterator it=m_leaderboard.getRankings().begin();
                                           it !=m_leaderboard.getRankings().end(); ++it, ++rank){

        printPlayerLeaderBoard((rank+1), *(it->m_player));
    }

}



