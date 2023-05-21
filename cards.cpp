#include <iostream>
#include "cards.h"

void printCards(Card cards[], int numCards)
{
  for (int i = 0; i < numCards; i++)
  {
    std::cout << cards[i].name << " of " << cards[i].suit << " ";
  }
}
