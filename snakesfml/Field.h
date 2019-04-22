#pragma once
#include "Picture.h"
class Field
{
public:
	Field(int n = 25, int m = 50, int scale = 24, int d = 20, int h_field_for_score = 60);
	int get_scale();
	int get_d();
	int get_w();
	int get_h_field_for_score();
	int get_h();
	int get_n();
	int get_m();
private:
	int n, m;
	int scale;
	int d;
	int w;
	int h_field_for_score;
	//int score = 0;
	int h;
};