#pragma once
#include "Picture.h"
#include "Field.h"
#include "Fruit.h"
#include "point.h"
#include "Snake.h"

class Game : public Field, public Fruit, public Snake
{
public:
	double time1 = 600000;
	int flag = -1; //start picture
	sf::Clock cl;
	sf::Time t = cl.getElapsedTime();
	Game();
	void start_game();
};