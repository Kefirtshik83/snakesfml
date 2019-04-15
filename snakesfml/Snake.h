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

public:
	int level;
	int dir;
	int len;
	int score = 0;
	std::vector <point> s;
	sf::Image image_s;
	sf::Texture texture_s;



	Snake(int dir = 1, int len = 2, int level = 1, int y0 = 15, std::string ss = "pictures/snake.jpg");
	virtual void control(); //обработка событий клавиатуры
	//void tick(); //движение змеи, проверка на соударение
} ;