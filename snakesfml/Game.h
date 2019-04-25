#pragma once
#include <iostream>
#include "Picture.h"
#include "Field.h"
#include "Fruit.h"
#include "point.h"
#include "Snake.h"
#include "Snake_1.h"

class Game 
{
public:
	const int ooo = 1200;
	Field field;
	Picture headband;
	Picture start_button;
	Picture field_picture;
	Picture one_player_button;
	Picture two_player_button;
	Picture one_snake_button;
	Picture two_snake_button;

	Fruit fruit;
	Snake snake_1;
	Snake_1 snake_2;

	sf::RectangleShape wall;
	sf::CircleShape shape;
	sf::CircleShape shape1;
	sf::Font font;//רנטפע 
	sf::Text text;
	double time1 = 600000;
	bool play = 0;
	bool one_player = 0;
	bool two_player = 0;
	bool one_snake = 0;
	bool two_snake = 0;
	int who_is_win = 0;
	sf::Clock cl;
	sf::Time t1 = cl.getElapsedTime();
	sf::Time t2 = cl.getElapsedTime();
	Game();
	void one_g_one_s_tick();
	void one_g_two_s_tick();
	void two_g_two_s_tick();
	void draw_score(sf::RenderWindow &window);
	void draw_snake(sf::RenderWindow &window, std::vector<point> sn);
	//void draw_sn(sf::RenderWindow &window, std::vector<point> sn);
	void draw_headband_1(sf::RenderWindow &window);
	void draw_headband_1_1(sf::RenderWindow &window);
	void draw_fruit(sf::RenderWindow &window);
	void draw_field(sf::RenderWindow &window);
	void game_draw(sf::RenderWindow &window);
	void chose_count_of_players(sf::RenderWindow &window, sf::Event event);
	void chose_count_of_snakes(sf::RenderWindow &window, sf::Event event);
	void snack_1_died();
	void snack_2_died();
	void one_s_stand_pos();
	void two_s_stand_pos();
	void snake_1_set_dir();
	void snake_2_set_dir();

};