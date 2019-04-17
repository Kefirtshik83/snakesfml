#include "Snake_1.h"
void Snake_1 :: control()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { dir = 3; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { dir = 1; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { dir = 2; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { dir = 4; }
}

Snake_1::Snake_1(): Snake(1, 2, 1, 18, "pictures/snake.jpg")
{

}