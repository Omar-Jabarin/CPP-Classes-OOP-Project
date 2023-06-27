//
// Created by omar_ on 25/06/2023.
//

#include "Merchant.h"
#define BUFF_TRADE 2
#define POTION_TRADE 1
#define NO_TRADE 0
#define AVAILABLE_DEALS 2
#define POTION_COST 5
#define POTION_STRENGTH 1
#define BUFF_COST 10
#define BUFF_STRENGTH 1


int Merchant::getRequest() {
    std::string buffer;
    while (true) {
        try {
            std::getline(std::cin, buffer);
            int i = std::stoi(buffer);
            if (0 <= i && i <= AVAILABLE_DEALS) {
                return i;
            }
        } catch (const std::exception&) {}
        printInvalidInput();
    }
}

void Merchant::apply(Player& player) {
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(),player.getCoins());
    switch (getRequest()) {
        case NO_TRADE:
            printMerchantSummary(std::cout, player.getName(), NO_TRADE, NO_TRADE);
            return;

        case POTION_TRADE:
            if (player.pay(POTION_COST)) {
                player.heal(POTION_STRENGTH);
                printMerchantSummary(std::cout, player.getName(),POTION_TRADE, POTION_COST);
            } else {
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout,player.getName(),POTION_TRADE,NO_TRADE);
            }
            return;
        case BUFF_TRADE:
            if (player.pay(BUFF_COST)) {
                player.buff(BUFF_STRENGTH);
                printMerchantSummary(std::cout,player.getName(),BUFF_TRADE,BUFF_COST);

            } else {
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout,player.getName(),BUFF_TRADE,NO_TRADE);
            }
            return;
    }
}