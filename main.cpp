#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include "blackjack.h"
#include "score.cpp"
#include "cards.cpp"


int main() {
  srand(time(NULL));

  int money = 1000; // Initial amount of money

  bool playAgain = true;
  do {
    std::cout << "You have $" << money << ". Enter bet: ";
    int bet;
    std::cin >> bet;

    if (bet > money) {
      std::cout << "You don't have enough money to place that bet. Restart the game(re-run) to gain aditional funds or stop playing because its ruining your life." << std::endl;
      continue;
    }

    Card deck[DECK_SIZE];
    generateDeck(deck);
    shuffleDeck(deck);

    Card playerCards[10];
    int playerNumCards = 0;
    Card computerCards[10];
    int computerNumCards = 0;

    // Deal the first two cards to the player and the computer
    playerCards[playerNumCards++] = drawCard(deck);
    computerCards[computerNumCards++] = drawCard(deck);
    playerCards[playerNumCards++] = drawCard(deck);
    computerCards[computerNumCards++] = drawCard(deck);

    std::cout << "Your cards: ";
    printCards(playerCards, playerNumCards);
    std::cout << " (" << calculateScore(playerCards, playerNumCards) << ")" << std::endl;

    std::cout << "Dealer's cards: ";
    printCards(computerCards, computerNumCards);
    std::cout << " (" << calculateScore(computerCards, computerNumCards) << ")" << std::endl;
    // Player's turn
    while (true) {
      std::cout << "Hit or stand (h/s)? ";
      char choice;
      std::cin >> choice;

      if (choice == 's') {
        break;
      } else if (choice == 'h') {
        playerCards[playerNumCards++] = drawCard(deck);
        std::cout << "Your cards: ";
        printCards(playerCards, playerNumCards);
        std::cout << " (" << calculateScore(playerCards, playerNumCards) << ")" << std::endl;

        if (calculateScore(playerCards, playerNumCards) > BLACKJACK) {
          std::cout << "You busted. You lose." << std::endl;
          money -= bet;
          break;
        }
      }
    }


     // Computer's turn
  while (calculateScore(computerCards, computerNumCards) < 17) {
    computerCards[computerNumCards++] = drawCard(deck);
    std::cout << "Dealer's cards: ";
    printCards(computerCards, computerNumCards);
    std::cout << " (" << calculateScore(computerCards, computerNumCards) << ")" << std::endl;
  }

  int playerScore = calculateScore(playerCards, playerNumCards);
  int computerScore = calculateScore(computerCards, computerNumCards);
  if (playerScore > BLACKJACK) {
    std::cout << "You busted. You lose." << std::endl;
    money -= bet;
  } else if (computerScore > BLACKJACK) {
    std::cout << "Dealer busted. You win!" << std::endl;
    money += bet;
  } else if (playerScore > computerScore) {
    std::cout << "You have a higher score. You win!" << std::endl;
    money += bet;
  } else if (computerScore > playerScore) {
    std::cout << "Dealer has a higher score. You lose." << std::endl;
    money -= bet;

    } else if (computerScore == playerScore) {
    std::cout << "It's a tie." << std::endl;
  }
  else {
    std::cout << "Error." << std::endl;
  }

  if (money == 0) {
    std::cout << "You're out of money! Game over." << std::endl;
    playAgain = false;
  } else {
    std::cout << "Do you want to play again? (y/n) ";
    char choice;
    std::cin >> choice;
    if (choice != 'y') {
      playAgain = false;
    }
  }
} while (playAgain);

return 0;
}
