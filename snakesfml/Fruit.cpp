#include "Fruit.h"

Fruit::Fruit() : apple("apple1.png", 0, 0, 0, 0, 1200, 1200),
pear("pear.png", 0, 0, 0, 0, 1200, 1200)
{
	for (int i = 0; i < 6; ++i)
	{
		f.push_back({ rand(), rand(), "apple" });
	}
	f[5].name_f = "pear";
	f[4].name_f = "pear";
	f[3].name_f = "pear";
}

fr Fruit::get_f(int i)
{
	return f[i];
}

void Fruit::set_f(int i, int x, int y)
{
	f[i].x = x;
	f[i].y = y;
}

void Fruit::set_name_f(int i, std::string s)
{
	f[i].name_f = s;
}

void Fruit::Set_Scale(int scale)
{
	apple.Set_Scale((float)scale/1200* 1.5, (float)scale / 1200 * 1.5);
	pear.Set_Scale((float)scale / 1200 * 1.5, (float)scale / 1200 * 1.5);
}

std::string Fruit::get_name_f(int i)
{
	return f[i].name_f;
}

sf::Sprite Fruit::get_sprite(int i, int x, int y)
{
	if (f[i].name_f == "apple")
	{
		apple.Set_Position(x, y);
		return apple.get_sprite();
	}
	if (f[i].name_f == "pear")
	{
		pear.Set_Position(x, y);
		return pear.get_sprite();
	}
}