#include "Game.h"

Game::Game() : field(50, 30, 24, 20, 60),
one_player_button("one_player.png", field.get_w() / 3, field.get_h() / 5 + field.get_h_field_for_score(), 0, 0, 204, 54),
two_player_button("two_players.png", field.get_w() / 3, field.get_h() / 2 + field.get_h_field_for_score(), 0, 0, 204, 54),
one_snake_button("one_snake.png", field.get_w() / 3, field.get_h() / 5 + field.get_h_field_for_score(), 0, 0, 204, 54),
two_snake_button("two_snakes.png", field.get_w() / 3, field.get_h() / 2 + field.get_h_field_for_score(), 0, 0, 204, 54),
headband("snake1.jpg", 0, 0, 0, 0, field.get_w() + 2 * field.get_d(), field.get_h() + 2 * field.get_d() + field.get_h_field_for_score()),
start_button("start.png", field.get_w() / 3, field.get_h() / 3 + field.get_h_field_for_score(), 50, 50, (field.get_w() + 2 * field.get_d()) / 3.1, (field.get_h() + 2 * field.get_d()) / 4),
wall(sf::Vector2f(field.get_w() + 2 * field.get_d(), field.get_h() + field.get_h_field_for_score() + 2 * field.get_d())),
text("", font, 20),
field_picture("field.jpg", field.get_d(), field.get_h_field_for_score() + field.get_d(), 0, 0, field.get_w(), field.get_h()),
shape(field.get_scale() / 2.f), shape1(12.f)
{	

	std::cout << "field.w = " << field.get_w() << std::endl;
	font.loadFromFile("pictures/CyrilicOld.TTF");//передаем нашему шрифту файл шрифта
	sf::Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	//text.setColor(sf::Color::Red);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый

	start_button.Create_Mask(255, 255, 255, 255);
	wall.setFillColor(sf::Color(200, 50, 50));
	fruit.Set_Scale(field.get_scale());




	shape.setTexture(snake_1.get_texture());
	shape.setTextureRect(sf::IntRect(100, 100, 200, 200));
	shape1.setTexture(snake_1.get_texture());
	shape1.setTextureRect(sf::IntRect(100, 100, 200, 200));
}

void Game::snake_1_set_dir()
{
	if (snake_1.get_dir() == 1) { snake_1.s_x_plus(0, 1); }
	if (snake_1.get_dir() == 2) { snake_1.s_y_plus(0, -1); }
	if (snake_1.get_dir() == 3) { snake_1.s_x_plus(0, -1); }
	if (snake_1.get_dir() == 4) { snake_1.s_y_plus(0, 1); }
}
void Game::snake_2_set_dir()
{
	if (snake_2.get_dir() == 1) { snake_2.s_x_plus(0, 1); }
	if (snake_2.get_dir() == 2) { snake_2.s_y_plus(0, -1); }
	if (snake_2.get_dir() == 3) { snake_2.s_x_plus(0, -1); }
	if (snake_2.get_dir() == 4) { snake_2.s_y_plus(0, 1); }
}

void Game::snack_1_died()
{
	who_is_win = 2;
	snake_1.set_dir(1);
	snake_1.resize_s(1);
	snake_1.set_len(0);
	snake_1.set_level(0);
	snake_1.set_s(0, -120, -120);
	snake_1.set_score(0);
}

void Game::snack_2_died()
{
	who_is_win = 1;
	snake_2.set_dir(1);
	snake_2.resize_s(1);
	snake_2.set_len(0);
	snake_2.set_level(0);
	snake_2.set_s(0, -120, -120);
	snake_2.set_score(0);
}

void Game::one_s_stand_pos()
{

}

void Game::two_s_stand_pos()
{
	who_is_win = 0;
	play = 0;
	one_player = 0;
	two_player = 0;
	one_snake = 0;
	two_snake = 0;
	snake_1.set_dir(1);
	snake_2.set_dir(1);
	snake_1.resize_s(2);
	snake_1.set_len(2);
	snake_1.set_level(1);
	snake_1.set_s(0, 15, 10);
	snake_1.set_score(0);
	snake_2.resize_s(2);
	snake_2.set_len(2);
	snake_2.set_level(1);
	snake_2.set_s(0, 15, 18);
	snake_2.set_score(0);
}

void Game::draw_score(sf::RenderWindow &window)
{
	if (one_player)
	{
		std::ostringstream playerScoreString, playerLevelString;
		playerScoreString << snake_1.get_score();
		text.setString("score:" + playerScoreString.str());
		text.setPosition(field.get_d(), field.get_h_field_for_score() - field.get_d());
		window.draw(text);
		playerLevelString << snake_1.get_level();
		text.setString("level:" + playerLevelString.str());
		text.setPosition(field.get_w() / 2, field.get_h_field_for_score() - field.get_d());
		window.draw(text);
	}
	if (two_player)
	{
		std::ostringstream playerScoreString_1, playerLevelString_1, playerScoreString_2, playerLevelString_2;
		playerScoreString_1 << snake_1.get_score();
		text.setString("1 score:" + playerScoreString_1.str());
		text.setPosition(field.get_d(), field.get_h_field_for_score() - field.get_d());
		window.draw(text);
		playerLevelString_1 << snake_1.get_level();
		text.setString("1 level:" + playerLevelString_1.str());
		text.setPosition(field.get_w() / 4, field.get_h_field_for_score() - field.get_d());
		window.draw(text);
		playerScoreString_2 << snake_2.get_score();
		text.setString("2 score:" + playerScoreString_2.str());
		text.setPosition(field.get_w()/2, field.get_h_field_for_score() - field.get_d());
		window.draw(text);
		playerLevelString_2 << snake_2.get_level();
		text.setString("2 level:" + playerLevelString_2.str());
		text.setPosition(field.get_w()*3 / 4, field.get_h_field_for_score() - field.get_d());
		window.draw(text);
	}
}

