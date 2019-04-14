#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>



double time1 = 600000;
int flag = -1; //start picture
sf::Clock cl;
sf::Time t = cl.getElapsedTime();

struct point
{
	int x;
	int y;
};


class Snake
{

public:
	int level;
	int dir;
	int len;
	std::vector <point> s;
	sf::Image image;
	sf::Texture texture;


	Snake(int dir = 1, int len = 2, int level = 1) : dir(dir), len(len), level(level)
	{
		for (int i = 0; i < len; ++i)
		{
			s.push_back({ 10, 15 + i });
		}
		image.loadFromFile("pictures/snake.jpg");
		texture.loadFromImage(image);
	}
	void control() //обработка событий клавиатуры
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { dir = 3; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { dir = 1; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { dir = 2; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { dir = 4; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5)) { flag = 0; }
	}
	void tick() //движение змеи, проверка на соударение
	{

		if (cl.getElapsedTime().asMicroseconds() - t.asMicroseconds() > time1*pow(0.9, level - 1))
		{
			t = cl.getElapsedTime();

			for (int i = len - 1; i > 0; --i)
			{
				s[i].x = s[i - 1].x;
				s[i].y = s[i - 1].y;
			}



			if (dir == 1) { s[0].x++; }
			if (dir == 2) { s[0].y--; }
			if (dir == 3) { s[0].x--; }
			if (dir == 4) { s[0].y++; }

			for (int i = 1; i < len; ++i)
			{
				if (s[i].x == s[0].x && s[i].y == s[0].y)
				{
					flag = -1;
					len = 2;
					s[0].x = 15;
					s[0].y = 10;
					field.score = 0;
				}
			}
			if (s[0].x * field.scale + field.d < field.d || s[0].x * field.scale + field.scale + field.d > field.w + field.d || s[0].y * field.scale + field.d < field.d || s[0].y * field.scale + field.scale + field.d> field.h + field.d)
			{
				flag = -1;
				len = 2;
				s[0].x = 15;
				s[0].y = 10;
				field.score = 0;
			}
		}

		for (int i = 0; i < 6; ++i)
		{
			if (s[0].x == f[i].x && s[0].y == f[i].y)
			{
				s.push_back({ -150,-150 });
				++field.score;
				level = 1 + field.score / 1;
				f[i].x = rand() % field.n; //
				f[i].y = rand() % field.m;
				len++;


			}
		}
	}
} snake(1, 2, 1);