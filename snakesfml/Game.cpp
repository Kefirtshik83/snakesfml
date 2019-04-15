#include "Game.h"

Game::Game() : Snake(1, 2, 1), Fruit(), headband("snake1.jpg", 0, 0, 0, 0, w + 2 * d, h + 2 * d + h_field_for_score), start_button("start.png", w / 3, h / 3 + score, 50, 50, (w + 2 * d) / 3.1, (h + 2 * d) / 4), wall(sf::Vector2f(w + 2 * d, h + h_field_for_score + 2 * d)), text("", font, 20), 
field("field.jpg", d, h_field_for_score + d, 0, 0, w, h)
{
	font.loadFromFile("pictures/CyrilicOld.TTF");//передаем нашему шрифту файл шрифта
	sf::Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	//text.setColor(sf::Color::Red);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый

	appleim.loadFromFile("pictures/apple1.png");
	appleim.createMaskFromColor(sf::Color(255, 255, 255, 255), 0);

	start_button.Create_Mask(255, 255, 255, 255);
	wall.setFillColor(sf::Color(200, 50, 50));

	appletex.loadFromImage(appleim);
}

void Game::start_game()
{
	if (cl.getElapsedTime().asMicroseconds() - t.asMicroseconds() > time1*pow(0.9, level - 1))
	{
		t = cl.getElapsedTime();

		for (int i = len - 1; i > 0; --i)
		{
			s[i].x = s[i - 1].x;
			s[i].y = s[i - 1].y;
		}
		for (int i = 0; i < 6; ++i)
		{
			f[i].x = f[i].x % n;
			f[i].y = f[i].y % m;
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
				score = 0;
			}
		}
		if (s[0].x * scale + d < d || s[0].x * scale + scale + d > w + d || s[0].y * scale + d < d || s[0].y * scale + scale + d> h + d)
		{
			flag = -1;
			len = 2;
			s[0].x = 15;
			s[0].y = 10;
			score = 0;
		}
	}

	for (int i = 0; i < 6; ++i)
	{
		if (s[0].x == f[i].x && s[0].y == f[i].y)
		{
			s.push_back({ -150,-150 });
			++score;
			level = 1 + score / 1;
			f[i].x = rand() % n; //
			f[i].y = rand() % m;
			len++;


		}
	}
}

void Game::game_draw(sf::RenderWindow & window)
{


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
			window.draw(field.sprite);

			std::ostringstream playerScoreString, playerLevelString;
			playerScoreString << score;
			text.setString("score:" + playerScoreString.str());
			text.setPosition(0, h_field_for_score - d);
			window.draw(text);
			playerLevelString << level;
			text.setString("level:" + playerLevelString.str());
			text.setPosition(w / 2, h_field_for_score - d);
			window.draw(text);

			//sf::RectangleShape game(sf::Vector2f(w, h));
			//draw snake
			if (flag > 0)
				start_game();
			for (int i = 0; i <len; ++i)
			{
				sf::CircleShape shape(scale / 2.f); //
				shape.setPosition(d + s[i].x * scale, d + s[i].y * scale + h_field_for_score);
				shape.setTexture(&texture_s);
				shape.setTextureRect(sf::IntRect(100, 100, 200, 200));
				window.draw(shape);
				if (i < len - 1)
				{
					sf::CircleShape shape1(12.f);
					shape1.setPosition(d + (s[i].x + s[i + 1].x) / 2.0 * scale,d + (s[i].y + s[i + 1].y) / 2.0 * scale + h_field_for_score);
					shape1.setTexture(&texture_s);
					shape1.setTextureRect(sf::IntRect(100, 100, 200, 200));
					window.draw(shape1);
				}
				//std:: cout << cl.getElapsedTime().asMilliseconds() << std::endl;
			}
			//draw fructs
			for (int i = 0; i < 6; ++i)
			{
				double k = 1.5;//retewt
				sf::RectangleShape quad(sf::Vector2f(k * scale, k  * scale));
				quad.setPosition(d + f[i].x * scale - scale * (k - 1) / 2, d + f[i].y * scale - scale*(k - 1) / 2 + h_field_for_score);
				quad.setTexture(&appletex);
				quad.setTextureRect(sf::IntRect(0, 0, 380, 380));
				window.draw(quad);
			}
			control();
		}
		else
		{
			window.draw(headband.sprite);
			window.draw(start_button.sprite);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { flag += 1; std::cout << flag << std::endl; }
		window.display();
	}
}