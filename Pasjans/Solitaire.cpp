#include "stdafx.h"
#include "Solitaire.h"
#include "Deck.h"
#include "Card.h"
#include "TableCard.h"
#include "Pasjans.h"

bool isMousePressed = false;


Solitaire::Solitaire(void)
	:_deck(52)
	, _discardedCards(52)
{
	//Uses the deck class to populate solitaire deck
	//Shuffle the deck to randomize 

	Deck deck = Deck();
	deck.Shuffle();
	deck.PopulateVector(_deck);

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		TableCard tableCard = TableCard(20);
		_tableCards.push_back(tableCard);
	}

	for (int i = 0; i < 4; i++)
	{
		TableCard suitCard = TableCard(13);
		_suitCards.push_back(suitCard);
	}
	PopulateTable();
}

Solitaire::~Solitaire(void)
{
}

void Solitaire::PopulateTable(void)
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		for (int j = 0; j < TABLE_SIZE - i; j++)
		{
			if (j == 0)
				_deck.top().Flip();
			_tableCards[j].Push(_deck.top());
			_deck.Pop();
		}
	}
}

void Solitaire::Deal(int numToDeal)
{
	int size = _deck.Size();
	for (int i = 0; i < size; i++)
	{
		if (_deck.top().GetIsFaceUp())
		{
			_deck.top().Flip();
			_discardedCards.Push(_deck.top());
			_deck.Pop();
		}
	}
	if (_deck.empty())
	{
		for (int i = _discardedCards.Size() - 1; i >= 0; i--)
			_deck.Push(_discardedCards[i]);

		_discardedCards.Clear();
	}
	int index = 0;
	for (int i = 0; i < numToDeal; i++)
	{
		index = _deck.Size() - i - 1;
		if (index >= 0)
		{
			_deck[index].Flip();
		}
		else
			break;
	}
}

void Solitaire::PrintSuitDetails(sf::RenderWindow &window)
{
	int x = WINDOW_WIDTH-200, y = 20;

	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f targetSize(CARD_WIDTH, CARD_HEIGHT);

	for (int j = 0; j < _suitCards.size(); j++, y+=CARD_HEIGHT+20)
	{

		switch (j)
		{
		case 0:

			texture.loadFromFile("deck\\kP.bmp");
			texture.setSmooth(true);
			KierSuit.setTexture(texture);

			KierSuit.setPosition(sf::Vector2f(x, y));

			KierSuit.setScale(
				targetSize.x / KierSuit.getLocalBounds().width,
				targetSize.y / KierSuit.getLocalBounds().height);

			window.draw(KierSuit);
			break;
		case 1:

			texture.loadFromFile("deck\\dP.bmp");
			texture.setSmooth(true);
			KaroSuit.setTexture(texture);
			KaroSuit.setPosition(sf::Vector2f(x, y));

			KaroSuit.setScale(
				targetSize.x / KaroSuit.getLocalBounds().width,
				targetSize.y / KaroSuit.getLocalBounds().height);

			window.draw(KaroSuit);
			break;
		case 2:

			texture.loadFromFile("deck\\tP.bmp");
			texture.setSmooth(true);
			TreflSuit.setTexture(texture);

			TreflSuit.setPosition(sf::Vector2f(x, y));

			TreflSuit.setScale(
				targetSize.x / TreflSuit.getLocalBounds().width,
				targetSize.y / TreflSuit.getLocalBounds().height);

			window.draw(TreflSuit);
			break;
		case 3:

			texture.loadFromFile("deck\\pP.bmp");
			texture.setSmooth(true);
			PikSuit.setTexture(texture);

			PikSuit.setPosition(sf::Vector2f(x, y));

			PikSuit.setScale(
				targetSize.x / PikSuit.getLocalBounds().width,
				targetSize.y / PikSuit.getLocalBounds().height);

			window.draw(PikSuit); 
			break;
		}

		for (int i = 0; i < _suitCards[j].Size(); i++)
		{
			if (&_suitCards[j][i] != NULL) {

				_suitCards[j][i].SetPositionFirst(sf::Vector2f(x, y));

				_suitCards[j][i].GetCardSprite()->setPosition(sf::Vector2f(x, y));

				_suitCards[j][i].SetTexture(*(_suitCards[j][i].GetTexture()));

				window.draw(*(_suitCards[j][i].GetCardSprite()));

			}
			else
				break;
		}
	}
}

