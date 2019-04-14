#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include "picture.h"
#include "Field.h"
#include "variables.cpp"
#include "Fruit.h"
#include "Snake.h"

//1-right  2-up  3-left   4-down
/*
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
			s.push_back({10, 15 + i});
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
}*/ 



int main()
{
	//шрифт

	sf::Font font;//шрифт 
	font.loadFromFile("pictures/CyrilicOld.TTF");//передаем нашему шрифту файл шрифта
	sf::Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	//text.setColor(sf::Color::Red);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый


	//headband
	Picture headband("snake1.jpg", 0, 0, 0, 0, field.w + 2 * field.d, field.h + 2 * field.d + field.h_field_for_score);
	//start button
	Picture start_button("start.png", field.w / 3, field.h / 3 + field.score, 50, 50, (field.w + 2 * field.d) / 3.1, (field.h + 2 * field.d) / 4);
	start_button.Create_Mask(255, 255, 255, 255);
	//draw wall
	sf::RectangleShape wall(sf::Vector2f(field.w + 2 * field.d, field.h + field.h_field_for_score + 2 * field.d));
	wall.setFillColor(sf::Color(200, 50, 50));

	//draw field
	Picture field1("field.jpg", field.d, field.h_field_for_score + field.d, 0, 0, field.w, field.h);

	//texture apple
	sf::Image appleim;
	appleim.loadFromFile("pictures/apple1.png");
	appleim.createMaskFromColor(sf::Color(255, 255, 255, 255), 0);
	sf::Texture appletex;
	appletex.loadFromImage(appleim);

	//s[0].x = 15;
	//s[0].y = 10;

	for (int i = 0; i < 6; ++i)
	{
		f[i].x = rand() % field.n;
		f[i].y = rand() % field.m;

	}

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(field.w+2 * field.d, field.h+2 * field.d + field.h_field_for_score), "snake", sf::Style::Default, settings);

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		if (flag >= 0)
		{
			//window.draw(wallsprite);
			window.draw(wall);
			window.draw(field1.sprite);


			std::ostringstream playerScoreString, playerLevelString;    
			playerScoreString << field.score;		
			text.setString("score:" + playerScoreString.str());
			text.setPosition(0, field.h_field_for_score - field.d);
			window.draw(text);
			playerLevelString << snake.level;
			text.setString("level:" + playerLevelString.str());
			text.setPosition(field.w/2, field.h_field_for_score - field.d);
			window.draw(text);

			//sf::RectangleShape field(sf::Vector2f(w, h));
			//draw snake
			if(flag > 0)
				snake.tick();
			for (int i = 0; i < snake.len; ++i)
			{

				sf::CircleShape shape(field.scale/2.f); //
				shape.setPosition(field.d + snake.s[i].x * field.scale, field.d + snake.s[i].y * field.scale + field.h_field_for_score);
				shape.setTexture(&snake.texture);
				shape.setTextureRect(sf::IntRect(100, 100, 200, 200));
				window.draw(shape);
				if (i < snake.len - 1)
				{
					sf::CircleShape shape1(12.f);
					shape1.setPosition(field.d + (snake.s[i].x + snake.s[i + 1].x) / 2.0 * field.scale, field.d + (snake.s[i].y + snake.s[i + 1].y) / 2.0 * field.scale + field.h_field_for_score);
					shape1.setTexture(&snake.texture);
					shape1.setTextureRect(sf::IntRect(100, 100, 200, 200));
					window.draw(shape1);
				}
				//std:: cout << cl.getElapsedTime().asMilliseconds() << std::endl;
			}

			//draw fructs
			for (int i = 0; i < 6; ++i)
			{
				double k = 1.5;//retewt
				sf::RectangleShape quad(sf::Vector2f(k * field.scale, k  * field.scale));
				quad.setPosition(field.d + f[i].x * field.scale - field.scale * (k-1)/2, field.d + f[i].y * field.scale - field.scale*(k-1)/2 + field.h_field_for_score);
				quad.setTexture(&appletex);
				quad.setTextureRect(sf::IntRect(0, 0, 380, 380));
				window.draw(quad);
			}

			snake.control();
		}
		else
		{

			window.draw(headband.sprite);


			window.draw(start_button.sprite);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { flag += 1; std::cout << flag << std::endl; }

		window.display();
	}

	return 0;
}
