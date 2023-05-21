#include <string>
#include "score.h"

int calculateScore(Card cards[], int numCards) {
  int score = 0;
  int numAces = 0;
  for (int i = 0; i < numCards; i++) {
    if (cards[i].value == 1) {
      // Ace
      numAces++;
      score += 11;
    } else if (cards[i].value > 10) {
      // Face card
      score += 10;
    } else {
      // Number card
      score += cards[i].value;
    }
  }

  // Handle the case where the hand has multiple aces and the score exceeds 21
  while (score > BLACKJACK && numAces > 0) {
    score -= 10;
    numAces--;
  }

  return score;
}
