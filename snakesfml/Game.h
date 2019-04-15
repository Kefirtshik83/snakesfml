#pragma once
#include "Picture.h"
#include "Field.h"
#include "Fruit.h"
#include "point.h"
#include "Snake.h"
#include "Snake_1.h"

class Game : public Field, public Fruit, public Snake
{
public:
	Picture headband;
	Picture start_button;
	Picture field;
	Snake_1 sn;

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
	int count_gamers = 2;
	int who_is_win = 0;
	sf::Clock cl;
	sf::Time t = cl.getElapsedTime();
	Game();
	void tick();
	void draw_score(sf::RenderWindow &window);
	void draw_snake(sf::RenderWindow &window, std::vector<point> sn);
	//void draw_sn(sf::RenderWindow &window, std::vector<point> sn);
	void draw_fruit(sf::RenderWindow &window);
	void draw_field(sf::RenderWindow &window);
	void game_draw(sf::RenderWindow &window);
};