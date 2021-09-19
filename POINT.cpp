#include "POINT.h"
#include <math.h>



void POINT_init(POINT * this_p, float x, float y)
{
    this_p->x = x;
    this_p->y = y;
}

float POINT_distance(POINT* this_p, POINT* p)
{
    float dx = this_p->x - p->x, dy = this_p->y - p->y;
    return sqrt(dx * dx + dy * dy);
}
