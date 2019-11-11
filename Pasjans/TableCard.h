#pragma once
#include "Card.h"

class TableCard
{
public:
	TableCard(int maxSize);
	~TableCard(void);
	Card& operator[](int index);
	bool Push(Card& card);
	bool PushValueCopy(Card card);
	int Size();
	bool empty();
	Card& top(void);

	bool RemoveAt(int index);
	bool Pop();
	void Clear();
	static void MoveBetween(TableCard& from, TableCard& to);

private:
	int _maxSize;
	int _size;
	std::vector<Card*> _cards;
};
