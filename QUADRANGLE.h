#pragma once
#include "POINT.h"
#include "LINE.h"

typedef struct QUADRANGLE
{
	POINT first_point, second_point, third_point, fourth_point;
	LINE first_line, second_line, third_line, fourth_line;
};


int QUADRANGLE_init(QUADRANGLE* this_q, const POINT* first_p, const POINT* second_p, const POINT* third_p, const POINT* fourth_p);
float QUADRANGLE_perimeter(const QUADRANGLE* this_q);


