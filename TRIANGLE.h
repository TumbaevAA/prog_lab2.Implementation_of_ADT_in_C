#pragma once
#include "POINT.h"
#include "LINE.h"

typedef struct TRIANGLE
{
	POINT first_point, second_point, third_point;
	LINE first_line, second_line, third_line;

};

int TRIANGLE_init(TRIANGLE* this_t, const POINT* first_p, const POINT* second_p, const POINT* third_p);
float TRIANGLE_perimeter(const TRIANGLE* this_t);
float TRIANGLE_area(const TRIANGLE* this_t);
