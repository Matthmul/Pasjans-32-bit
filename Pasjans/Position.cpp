#include "Position.h"

Position::Position() {
	init();
}

Position::Position(sf::Vector2f destination_coord, sf::Vector2f destination_coord2) {
	if(destination_coord.x != NULL) coord.first = destination_coord;
	if (destination_coord2.x != NULL) coord.second = destination_coord2;
}


void Position::init() {
	coord.first = coord.second = sf::Vector2f(-1, -1);
}