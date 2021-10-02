#include <math.h>
#include "CIRCLE.h"
#define PI 3.1415926535

int CIRCLE_init(CIRCLE* this_c, const POINT* center, float radius)
{
	if (this_c == NULL || center == NULL || radius <= 0) return 1;

	this_c->center = *center;
	this_c->radius = radius;
	return 0;
}

float CIRCLE_area(const CIRCLE* this_c)
{
	if (this_c == NULL) return -1;

	return PI * this_c->radius * this_c->radius;
}

float CIRCLE_circumference(const CIRCLE* this_c)
{
	if (this_c == NULL) return -1;

	return 2 * PI * this_c->radius;
}


