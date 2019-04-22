#include "Fruit.h"

Fruit::Fruit()
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

std::string Fruit::get_name_f(int i)
{
	return f[i].name_f;
}