void Solitaire::PrintDeckDetails(sf::RenderWindow &window)
{
	int x = 20, y = 20;

	sf::Texture texture;

	texture.loadFromFile("deck\\rewers_as.bmp");
	texture.setSmooth(true);
	FiledDeck.setTexture(texture);

	FiledDeck.setPosition(sf::Vector2f(x, y));
	sf::Vector2f targetSize(CARD_WIDTH, CARD_HEIGHT);

	FiledDeck.setScale(
		targetSize.x / FiledDeck.getLocalBounds().width,
		targetSize.y / FiledDeck.getLocalBounds().height);

	window.draw(FiledDeck);

	//dodac napis deck

	y += CARD_WIDTH + 80;
	for (unsigned int i = 0; i < _deck.Size(); i++)
	{
		if (_deck[i].GetIsFaceUp()) {

			_deck[i].SetPositionFirst(sf::Vector2f(x, y));

			_deck[i].GetCardSprite()->setPosition(sf::Vector2f(x, y));

			_deck[i].SetTexture(*(_deck[i].GetTexture()));

			window.draw(*(_deck[i].GetCardSprite()));

		}
	}
}

void Solitaire::PrintAllDetails(sf::RenderWindow &window)
{
	PrintDeckDetails(window);
	PrintSuitDetails(window);

	int colMax = _tableCards.size();
	int rowMax = 0;
	int x = 250, y = 40;

	for (int i = 0; i < colMax; i++)
	{
		if (_tableCards[i].Size() > rowMax)
		{
			rowMax = _tableCards[i].Size();
		}
	}

	for (int i = 0; i < rowMax; i++)
	{
		for (int j = colMax - 1; j >= 0; j--)
		{
			if (i >= _tableCards[j].Size())
			{
				if (y != 40) {
					y = 40;
					x += 175;
				}
				continue;
			}
			if (_tableCards[j][i].GetIsFaceUp()) {

				_tableCards[j][i].SetPositionFirst(sf::Vector2f(x, y)); //TODO tutaj zmienic
				//_tableCards[j][i].GetCardSprite()->setOrigin(sf::Vector2f(CARD_WIDTH/4, CARD_HEIGHT/4));

				//_tableCards[j][i].GetCardSprite()->setPosition(sf::Vector2f(x, y));

				_tableCards[j][i].GetCardSprite()->setOrigin(sf::Vector2f(CARD_WIDTH / 2, CARD_HEIGHT / 2));
				_tableCards[j][i].GetCardSprite()->setPosition(_tableCards[j][i].GetPosition().coord.first.x + (CARD_WIDTH /4), _tableCards[j][i].GetPosition().coord.first.y + (CARD_HEIGHT / 4));
				//_tableCards[j][i].GetCardSprite()->setPosition(sf::Vector2f(50, 50));
				//_tableCards[j][i].GetCardSprite()->setOrigin(sf::Vector2f(0, 0));

				_tableCards[j][i].SetTexture(*(_tableCards[j][i].GetTexture()));
				
				window.draw(*(_tableCards[j][i].GetCardSprite()));

				y += 40;
			}
			else {

				sf::Sprite sprite;
				sf::Texture texture;

				texture.loadFromFile("deck\\rewers_as.bmp");
				texture.setSmooth(true);
				sprite.setTexture(texture);

				sprite.setOrigin(sf::Vector2f(CARD_WIDTH / 2, CARD_HEIGHT / 2));
				sprite.setPosition(x + (CARD_WIDTH / 4), y + (CARD_HEIGHT / 4));


				sf::Vector2f targetSize(CARD_WIDTH, CARD_HEIGHT);

				sprite.setScale(
					targetSize.x / sprite.getLocalBounds().width,
					targetSize.y / sprite.getLocalBounds().height);

				window.draw(sprite);

				y += 40;
			}
		}
	}
}

