#include "POINT.h"
#include <math.h>


float POINT::distance(POINT a)
{
    float dx = x - a.x, dy = y - a.y;
    return sqrt(dx * dx + dy * dy);
}

void POINT::init(float a, float b)
{
    x = a;
    y = b;
}
