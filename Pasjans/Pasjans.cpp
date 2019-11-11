// Pasjans.cpp : Definiuje punkt wejścia dla aplikacji.

#include "stdafx.h"
#include "Pasjans.h"
#include "Solitaire.h"
#include "Deck.h"
#include "TableCard.h"

Solitaire game = Solitaire();

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pasjans - created by MM&WS", sf::Style::Close | sf::Style::Titlebar, settings);

	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(FPS);

	if (game.GameCompleted()) {
		return 1;
	}

	while (window.isOpen()) {
		//game.update();

		window.clear(sf::Color(30, 142, 57));
		game.PrintAllDetails(window);
		//game.draw(window);
		window.display();

		handle_events(window, game);
	}

	return 0;
}

void handle_events(sf::RenderWindow &window, Solitaire &game) {
	sf::Event e;
	while (window.pollEvent(e)) {
		switch (e.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			if (e.key.code == sf::Keyboard::Q) {
				window.close();
			}
			else if (e.key.code == sf::Keyboard::F2) {
				game.ResetGame();
			}
			break;
		case sf::Event::MouseButtonPressed:
			if (e.mouseButton.button == sf::Mouse::Left) {
				game.MousePressed(sf::Vector2f(e.mouseButton.x, e.mouseButton.y));
			}
			break;
		case sf::Event::MouseButtonReleased:
			if (e.mouseButton.button == sf::Mouse::Left) {
				game.MouseReleased(sf::Vector2f(e.mouseButton.x, e.mouseButton.y), game._column, game._row);
			}
			break;
		case sf::Event::MouseMoved:
			game.MouseMoved(sf::Vector2f(e.mouseMove.x, e.mouseMove.y), game._column, game._row);
			//game.MouseMoved(sf::Mouse::getPosition(), game._column, game._row);
			break;
		case sf::Event::MouseLeft:
			game.MouseLeft();
			break;
		}
	}
}