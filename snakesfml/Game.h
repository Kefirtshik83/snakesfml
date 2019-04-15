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
	sf::CircleShape shape;
	sf::CircleShape shape1;
	sf::Font font;//רנטפע 
	sf::Text text;
	double time1 = 600000;
	int flag = -1; //start picture
	sf::Clock cl;
	sf::Time t = cl.getElapsedTime();
	Game();
	void tick();
	void draw_score(sf::RenderWindow &window);
	void draw_snake(sf::RenderWindow &window);
	void draw_fruit(sf::RenderWindow &window);
	void draw_field(sf::RenderWindow &window);
	void game_draw(sf::RenderWindow &window);
};