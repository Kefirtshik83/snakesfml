#pragma once
#include "Picture.h"
#include "Field.h"
#include "Fruit.h"
#include "point.h"
#include "Snake.h"

class Game : public Field, public Fruit, public Snake
{
public:
	Picture headband;
	Picture start_button;
	Picture field;

	//texture apple
	sf::Image appleim;
	sf::Texture appletex;

	sf::RectangleShape wall;
	sf::Font font;//רנטפע 
	sf::Text text;
	double time1 = 600000;
	int flag = -1; //start picture
	sf::Clock cl;
	sf::Time t = cl.getElapsedTime();
	Game();
	void start_game();
	void game_draw(sf::RenderWindow &window);
};