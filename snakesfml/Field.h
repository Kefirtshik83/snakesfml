#pragma once
#include "Picture.h"
class Field
{
public:
	int n = 50, m = 30;
	int scale = 24;
	int d = 20;
	int w = scale * n;
	int h_field_for_score = 60;
	int score = 0;
	int h = scale * m;
};