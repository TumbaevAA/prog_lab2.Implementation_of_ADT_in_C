#pragma once
#include "POINT.h"

typedef struct LINE
{
	POINT start_point, end_point;
	float lenght;
};

int LINE_init(LINE* this_l, const POINT* start_p, const POINT* end_p);
int LINE_is_point_on_line(const LINE* this_l, const POINT* p);