int Solitaire::LocateCard(sf::Vector2f coord, int & group, int & column, int & row)
{
	//Dodac obsluge odslonietego decka

	int colMax = _tableCards.size();
	int rowMax = 0;
	group = column = row = -1;

	if (FiledDeck.getGlobalBounds().contains(coord)) {
		return DECK;
	}
	else if (PikSuit.getGlobalBounds().contains(coord)) {

	}
	else if (KierSuit.getGlobalBounds().contains(coord)) {

	}
	else if (KaroSuit.getGlobalBounds().contains(coord)) {

	}
	else if (TreflSuit.getGlobalBounds().contains(coord)) {

	}
	else
	{
		for (unsigned int i = 0; i < _deck.Size(); i++)
		{
			Card c = _deck[i];
			if (c.GetCardSprite()->getGlobalBounds().contains(coord)) {
				row = i;
				return i+100; //return number card
			}
		}
		for (int i = 0; i < colMax; i++)
		{
			if (_tableCards[i].Size() > rowMax)
			{
				rowMax = _tableCards[i].Size();
			}
		}
		for (int i = 0; i < rowMax; i++)
		{
			for (int j = colMax - 1; j >= 0; j--)
			{
				if (i >= _tableCards[j].Size())
				{
					continue;
				}
				Card c = _tableCards[j][i];
				if (c.GetCardSprite()->getGlobalBounds().contains(coord)) {
					row = i;
					column = j;
					return i; //return the row
				}
			}
		}
	}

	return -1;
}

void Solitaire::ResetGame()
{
}

void Solitaire::MousePressed(sf::Vector2f coord)
{
	int group, column, row;
	int status = LocateCard(coord, group, column, row);
	if (status == DECK) {
		Deal(1);
		return;
	}
	if (status != -1) {
		if (status >= 100) {
			_row = status;
			isMousePressed = true;
		}
		else {
			if (_tableCards[column][row].GetIsFaceUp()) {
				_column = column;
				_row = row;

				//_tableCards[column][row].GetCardSprite()->setOrigin(coord.x - (_tableCards[column][row].GetCardSprite()->getPosition().x - _tableCards[column][row].GetCardSprite()->getOrigin().x),
					//coord.y - (_tableCards[column][row].GetCardSprite()->getPosition().y - _tableCards[column][row].GetCardSprite()->getOrigin().y));

				isMousePressed = true;
			}
			else if (!_tableCards[column][row].GetIsFaceUp() && _tableCards[column][row].parent == NULL)
			{
				_tableCards[column][row].Flip();
			}
		}
		
	}

}

void Solitaire::MouseReleased(sf::Vector2f coord, int column, int row)
{
	if (row < 100) //_tableCards[column][row].GetCardSprite()->setPosition(coord);//.x + _tableCards[column][row].GetCardSprite()->getPosition().x, -coord.y + _tableCards[column][row].GetCardSprite()->getPosition().y);
	if (row >= 100) {
		row %= 100;
		//_deck[row].GetCardSprite()->setPosition(coord);//+ _deck[row].GetCardSprite()->getPosition().x, -coord.y + _deck[row].GetCardSprite()->getPosition().y);
	}
	isMousePressed = false;
}

