#include "Fruit.h"

Fruit::Fruit()
{
	for (int i = 0; i < 6; ++i)
	{
		f.push_back({ rand(), rand() });
	}
}