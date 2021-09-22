#pragma once
#include "POINT.h"

typedef struct LINE
{
	POINT first_point, second_point;
	float lenght;
};

int LINE_init(LINE* this_l, const POINT* first_p, const POINT* second_p);



int LINE_is_point_on_line(const LINE* this_l, const POINT* p);
