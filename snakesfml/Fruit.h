#pragma once
#include <vector>
#include <string>
#include "point.h"

struct fr
{
	int x, y;
	std::string name_f;
};

class Fruit
{
public:
	std::vector <fr> f;
	Fruit();
};