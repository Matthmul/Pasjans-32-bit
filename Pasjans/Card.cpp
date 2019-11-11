#include "Card.h"

Card::Card(void)
{
	isFaceUp == false;
}

Card::Card(char r, char s, sf::Texture *t)
	: rank(r)
	, suit(s)
	, isFaceUp(false)
	, child(NULL)
	, parent(NULL)
	, t(*t)
{
	SetTexture(this->t);
}

Card::~Card(void)
{
}

void Card::Flip()
{
	isFaceUp = !isFaceUp;
}
bool Card::GetIsFaceUp()
{
	return isFaceUp;
}
char Card::GetCardSuit()
{
	return suit;
}
char Card::GetCardRank()
{
	return rank;
}

sf::Sprite * Card::GetCardSprite()
{
	return &s;
}

void Card::SetTexture(sf::Texture & t)
{
	t.setSmooth(true);
	sf::Vector2f targetSize(CARD_WIDTH, CARD_HEIGHT);

	s.setTexture(t);

	s.setScale(
		targetSize.x / s.getLocalBounds().width,
		targetSize.y / s.getLocalBounds().height);
}

void Card::SetPositionFirst(sf::Vector2f coord)
{
	this->p.coord.first = coord;
}

void Card::SetPositionSecond(sf::Vector2f coord)
{
	this->p.coord.second = coord;
}

Position Card::GetPosition()
{
	return p;
}

sf::Texture * Card::GetTexture()
{
	return &t;
}

int Card::GetSolitaireValue()
{
	if (rank == 'A')
		return 1;
	else if (rank == 'T')
		return 10;
	else if (rank == 'J')
		return 11;
	else if (rank == 'Q')
		return 12;
	else if (rank == 'K')
		return 13;
	else
	{
		char c[] = { rank, '\0' };
		return atoi(c);
	}
}
