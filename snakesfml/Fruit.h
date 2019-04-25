#pragma once
#include <vector>
#include <string>
#include "point.h"
#include "Picture.h"

struct fr
{
	int x, y;
	std::string name_f;
};

class Fruit
{
private:
	std::vector <fr> f;
	Picture apple;
	Picture pear;
public:
	Fruit();
	void Set_Scale(int scale);
	sf::Sprite get_sprite(int i, int x, int y);
	fr get_f(int i);
	void set_f( int i, int x, int y);
	void set_name_f(int i, std::string s);
	std::string get_name_f(int i);
};