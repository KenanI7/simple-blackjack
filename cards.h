#ifndef CARDS_H
#define CARDS_H

#include <string>

struct Card
{
    int value;
    std::string suit;
    std::string name;
    bool dealt;
};

void printCards(Card cards[], int numCards);

#endif // CARDS_H
