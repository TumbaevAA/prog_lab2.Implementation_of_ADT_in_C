#pragma once
#include "POINT.h"
#include "LINE.h"

typedef struct SQUARE
{
	POINT first_point, second_point, third_point, fourth_point;
	LINE first_line, second_line, third_line, fourth_line;
};

int SQUARE_init(SQUARE* this_s, const POINT* first_p, const POINT* second_p, const POINT* third_p, const POINT* fourth_p);

float SQUARE_perimeter(const SQUARE* this_s);
float SQUARE_area(const SQUARE* this_s);