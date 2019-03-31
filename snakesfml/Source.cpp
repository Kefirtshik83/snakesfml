#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <cmath>
int n = 50, m = 30;
int scale = 24;
int d = 20;
int w = scale * n;
int hscore = 60;
int score = 0;
double time1 = 600000;
int level = 1, maxlevel = 15;
int h = scale * m;
//1-right  2-up  3-left   4-down
int dir = 1, len = 5;
int flag = -1; //start picture
int i =  5;



class Picture
{
public:
	float x_position, y_position;
	int x1_im, x2_im, y1_im, y2_im; //size of cut out rectangle
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	std::string pic_name; //name of picture
	Picture(std::string pic_name, float x_position=0, float y_position=0, int x1_im=-1,  int y1_im=-1, int x2_im = -1, int y2_im=-1) : x_position(x_position), y_position(y_position),
		x1_im(x1_im), x2_im(x2_im), y1_im(y1_im), y2_im(y2_im), pic_name(pic_name)
	{
		image.loadFromFile("pictures/" + pic_name);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(x1_im, y1_im, x2_im, y2_im));
		sprite.setPosition(x_position, y_position);
	}
	void Create_Mask(int r, int g, int b, int a)
	{
		image.createMaskFromColor(sf::Color(r, g, b, a), 0);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(x1_im, y1_im, x2_im, y2_im));
		sprite.setPosition(x_position, y_position);
	}

};

sf::Clock cl;
sf::Time t = cl.getElapsedTime();



class Snake
{
public:
	int x;
	int y;
} s[600]; // s[0] - head

class fruit
{
public:
	int x;
	int y;
} f[6];

void tick()
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
				score = 0;
			}
		}
		if (s[0].x * scale + d < d || s[0].x * scale + scale + d > w + d || s[0].y * scale + d < d || s[0].y * scale + scale + d > h + d)
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
			++score;
			level = 1 + score / 1;
			f[i].x = rand() % n; //
			f[i].y = rand() % m;
			len++;
			s[len - 1].x = -150;
			s[len - 1].y = -150;

		}
	}

}

void key()
{

}

int main()
{
	//шрифт

	sf::Font font;//шрифт 
	font.loadFromFile("pictures/CyrilicOld.TTF");//передаем нашему шрифту файл шрифта
	sf::Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	//text.setColor(sf::Color::Red);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый


	//headband
	Picture headband("headband.jpg", 0, 0, 0, 0, w + 2 * d, h + 2 * d + hscore);
	//start button
	Picture start_button("start.png", w / 3, h / 3 + score, 50, 50, (w + 2 * d) / 3.1, (h + 2 * d) / 4);
	start_button.Create_Mask(255, 255, 255, 255);
	//draw wall
	sf::RectangleShape wall(sf::Vector2f(w + 2*d, h + hscore + 2*d));
	wall.setFillColor(sf::Color(200, 50, 50));

	//draw field
	Picture field("field.jpg", d, hscore + d, 0, 0, w, h);
	//texture snake
	sf::Image snakeim;
	snakeim.loadFromFile("pictures/snake.jpg");
	sf::Texture snaketex;
	snaketex.loadFromImage(snakeim);
	//texture apple
	sf::Image appleim;
	appleim.loadFromFile("pictures/apple1.png");
	appleim.createMaskFromColor(sf::Color(255, 255, 255, 255), 0);
	sf::Texture appletex;
	appletex.loadFromImage(appleim);

	s[0].x = 15;
	s[0].y = 10;

	for (int i = 0; i < 6; ++i)
	{
		f[i].x = rand() % n;
		f[i].y = rand() % m;

	}

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(w+2 * d , h+2 * d + hscore), "snake", sf::Style::Default, settings);

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
			text.setPosition(0, hscore - d);
			window.draw(text);
			playerLevelString << level;
			text.setString("level:" + playerLevelString.str());
			text.setPosition(w/2, hscore - d);
			window.draw(text);

			//sf::RectangleShape field(sf::Vector2f(w, h));
			//draw snake
			if(flag > 0)
				tick();
			for (int i = 0; i < len; ++i)
			{

				sf::CircleShape shape(scale/2.f);
				shape.setPosition(d + s[i].x * scale, d + s[i].y * scale + hscore);
				shape.setTexture(&snaketex);
				shape.setTextureRect(sf::IntRect(100, 100, 200, 200));
				window.draw(shape);
				if (i < len - 1)
				{
					sf::CircleShape shape1(12.f);
					shape1.setPosition(d + (s[i].x + s[i + 1].x) / 2.0 * scale, d + (s[i].y + s[i + 1].y) / 2.0 * scale + hscore);
					shape1.setTexture(&snaketex);
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
				quad.setPosition(d + f[i].x * scale - scale * (k-1)/2, d + f[i].y * scale - scale*(k-1)/2 + hscore);
				quad.setTexture(&appletex);
				quad.setTextureRect(sf::IntRect(0, 0, 380, 380));
				window.draw(quad);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { dir = 3; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { dir = 1; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { dir = 2; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { dir = 4; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5)) { flag = 0; }
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
