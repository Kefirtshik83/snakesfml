#include "Field.h"
Field::Field(int n, int m, int scale, int d, int h_field_for_score) : n(n), m(m), scale(scale), d(d), h_field_for_score(h_field_for_score)
{
	w = n * scale;
	h = m * scale;
}

int Field::get_scale()
{
	return scale;
}
int Field::get_d()
{
	return d;
}
int Field::get_w()
{
	return w;
}
int Field::get_h_field_for_score()
{
	return h_field_for_score;
}

int Field::get_h()
{
	return h;
}
int Field::get_n()
{
	return n;
}
int Field::get_m()
{
	return m;
}