void Solitaire::MouseMoved(sf::Vector2f coord, int column,int row)
{
	if (isMousePressed) {
			if (row < 100) {
			_tableCards[column][row].GetCardSprite()->setOrigin(coord.x - (_tableCards[column][row].GetCardSprite()->getPosition().x - _tableCards[column][row].GetCardSprite()->getOrigin().x),
				coord.y - (_tableCards[column][row].GetCardSprite()->getPosition().y - _tableCards[column][row].GetCardSprite()->getOrigin().y));

			//_tableCards[column][row].GetCardSprite()->setPosition(coord.x + _tableCards[column][row].GetCardSprite()->getPosition().x, 
				//-coord.y + _tableCards[column][row].GetCardSprite()->getPosition().y);

			//_tableCards[column][row].GetCardSprite()->setOrigin(coord.x + _tableCards[column][row].GetPosition().coord.first.x, coord.y + _tableCards[column][row].GetPosition().coord.first.x);
			
			//_tableCards[column][row].GetCardSprite()->setPosition(coord);			
			}
		if (row >= 100) {
			row %= 100;
			_deck[row].GetCardSprite()->setOrigin(coord.x + _deck[row].GetCardSprite()->getPosition().x, 
				coord.y + _deck[row].GetCardSprite()->getPosition().y);
		}
	}
}

void Solitaire::MouseLeft()
{
}

