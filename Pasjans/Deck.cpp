#include "stdafx.h"
#include "Deck.h"
#include "TableCard.h"

std::wstring s2ws(const std::string& s)
{
int len;
int slength = (int)s.length() + 1;
len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
wchar_t* buf = new wchar_t[len];
MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
std::wstring r(buf);
delete[] buf;
return r;
}

Deck::Deck(void)
	:currentIndex(0)
{
	srand((unsigned)time(0));
	Populate();
}

Deck::~Deck(void)
{
}

void Deck::Populate()
{
	int index = 0;
	sf::Texture texture;
	for (int i = 0; i < SUIT_SIZE; i++)
	{
		for (int j = 0; j < RANK_SIZE; j++)
		{
			std::stringstream ss;
			ss << "deck\\" << SUITS[i] << RANKS[j] << '.' << 'b' << 'm' << 'p';
			std::string str = ss.str();
			texture.loadFromFile(str);
			_deck[index] = Card(RANKS[j], SUITS[i], &texture);
			index++;
		}
	}
}

void Deck::Shuffle()
{
	int max = SUIT_SIZE * RANK_SIZE;
	for (int i = 0; i < max - 1; i++)
	{
		int randNum = rand() % 52;
		std::swap(_deck[i], _deck[randNum]);
	}

}

/*void Deck::PrintDeck(void)
{
	int max = SUIT_SIZE * RANK_SIZE;
	for (int i = 0; i < max; i++)
	{
		if (i % 13 == 0)
			std::cout << '\n' << '\n';
	}
}*/

void Deck::PopulateVector(TableCard& aDeck)
{
	int max = SUIT_SIZE * RANK_SIZE;
	aDeck.Clear();
	for (int i = 0; i < max; i++)
		aDeck.PushValueCopy(_deck[i]);
}