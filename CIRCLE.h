#pragma once
#include "POINT.h"
typedef struct CIRCLE
{
	POINT center;
	float radius;

};

int CIRCLE_init(CIRCLE* this_c, const POINT* center, float radius);
float CIRCLE_area(const CIRCLE* this_c);
float CIRCLE_circumference(const CIRCLE* this_c);
