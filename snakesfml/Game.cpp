#include "Game.h"

Game::Game() : field(50, 30, 24, 20, 60), headband("snake1.jpg", 0, 0, 0, 0, field.w + 2 * field.d, field.h + 2 * field.d + field.h_field_for_score),
start_button("start.png", field.w / 3, field.h / 3 + field.h_field_for_score, 50, 50, (field.w + 2 * field.d) / 3.1, (field.h + 2 * field.d) / 4),
wall(sf::Vector2f(field.w + 2 * field.d, field.h + field.h_field_for_score + 2 * field.d)),
text("", font, 20),
field_picture("field.jpg", field.d, field.h_field_for_score + field.d, 0, 0, field.w, field.h),
shape(field.scale / 2.f), shape1(12.f)
{	
	std::cout << "field.w = " << field.w << std::endl;
	font.loadFromFile("pictures/CyrilicOld.TTF");//передаем нашему шрифту файл шрифта
	sf::Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	//text.setColor(sf::Color::Red);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый

	appleim.loadFromFile("pictures/apple1.png");
	appleim.createMaskFromColor(sf::Color(255, 255, 255, 255), 0);

	start_button.Create_Mask(255, 255, 255, 255);
	wall.setFillColor(sf::Color(200, 50, 50));

	appletex.loadFromImage(appleim);


	shape.setTexture(&snake_1.texture_s);
	shape.setTextureRect(sf::IntRect(100, 100, 200, 200));
	shape1.setTexture(&snake_1.texture_s);
	shape1.setTextureRect(sf::IntRect(100, 100, 200, 200));
}

void Game::tick()
{
	if (cl.getElapsedTime().asMicroseconds() - t.asMicroseconds() > time1*pow(0.9, snake_1.level - 1))
	{
		t = cl.getElapsedTime();

		for (int i = snake_1.len - 1; i > 0; --i)
		{
			snake_1.s[i].x = snake_1.s[i - 1].x;
			snake_1.s[i].y = snake_1.s[i - 1].y;
		}
		for (int i = 0; i < 6; ++i)
		{
			fruit.f[i].x = fruit.f[i].x % field.n;
			fruit.f[i].y = fruit.f[i].y % field.m;
		}



		if (snake_1.dir == 1) { snake_1.s[0].x++; }
		if (snake_1.dir == 2) { snake_1.s[0].y--; }
		if (snake_1.dir == 3) { snake_1.s[0].x--; }
		if (snake_1.dir == 4) { snake_1.s[0].y++; }

		for (int i = 1; i < snake_1.len; ++i)
		{
			if (snake_1.s[i].x == snake_1.s[0].x && snake_1.s[i].y == snake_1.s[0].y)
			{
				flag = -1;
				snake_1.len = 2;
				snake_1.s[0].x = 15;
				snake_1.s[0].y = 10;
				snake_1.score = 0;
			}
		}
		if (snake_1.s[0].x * field.scale + field.d < field.d || snake_1.s[0].x *field.scale + field.scale + field.d > field.w + field.d || snake_1.s[0].y * field.scale + field.d < field.d || snake_1.s[0].y * field.scale + field.scale + field.d> field.h + field.d)
		{
			flag = -1;
			snake_1.len = 2;
			snake_1.s[0].x = 15;
			snake_1.s[0].y = 10;
			snake_1.score = 0;
		}
		if (count_gamers > 1)
		{
			for (int i = snake_2.len - 1; i > 0; --i)
			{
				snake_2.s[i].x = snake_2.s[i - 1].x;
				snake_2.s[i].y = snake_2.s[i - 1].y;
			}



			if (snake_2.dir == 1) { snake_2.s[0].x++; }
			if (snake_2.dir == 2) { snake_2.s[0].y--; }
			if (snake_2.dir == 3) { snake_2.s[0].x--; }
			if (snake_2.dir == 4) { snake_2.s[0].y++; }
		}
	}

	for (int i = 0; i < 6; ++i)
	{
		if (snake_1.s[0].x == fruit.f[i].x && snake_1.s[0].y == fruit.f[i].y)
		{
			snake_1.s.push_back({ -150,-150 });
			++snake_1.score;
			snake_1.level = 1 + snake_1.score / 1;
			fruit.f[i].x = rand() % field.n; //
			fruit.f[i].y = rand() % field.m;
			snake_1.len++;


		}
	}
	if (count_gamers > 1)
	{
		for (int i = 0; i < 6; ++i)
		{
			if (snake_2.s[0].x == fruit.f[i].x && snake_2.s[0].y == fruit.f[i].y)
			{
				snake_2.s.push_back({ -150,-150 });
				++snake_2.score;
				snake_2.level = 1 + snake_2.score / 1;
				fruit.f[i].x = rand() % field.n; //
				fruit.f[i].y = rand() % field.m;
				snake_2.len++;


			}
		}

		if (who_is_win == 0)
		{
			for (int i = 0; i < snake_2.s.size(); ++i)
			{
				if (snake_1.s[0].x == snake_2.s[i].x && snake_1.s[0].y == snake_2.s[i].y)
				{
					who_is_win = 2;
				}
			}
			for (int i = 0; i < snake_1.s.size(); ++i)
			{
				if (snake_2.s[0].x == snake_1.s[i].x && snake_2.s[0].y == snake_1.s[i].y)
				{
					who_is_win = 1;
				}
			}
		}
	}
}

