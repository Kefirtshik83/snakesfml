#include "Fruit.h"

Fruit::Fruit()
{
	for (int i = 0; i < 6; ++i)
	{
		f.push_back({ rand(), rand(), "pictures/apple1.png" });
	}
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