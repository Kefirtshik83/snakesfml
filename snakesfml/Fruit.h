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
private:
	std::vector <fr> f;
public:
	Fruit();
	fr get_f(int i);
	void set_f( int i, int x, int y);
	void set_name_f(int i, std::string s);
	std::string get_name_f(int i);
};