bool Solitaire::ValidMove(int from, int to)
{
	//start move and end move the same

	if (from == to && from != 7)
		return false;

	Card* toCard = NULL;
	Card* fromCard;

	if (from == 7)
	{
		if (!_deck.empty())
		{
			if (!_deck.top().GetIsFaceUp())
			{
				return false;
			}
			else
			{
				fromCard = &_deck.top();
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		//if no card in moving from row not valid
		if (!_tableCards[from].empty())
			fromCard = &_tableCards[from].top();
		else
			return false;
	}

	if (!_tableCards[to].empty())
		toCard = &_tableCards[to].top();

	//move king to empty space
	if (_tableCards[to].empty())
	{
		if (fromCard->GetCardRank() == 'K')
			return true;
		else
			return false;
	}
	else if (fromCard->GetSolitaireValue() == toCard->GetSolitaireValue() - 1)
	{
		int toColor = 0, fromColor = 0;
		if (toCard->GetCardSuit() == 'k' || toCard->GetCardSuit() == 'd')
			toColor = 0;
		else
			toColor = 1;
		if (fromCard->GetCardSuit() == 'p' || fromCard->GetCardSuit() == 't')
			fromColor = 0;
		else
			fromColor = 1;

		if (toCard->GetCardSuit() == 't' || toCard->GetCardSuit() == 'p')
			toColor = 0;
		else
			toColor = 1;
		if (fromCard->GetCardSuit() == 'k' || fromCard->GetCardSuit() == 'd')
			fromColor = 0;
		else
			fromColor = 1;
		
		if (fromColor == toColor)
			return false;
		else
			return true;
	}
	return false;
}

bool Solitaire::ValidSuitMove(int from)
{
	Card* fromCard;
	if (from == 7)
	{
		if (!_deck.empty())
		{
			if (!_deck.top().GetIsFaceUp())
			{
				return false;
			}
			else
			{
				fromCard = &_deck.top();
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (!_tableCards[from].empty())
			fromCard = &_tableCards[from].top();
		else
			return false;
	}
	char suit = fromCard->GetCardSuit();
	int moveIndex = 0;
	switch (suit)
	{
	case 'k':
		moveIndex = 0;
		break;
	case 'p':
		moveIndex = 1;
		break;
	case 'd':
		moveIndex = 2;
		break;
	case 't':
		moveIndex = 3;
		break;
	}
	if (fromCard->GetSolitaireValue() ==
		_suitCards[moveIndex].Size() + 1)
	{
		if (!_suitCards[moveIndex].Size() == 0)
		{
			if (fromCard->parent != NULL)
				fromCard->parent->child = NULL;
			fromCard->parent = &_suitCards[moveIndex].top();
			_suitCards[moveIndex].top().child = fromCard;
			fromCard->child = NULL;
		}
		if (from != 7) {
			TableCard::MoveBetween(_tableCards[from], _suitCards[moveIndex]);
			if (!_tableCards[from].empty())
			{
				if (!_tableCards[from].top().GetIsFaceUp())
					_tableCards[from].top().Flip();
			}
		}
		else
		{
			_suitCards[moveIndex].Push(_deck.top());
			_deck.Pop();
		}
	}


	return false;
}

void Solitaire::MakeSuitMove(int from)
{
	ValidSuitMove(from);
}

void Solitaire::MakeMoveBetweenRows(int from, int to)
{
	if (ValidMove(from, to))
	{
		if (!_tableCards[to].empty())
			_tableCards[to].top().child = &_tableCards[from].top();

		if (_tableCards[from].top().GetCardRank() != 'K')
			_tableCards[from].top().parent = &_tableCards[to].top();
		TableCard::MoveBetween(_tableCards[from], _tableCards[to]);

		if (!_tableCards[from].empty())
			if (!_tableCards[from].top().GetIsFaceUp())
				_tableCards[from].top().Flip();
	}
}

void Solitaire::MakeMoveDeckToRow(int to)
{
	if (ValidMove(7, to))
	{
		if (!_tableCards[to].empty())
			_tableCards[to].top().child = &_deck.top();
		if (_deck.top().GetCardRank() != 'K')
			_deck.top().parent = &_tableCards[to].top();

		_tableCards[to].Push(_deck.top());
		_deck.Pop();

	}
}

void Solitaire::MakeMoveRowToRow(int from, int to)
{
	if (from == 7)
	{
		MakeMoveDeckToRow(to);
		return;
	}
	else if (_tableCards[from].Size() == 0)
		return;
	Card* fromCard;
	fromCard = &_tableCards[from].top();
	if (fromCard->parent == NULL)
		MakeMoveBetweenRows(from, to);
	else
	{
		int pos = _tableCards[from].Size() - 1;
		bool checkParent = true;
		bool found = false;
		while (checkParent && !found)
		{
			if (ValidRowToRowMove(fromCard, to))
				found = true;
			else if (fromCard->parent == NULL)
				checkParent = false;
			else
			{
				fromCard = fromCard->parent;
				pos--;
			}

		}
		if (found)
		{
			bool hasChildren = true;
			if (fromCard->parent != NULL)
				fromCard->parent->child = NULL;

			while (hasChildren)
			{

				if (!_tableCards[to].empty())
				{
					fromCard->parent = &_tableCards[to].top();
					_tableCards[to].top().child = fromCard;
				}
				_tableCards[to].Push(*fromCard);
				_tableCards[from].RemoveAt(pos);
				fromCard = fromCard->child;


				pos++;
				if (fromCard == NULL)
					hasChildren = false;
			}
		}
		if (!_tableCards[from].empty())
			if (!_tableCards[from].top().GetIsFaceUp())
				_tableCards[from].top().Flip();
	}
}

bool Solitaire::ValidRowToRowMove(Card* fromCard, int to)
{
	Card* toCard = NULL;
	if (!_tableCards[to].empty())
		toCard = &_tableCards[to].top();

	//move king to empty space
	if (_tableCards[to].empty())
	{
		if (fromCard->GetCardRank() == 'K')
			return true;
		else
			return false;
	}

	else if (fromCard->GetSolitaireValue() == toCard->GetSolitaireValue() - 1)
	{
		int toColor = 0, fromColor = 0;
		if (toCard->GetCardSuit() == 'k' || toCard->GetCardSuit() == 'd')
			toColor = 0;
		else
			toColor = 1;
		if (fromCard->GetCardSuit() == 'p' || fromCard->GetCardSuit() == 't')
			fromColor = 0;
		else
			fromColor = 1;

		if (toCard->GetCardSuit() == 't' || toCard->GetCardSuit() == 'p')
			toColor = 0;
		else
			toColor = 1;
		if (fromCard->GetCardSuit() == 'k' || fromCard->GetCardSuit() == 'd')
			fromColor = 0;
		else
			fromColor = 1;
		if (fromColor == toColor)
			return false;
		else
			return true;
	}
	return false;
}

bool Solitaire::GameCompleted()
{
	for (int i = 0; i < _suitCards.size(); i++)
		if (_suitCards[i].Size() < 13)
			return false;
	return true;
}