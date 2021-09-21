#pragma once
#include "POINT.h"
#include "LINE.h"

typedef struct TRIANGLE
{
	POINT first_point, second_point, third_point;
	LINE first_line, second_line, third_line;

};

int TRIANGLE_init(TRIANGLE* this_t, POINT* first_p, POINT* second_p, POINT* third_p);