void Game::draw_score(sf::RenderWindow &window)
{
	std::ostringstream playerScoreString, playerLevelString;
	playerScoreString << snake_1.score;
	text.setString("score:" + playerScoreString.str());
	text.setPosition(field.d, field.h_field_for_score - field.d);
	window.draw(text);
	playerLevelString << snake_1.level;
	text.setString("level:" + playerLevelString.str());
	text.setPosition(field.w / 2, field.h_field_for_score - field.d);
	window.draw(text);
}

void Game::draw_snake(sf::RenderWindow &window, std::vector<point> sn_)
{
	//draw snake

	for (int i = 0; i < sn_.size(); ++i)
	{
		shape.setPosition(field.d + sn_[i].x * field.scale, field.d + sn_[i].y * field.scale + field.h_field_for_score);
		window.draw(shape);
		if (i < sn_.size() - 1)
		{
			shape1.setPosition(field.d + (sn_[i].x + sn_[i + 1].x) / 2.0 * field.scale, field.d + (sn_[i].y + sn_[i + 1].y) / 2.0 * field.scale + field.h_field_for_score);
			window.draw(shape1);
		}
		//std:: cout << cl.getElapsedTime().asMilliseconds() << std::endl;
	}

}

void Game::draw_fruit(sf::RenderWindow &window)
{
	//draw fructs
	for (int i = 0; i < 6; ++i)
	{
		double k = 1.5;//retewt
		sf::RectangleShape quad(sf::Vector2f(k * field.scale, k  * field.scale));
		quad.setPosition(field.d + fruit.f[i].x * field.scale - field.scale * (k - 1) / 2, field.d + fruit.f[i].y * field.scale - field.scale * (k - 1) / 2 + field.h_field_for_score);
		quad.setTexture(&appletex);
		quad.setTextureRect(sf::IntRect(0, 0, 380, 380));
		window.draw(quad);
	}
}
void Game::draw_field(sf::RenderWindow &window)
{
	//window.draw(wallsprite);
	window.draw(wall);
	window.draw(field_picture.sprite);
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
			draw_field(window);
			draw_score(window);
			if (flag > 0)
				tick();
			/*
			if(count_gamers > 1)
				shape.setFillColor(sf::Color::Red);
			draw_snake(window, s);
			if (count_gamers > 1)
			{
				shape.setFillColor(sf::Color::Green);
				draw_snake(window, sn.s);
			}
			*/
			if (count_gamers == 1)
			{
				draw_snake(window, snake_1.s);
			}
			else
			{
				if (who_is_win == 0)
				{
					shape.setFillColor(sf::Color::Red);
					draw_snake(window, snake_1.s);
					shape.setFillColor(sf::Color::Green);
					draw_snake(window, snake_2.s);
				}
				if (who_is_win == 1)
				{
					shape.setFillColor(sf::Color::Red);
					draw_snake(window, snake_1.s);
				}
				if (who_is_win == 2)
				{
					shape.setFillColor(sf::Color::Green);
					draw_snake(window, snake_2.s);
				}
			}
			draw_fruit(window);
			snake_1.control();
			snake_2.control();
		}
		else
		{
			window.draw(headband.sprite);
			//std::cout << "hui" << std::endl;
			window.draw(start_button.sprite);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { flag += 1; std::cout << flag << std::endl; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5)) { flag = 0; }
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
		sf::Vector2f pos = (window).mapPixelToCoords(pixelPos);
		//std::cout << pos.x << " " << pos.y << std::endl;
		if (pos.x > 434 && pos.x < 807 && pos.y > (field.h + 2 * field.d) / 4 && pos.y < 418 && pos.y > 327 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			flag += 1;
		}
		window.display();
	}
}