#pragma once
#include "stdafx.h"
#include "Position.h"

class Card
{
public:
	Card(void);
	Card(char r, char s, sf::Texture *t);
	~Card(void);
	void Flip();
	bool GetIsFaceUp();
	int GetSolitaireValue();
	char GetCardSuit();
	char GetCardRank();

	sf::Sprite *GetCardSprite();

	void SetTexture(sf::Texture &t);
	void SetPositionFirst(sf::Vector2f coord);

	void SetPositionSecond(sf::Vector2f coord);

	Position GetPosition();

	sf::Texture * GetTexture();


	/*
	   Nawigowanie kartami góra dó³
	 */

	Card* parent;
	Card* child;

private:
	char rank;
	char suit;
	bool isFaceUp;
	sf::Sprite s;
	Position p;
	sf::Texture t;
};
