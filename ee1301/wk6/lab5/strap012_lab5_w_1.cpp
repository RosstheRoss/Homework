#include <iostream>
#include <string>

class DeckOfCards {
private:
  int deck[53];
  int index;
public:
  DeckOfCards() {
    for(int i=0; i<52; i++) {
      deck[i]=i+1;
    }
    int index=0;
  }
  int dealCard() {
    index++;
    if (index>=52) {
      index=0;
      shuffle();
    }
    return deck[index];
  }
  void shuffle() {
    int j=0;
    int temp=0;
    for (int i=51; i>1; i--) {
      j = rand() % 51 + 1;
      if (0 < j && j < i) {
        temp=deck[i]; deck[i]=deck[j]; deck[j]=temp;
      }
    }
  }
};

void showHand(int hand[], const int size);
char findCard(int card);
int main() {
  const int size=4;
  srand(time(NULL));
  DeckOfCards deck;
  int hand[size];
  deck.shuffle();
  for (int i=0; i<13; i++) {
    for (int j=0; j<size; j++) {
      hand[j]=deck.dealCard();
    }
    showHand(hand, size);
  }
}

void showHand(int hand[], const int size) {

  for (int i=0; i<size; i++) {
    char newHand[size];
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
