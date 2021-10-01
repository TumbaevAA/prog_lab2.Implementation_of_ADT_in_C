#pragma once
#include "POINT.h"
#include "LINE.h"

typedef struct ANGLE
{
	float degree;
	POINT main_point, first_ray_point, second_ray_point;
};

int ANGLE_init(ANGLE* this_a, const POINT* main_p, const POINT* first_ray_p, const POINT* second_ray_p);

