#pragma once
#include "Picture.h"
class Field
{
public:
	Field(int n = 50, int m = 30, int scale = 24, int d = 20, int h_field_for_score = 60);
	int n, m;
	int scale;
	int d;
	int w;
	int h_field_for_score;
	//int score = 0;
	int h;
};