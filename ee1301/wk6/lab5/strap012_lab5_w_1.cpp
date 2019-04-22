#include <iostream>
//#include <time.h>     //Needed if using MinGW

class DeckOfCards {
private:
  int index=0, deck[52];
public:
  DeckOfCards();
  void shuffle();
  int dealCard();
};

void showHand(int hand[], const int size);
int main() {
  srand(time(NULL));
  const int size=4;   //Size can be changed for larger hands
  DeckOfCards deck;
  int hand[size];
  for (int i=0; i<13; i++) {
    for (int j=0; j<size; j++) {
      hand[j]=deck.dealCard();
    }
    showHand(hand, size);
  }
}

//Prints out hand shuffled from before
void showHand(int hand[], const int size) {
  for (int i=0; i<size; i++) {
  //Switch case needed for showing face cards and aces
    switch(hand[i]%13) {
      case 0: std::cout << 'A';
        break;
      case 10: std::cout << 'J';
        break;
      case 11: std::cout << 'Q';
        break;
      case 12: std::cout << 'K';
        break;
      default: std::cout << hand[i]%13+1;
    }
    std::cout << " ";
  }
  std::cout << std::endl;
}

//Deck initialized with 1-52 and shuffled
DeckOfCards::DeckOfCards() {
  for(int i=0; i<51; i++) {
    deck[i]=i+1;
  }
  shuffle();
}

//Implementation of Knuth Shuffle
void DeckOfCards::shuffle() {
  int j=0, temp=0;
  for (int i=50; i>1; i--) {
    j = rand() % 50 + 1;
    if (j < i) {
      temp=deck[i]; deck[i]=deck[j]; deck[j]=temp;
    }
  }
}

//Function to deal the card when asked by grabbing from the deck and shuffling if such card does not exist.
//Returns the card drawn from the deck
int DeckOfCards::dealCard() {
  index++;
  if (index>=52) {
    index=0;
    shuffle();
  }
  return deck[index];
}