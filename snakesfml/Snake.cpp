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
