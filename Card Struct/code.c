#include <stdio.h>
#include <string.h>

typedef struct Card_struct {
	int suit;
	int value;
	char suitName[9];
	char valueName[7];
} Card;

Card createCardFunc(int i, int j);
void createDeckFunc(Card deckList[52]);

int main() {
	Card deckList[52];

	createDeckFunc(deckList);
	for (int i = 0; i < 52; i++) {
		//printf("%d %d\n", deckList[i].suit, deckList[i].value);
		printf("%s of %s, ", deckList[i].valueName, deckList[i].suitName);
	}
	return 0;
}

Card createCardFunc(int i, int j) {
	Card card;
	card.suit = i;
	card.value = j;
	char valueChar[3];
	switch (card.suit) {
	case 0:
		strcpy(card.suitName, "Hearts");
		break;
	case 1:
		strcpy(card.suitName, "Clubs");
		break;
	case 2:
		strcpy(card.suitName, "Diamonds");
		break;
	case 3:
		strcpy(card.suitName, "Spades");
		break;
	}

	if (card.value == 1 || card.value > 10) {
		switch (card.value) {
		case 1:
			strcpy(card.valueName, "Ace\0");
			break;
		case 11:
			strcpy(card.valueName, "Jack\0");
			break;
		case 12:
			strcpy(card.valueName, "Queen\0");
			break;
		case 13:
			strcpy(card.valueName, "King\0");
			break;
		}
	}
	else {
		sprintf(valueChar, "%d", card.value);
		strcpy(card.valueName, valueChar);
	}
	return card;
}

void createDeckFunc(Card deckList[52]) {
	int cardIter = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 14; j++) {
			deckList[cardIter] = createCardFunc(i, j);
			cardIter++;
		}
	}
}