#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include "Game.h"
#include "Picture.h"

//1-right  2-up  3-left   4-down

Game game;

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(game.w + 2 * game.d, game.h + 2 * game.d + game.h_field_for_score), "snake", sf::Style::Default, settings);
	game.game_draw(window);
	return 0;
}
