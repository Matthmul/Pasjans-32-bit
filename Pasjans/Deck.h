#pragma once
#include "Card.h"
#include "TableCard.h"

const static int RANK_SIZE = 13;
const static int SUIT_SIZE = 4;
const static char RANKS[] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };
const static char SUITS[] = { 'k','p','d', 't' };

class Deck : public Card
{
public:
	Deck(void);
	~Deck(void);
	void Populate(void);
	void Shuffle(void);
	//void PrintDeck(void);
	void PopulateVector(TableCard& aDeck);

private:
	Card _deck[52];
	int currentIndex;
};

std::wstring s2ws(const std::string&);
