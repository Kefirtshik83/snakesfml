#include "Snake.h"


Snake::Snake(int dir, int len, int level, int y0, std::string ss) : dir(dir), len(len), level(level)
{
	for (int i = 0; i < len; ++i)
	{
		s.push_back({ 10, y0 + i });
	}
	image_s.loadFromFile(ss);
	texture_s.loadFromImage(image_s);
}

void Snake :: control()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { dir = 3; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { dir = 1; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { dir = 2; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { dir = 4; }
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5)) { flag = 0; }


}

int Snake:: get_level()
{
	return level;
}
int Snake::get_dir()
{
	return dir;
}
int Snake::get_len()
{
	return len;
}
int Snake :: get_score()
{
	return score;
}
void Snake::set_level(int x)
{
	level = x;
}
void Snake::set_dir(int x)
{
	dir = x;
}
void Snake::set_len(int x)
{
	len = x;
}
void Snake::set_score(int x)
{
	score = x;
}

void Snake :: resize_s(int x)
{
	s.resize(x);
}

point Snake::get_s(int i)
{
	return s[i];
}
void Snake :: set_s(int i, int x, int y)
{
	s[i].x = x;
	s[i].y = y;
}
std::vector <point> Snake::get_full_s()
{
	return s;
}

sf::Image Snake::get_image()
{
	return image_s;
}
sf::Texture* Snake::get_texture()
{
	sf::Texture * a = &texture_s;
	return a;
}

void Snake::s_x_plus(int i, int x)
{
	s[i].x += x;
}
void Snake::s_y_plus(int i, int x)
{
	s[i].y += x;
}
void Snake::s_push_back(int x, int y)
{
	point a;
	a.x = x;
	a.y = y;
	s.push_back(a);
}
