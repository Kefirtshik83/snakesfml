#include "Field.h"
Field::Field(int n, int m, int scale, int d, int h_field_for_score) : n(n), m(m), scale(scale), d(d), h_field_for_score(h_field_for_score)
{
	w = n * scale;
	h = m * scale;
}