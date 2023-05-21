#ifndef BLACKJACK_H
#define BLACKJACK_H

const int BLACKJACK = 21;
const int DECK_SIZE = 52;

// Represents a card in the deck
struct Card {
  int value;
  std::string suit;
  std::string name;
  bool dealt;
};

#endif
