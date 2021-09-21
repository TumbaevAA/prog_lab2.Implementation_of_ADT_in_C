#include "POINT.h"
#include <math.h>


int POINT_init(POINT* this_p, float x, float y)
{
    if (this_p == NULL) return 1;

    this_p->x = x;
    this_p->y = y;

    return 0;
}


float POINT_distance(POINT* this_p, POINT* end_p)
{
    if (this_p == NULL || end_p == NULL) return -1;

    float dx = end_p->x - this_p->x, dy = end_p->y - this_p->y;
    return sqrt(dx * dx + dy * dy);
}
