#include "stdafx.h"
#include "TableCard.h"
#include "Card.h"

TableCard::TableCard(int maxSize)
	:_size(0)
	, _maxSize(maxSize)
{
	_cards.resize(maxSize);
}

TableCard::~TableCard(void)
{
}

bool TableCard::Push(Card& card)
{
	if (_size < _maxSize)
	{
		_cards[_size] = &card;
		_size++;
		return true;
	}
	return false;
}

bool TableCard::PushValueCopy(Card card)
{
	if (_size < _maxSize)
	{
		_cards[_size] = new Card(card);
		_size++;
		return true;
	}
	return false;
}

void TableCard::Clear()
{
	for (int i = 0; i < _size; i++)
		_cards[i] = NULL;

	_size = 0;
}

bool TableCard::empty()
{
	if (_size == 0)
		return true;
	return false;
}

Card& TableCard::top(void)
{
	if (_size > 0)
		return *_cards[_size - 1];
}

bool TableCard::RemoveAt(int index)
{
	if (index >= 0 && index < _maxSize)
	{
		_cards[index] = NULL;
		_size--;
		return true;
	}
	return false;
}

int TableCard::Size()
{
	return _size;
}

bool TableCard::Pop()
{
	if (_size > 0)
	{
		_cards[_size - 1] = NULL;
		_size--;
		return true;
	}
	return false;
}

Card& TableCard::operator[](int index)
{
	if (index >= 0 && index <= _size)
		return *_cards[index];
}

void TableCard::MoveBetween(TableCard& from, TableCard& to)
{
	to.Push(from.top());
	from.Pop();
}