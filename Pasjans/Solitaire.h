#pragma once
#include "Deck.h"
#include "Card.h"
#include "TableCard.h"

const static int TABLE_SIZE = 7;

class Solitaire
{
public:
	Solitaire(void);
	~Solitaire(void);
	void PopulateTable(void);
	void Deal(int numToDeal = 1);

	int LocateCard(sf::Vector2f coord, int &group, int &column, int &row);

	/* Functions for validating and moving cards  */
	void MakeSuitMove(int from);
	void MakeMoveBetweenRows(int from, int to);
	void MakeMoveDeckToRow(int to);
	void MakeMoveRowToRow(int from, int to);
	bool ValidMove(int from, int to);
	bool ValidRowToRowMove(Card* fromCard, int to);
	bool ValidSuitMove(int from);

	/* Checks to see if all answer sections full */
	bool GameCompleted();

	/* Functions for printing card details */
	void PrintAllDetails(sf::RenderWindow &window);
	void PrintSuitDetails(sf::RenderWindow &window);
	void PrintDeckDetails(sf::RenderWindow &window);

	/* Functions for stering game */
	void ResetGame();
	void MousePressed(sf::Vector2f coord);
	void MouseReleased(sf::Vector2f coord, int column, int row);
	void MouseMoved(sf::Vector2f coord, int column, int row);
	void MouseLeft();

	int _column, _row;

private:

	TableCard _deck;
	TableCard _discardedCards;
	std::vector<TableCard> _tableCards;

	//Destination of cards. When all filled player wins
	std::vector<TableCard> _suitCards;

	sf::Sprite FiledDeck;
	sf::Sprite PikSuit;
	sf::Sprite KierSuit;
	sf::Sprite KaroSuit;
	sf::Sprite TreflSuit;

};