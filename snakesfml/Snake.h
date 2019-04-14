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
	std::vector <point> s;
	sf::Image image;
	sf::Texture texture;


	Snake(int dir = 1, int len = 2, int level = 1);
	void control(); //обработка событий клавиатуры
	//void tick(); //движение змеи, проверка на соударение
} ;