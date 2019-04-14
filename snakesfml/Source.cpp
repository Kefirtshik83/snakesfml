#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include "Game.h"
#include "Picture.h"

//1-right  2-up  3-left   4-down

Game game;

int main()
{
	sf::Font font;//шрифт 
	font.loadFromFile("pictures/CyrilicOld.TTF");//передаем нашему шрифту файл шрифта
	sf::Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	//text.setColor(sf::Color::Red);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый


	//headband
	Picture headband("snake1.jpg", 0, 0, 0, 0, game.w + 2 * game.d, game.h + 2 * game.d + game.h_field_for_score);
	//start button
	Picture start_button("start.png", game.w / 3, game.h / 3 + game.score, 50, 50, (game.w + 2 * game.d) / 3.1, (game.h + 2 * game.d) / 4);
	start_button.Create_Mask(255, 255, 255, 255);
	//draw wall
	sf::RectangleShape wall(sf::Vector2f(game.w + 2 * game.d, game.h + game.h_field_for_score + 2 * game.d));
	wall.setFillColor(sf::Color(200, 50, 50));

	//draw game
	Picture game1("field.jpg", game.d, game.h_field_for_score + game.d, 0, 0, game.w, game.h);

	//texture apple
	sf::Image appleim;
	appleim.loadFromFile("pictures/apple1.png");
	appleim.createMaskFromColor(sf::Color(255, 255, 255, 255), 0);
	sf::Texture appletex;
	appletex.loadFromImage(appleim);

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(game.w+2 * game.d, game.h+2 * game.d + game.h_field_for_score), "snake", sf::Style::Default, settings);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		if (game.flag >= 0)
		{
			//window.draw(wallsprite);
			window.draw(wall);
			window.draw(game1.sprite);

			std::ostringstream playerScoreString, playerLevelString;    
			playerScoreString << game.score;		
			text.setString("score:" + playerScoreString.str());
			text.setPosition(0, game.h_field_for_score - game.d);
			window.draw(text);
			playerLevelString << game.level;
			text.setString("level:" + playerLevelString.str());
			text.setPosition(game.w/2, game.h_field_for_score - game.d);
			window.draw(text);

			//sf::RectangleShape game(sf::Vector2f(w, h));
			//draw snake
			if(game.flag > 0)
				game.start_game();
			for (int i = 0; i < game.len; ++i)
			{
				sf::CircleShape shape(game.scale/2.f); //
				shape.setPosition(game.d + game.s[i].x * game.scale, game.d + game.s[i].y * game.scale + game.h_field_for_score);
				shape.setTexture(&game.texture);
				shape.setTextureRect(sf::IntRect(100, 100, 200, 200));
				window.draw(shape);
				if (i < game.len - 1)
				{
					sf::CircleShape shape1(12.f);
					shape1.setPosition(game.d + (game.s[i].x + game.s[i + 1].x) / 2.0 * game.scale, game.d + (game.s[i].y + game.s[i + 1].y) / 2.0 * game.scale + game.h_field_for_score);
					shape1.setTexture(&game.texture);
					shape1.setTextureRect(sf::IntRect(100, 100, 200, 200));
					window.draw(shape1);
				}
				//std:: cout << cl.getElapsedTime().asMilliseconds() << std::endl;
			}
			//draw fructs
			for (int i = 0; i < 6; ++i)
			{
				double k = 1.5;//retewt
				sf::RectangleShape quad(sf::Vector2f(k * game.scale, k  * game.scale));
				quad.setPosition(game.d + game.f[i].x * game.scale - game.scale * (k-1)/2, game.d + game.f[i].y * game.scale - game.scale*(k-1)/2 + game.h_field_for_score);
				quad.setTexture(&appletex);
				quad.setTextureRect(sf::IntRect(0, 0, 380, 380));
				window.draw(quad);
			}
			game.control();
		}
		else
		{
			window.draw(headband.sprite);
			window.draw(start_button.sprite);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { game.flag += 1; std::cout << game.flag << std::endl; }
		window.display();
	}
	return 0;
}