void Game::draw_snake(sf::RenderWindow &window, std::vector<point> sn_)
{
	//draw snake

	for (int i = 0; i < sn_.size(); ++i)
	{
		shape.setPosition(field.get_d() + sn_[i].x * field.get_scale(), field.get_d() + sn_[i].y * field.get_scale() + field.get_h_field_for_score());
		window.draw(shape);
		if (i < sn_.size() - 1)
		{
			shape1.setPosition(field.get_d() + (sn_[i].x + sn_[i + 1].x) / 2.0 * field.get_scale(), field.get_d() + (sn_[i].y + sn_[i + 1].y) / 2.0 * field.get_scale() + field.get_h_field_for_score());
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
		double k = 1.5;
		window.draw(fruit.get_sprite(i, field.get_d() + fruit.get_f(i).x * field.get_scale() - field.get_scale() * (k - 1) / 2, field.get_d() + fruit.get_f(i).y * field.get_scale() - field.get_scale() * (k - 1) / 2 + field.get_h_field_for_score()));
	}
}

void Game::draw_field(sf::RenderWindow &window)
{
	//window.draw(wallsprite);
	window.draw(wall);
	window.draw(field_picture.get_sprite());
}

void Game::chose_count_of_players(sf::RenderWindow &window, sf::Event event)
{
	{
		if (!one_player && !two_player)
		{

			sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
			sf::Vector2f pos = (window).mapPixelToCoords(pixelPos);
			if (pos.x > field.get_w() / 3 && pos.x < field.get_w() / 3 + 204 * 2 && pos.y > field.get_h() / 5 + field.get_h_field_for_score() && pos.y < field.get_h() / 5 + field.get_h_field_for_score() + 2 * 54 && event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				one_player = 1;
			}

			if (pos.x > field.get_w() / 3 && pos.x < field.get_w() / 3 + 204 * 2 && pos.y > field.get_h() / 2 + field.get_h_field_for_score() && pos.y < field.get_h() / 2 + field.get_h_field_for_score() + 2 * 54 && event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				two_player = 1;
				play = 1;
			}
		}
	}
}

void Game::draw_headband_1(sf::RenderWindow &window)
{
	one_player_button.Set_Scale(2.f, 2.f);
	two_player_button.Set_Scale(2.f, 2.f);
	window.draw(headband.get_sprite());
	window.draw(one_player_button.get_sprite());
	window.draw(two_player_button.get_sprite());
}

void Game::chose_count_of_snakes(sf::RenderWindow &window, sf::Event event)
{
	if (one_player && (!one_snake && !two_snake))
	{
		{

			sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
			sf::Vector2f pos = (window).mapPixelToCoords(pixelPos);
			if (pos.x > field.get_w() / 3 && pos.x < field.get_w() / 3 + 204 * 2 && pos.y > field.get_h() / 5 + field.get_h_field_for_score() && pos.y < field.get_h() / 5 + field.get_h_field_for_score() + 2 * 54 && event.type == event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				one_snake = 1;
				play = 1;
			}

			if (pos.x > field.get_w() / 3 && pos.x < field.get_w() / 3 + 204 * 2 && pos.y > field.get_h() / 2 + field.get_h_field_for_score() && pos.y < field.get_h() / 2 + field.get_h_field_for_score() + 2 * 54 && event.type == event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				two_snake = 1;
				play = 1;
			}
		}
	}
}

void Game::draw_headband_1_1(sf::RenderWindow &window)
{
	one_snake_button.Set_Scale(2.f, 2.f);
	two_snake_button.Set_Scale(2.f, 2.f);
	window.draw(headband.get_sprite());
	window.draw(one_snake_button.get_sprite());
	window.draw(two_snake_button.get_sprite());
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
			chose_count_of_players(window, event);
			chose_count_of_snakes(window, event);

		}

		window.clear();



		if (!play && !one_player && !two_player && !one_snake && !two_snake)
		{
			draw_headband_1(window);
			sf::Text text;
			double time1 = 600000;
			bool play = 0;
			bool one_player = 0;
			bool two_player = 0;
			bool one_snake = 0;
			bool two_snake = 0;
			int who_is_win = 0;
			

		}
		if (one_player)
		{
			if (!two_snake && !one_snake)
			{
				draw_headband_1_1(window);
			}
			if (one_snake && one_player)
			{
				draw_field(window);
				draw_score(window);
				if (play > 0)
					one_g_one_s_tick();
				draw_snake(window, snake_1.get_full_s());
				draw_fruit(window);
				snake_1.control();

			}
			if (two_snake && one_player)
			{
				std::cout << "kek" << std::endl;
				draw_field(window);
				draw_score(window);
				if(play > 0)
					one_g_two_s_tick();
				shape.setFillColor(sf::Color::Red);
				draw_snake(window, snake_1.get_full_s());
				shape.setFillColor(sf::Color::Green);
				draw_snake(window, snake_2.get_full_s());
				draw_fruit(window);

				snake_1.control();

				snake_2.control();
			}
		}
		if (two_player)
		{
			std::cout << "kek" << std::endl;
			draw_field(window);
			draw_score(window);
			if (play > 0)
				two_g_two_s_tick();
			shape.setFillColor(sf::Color::Red);
			draw_snake(window, snake_1.get_full_s());
			shape.setFillColor(sf::Color::Green);
			draw_snake(window, snake_2.get_full_s());
			draw_fruit(window);

			snake_1.control();

			snake_2.control();
		}
		window.display();
	}
}