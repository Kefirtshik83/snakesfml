#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include "point.h"
#include "Field.h"
#include "Fruit.h"




class Snake
{

protected:
	int level;
	int dir;
	int len;
	int score = 0;
	std::vector <point> s;
	sf::Image image_s;
	sf::Texture texture_s;


public:
	Snake(int dir = 1, int len = 2, int level = 1, int y0 = 15, std::string ss = "pictures/snake.jpg");
	virtual void control(); //обработка событий клавиатуры
	int get_level();
	int get_dir();
	int get_len();
	int get_score();
	void set_level(int x);
	void set_dir(int x);
	void set_len(int x);
	void set_score(int x);
	void resize_s(int x);
	void s_x_plus(int i, int x);
	void s_y_plus(int i, int x);
	void s_push_back(int x, int y);
	point get_s(int i);
	void set_s(int i, int x, int y);
	std::vector <point> get_full_s();
	sf::Image get_image();
	sf::Texture* get_texture();
} ;