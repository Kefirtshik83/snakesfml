
//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <sstream>

#include "Game.h"

//1-right  2-up  3-left   4-down



int main()
{
	
	Game game;
	std::cout << game.field.w << " " << game.field.h << std::endl;
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(game.field.w + 2 * game.field.d, game.field.h + 2 * game.field.d + game.field.h_field_for_score), "snake", sf::Style::Default, settings);
	game.game_draw(window);
	return 0;
}
