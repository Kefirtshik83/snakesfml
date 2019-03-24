#include <SFML/Graphics.hpp>
#include <iostream>
int n = 50, m = 30;
int scale = 24;
int d = 20;
int w = scale * n;
int h = scale * m;
//1-right  2-up  3-left   4-down
int dir = 1, len = 5;
int flag = -1;
int i =  5;





sf::Clock cl;
sf::Time t = cl.getElapsedTime();



struct snake
{
	int x;
	int y;
};
struct snake s[600]; // s[0] - head

struct fruct
{
	int x;
	int y;
} f[6];

void tick()
{
	if (cl.getElapsedTime().asMicroseconds() - t.asMicroseconds() > 300000)
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
			}
		}
		if (s[0].x * scale + d < d || s[0].x * scale + scale + d > w + d || s[0].y * scale + d < d || s[0].y * scale + scale + d > h + d)
		{
			flag = -1;
			len = 2;
			s[0].x = 15;
			s[0].y = 10;
		}
	}

	for (int i = 0; i < 6; ++i)
	{
		if (s[0].x == f[i].x && s[0].y == f[i].y)
		{
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
	//headband
	sf::Image headband;
	headband.loadFromFile("pictures/headband.jpg");
	sf::Texture headtex;
	headtex.loadFromImage(headband);
	sf::Sprite headsprite;
	headsprite.setTexture(headtex);
	headsprite.setTextureRect(sf::IntRect(0, 0, w + 2 * d, h + 2 * d));
	//start button
	sf::Image startim;
	startim.loadFromFile("pictures/start.png");
	startim.createMaskFromColor(sf::Color(255, 255, 255, 255), 0);
	sf::Texture starttex;
	starttex.loadFromImage(startim);
	sf::Sprite startsprite;
	startsprite.setTexture(starttex);
	startsprite.setTextureRect(sf::IntRect(50, 50, (w + 2 * d)/3.1 , (h + 2 * d)/4));
	startsprite.setPosition(w/3, h/3);
	//draw wall
	sf::Image wallim;
	wallim.loadFromFile("pictures/wall.jpg");
	sf::Texture walltex;
	walltex.loadFromImage(wallim);
	sf::Sprite wallsprite;
	wallsprite.setTexture(walltex);
	wallsprite.setTextureRect(sf::IntRect(0, 0, w+2 * d, h + 2 * d));
	//draw field
	sf::Image fieldim;
	fieldim.loadFromFile("pictures/field.jpg");
	sf::Texture fieldtex;
	fieldtex.loadFromImage(fieldim);
	sf::Sprite fieldsprite;
	fieldsprite.setTexture(fieldtex);
	fieldsprite.setTextureRect(sf::IntRect(0, 0, w, h));
	fieldsprite.setPosition(d,d);
	//texture snake
	sf::Image snakeim;
	snakeim.loadFromFile("pictures/snake.jpg");
	sf::Texture snaketex;
	snaketex.loadFromImage(snakeim);

	s[0].x = 15;
	s[0].y = 10;

	for (int i = 0; i < 6; ++i)
	{
		f[i].x = rand() % n;
		f[i].y = rand() % m;

	}

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(w+2 * d, h+2 * d), "snake", sf::Style::Default, settings);

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		if (flag > 0)
		{
			window.draw(wallsprite);
			window.draw(fieldsprite);


			//sf::RectangleShape field(sf::Vector2f(w, h));
			//draw snake
			tick();
			for (int i = 0; i < len; ++i)
			{
				//sf::RectangleShape quad(sf::Vector2f(scale, scale));
				//quad.setPosition(d + s[i].x*scale, d + s[i].y * scale);
				//window.draw(quad);

				sf::CircleShape shape(scale/2.f);
				shape.setPosition(d + s[i].x * scale, d + s[i].y * scale);
				shape.setTexture(&snaketex);
				shape.setTextureRect(sf::IntRect(100, 100, 200, 200));
				window.draw(shape);
				if (i < len - 1)
				{
					sf::CircleShape shape1(12.f);
					shape1.setPosition(d + (s[i].x + s[i + 1].x) / 2.0 * scale, d + (s[i].y + s[i + 1].y) / 2.0 * scale);
					shape1.setTexture(&snaketex);
					shape1.setTextureRect(sf::IntRect(100, 100, 200, 200));
					window.draw(shape1);
				}
				//std:: cout << cl.getElapsedTime().asMilliseconds() << std::endl;
			}

			//draw fructs
			for (int i = 0; i < 6; ++i)
			{
				sf::RectangleShape quad(sf::Vector2f(scale, scale));
				quad.setPosition(d + f[i].x*scale, d + f[i].y * scale);
				window.draw(quad);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { dir = 3; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { dir = 1; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { dir = 2; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { dir = 4; }
		}
		else
		{

			window.draw(headsprite);


			window.draw(startsprite);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { flag += 1; }

		window.display();
	}

	return 0;
}
