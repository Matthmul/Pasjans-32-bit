#pragma once
#include "stdafx.h"

class Position {
public:
	std::pair<sf::Vector2f, sf::Vector2f> coord;
	Position();
	Position(sf::Vector2f destination_coord, sf::Vector2f destination_coord2);
	void init();
};

