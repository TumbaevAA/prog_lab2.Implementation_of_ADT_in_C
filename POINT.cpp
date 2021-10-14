#define _CRT_SECURE_NO_WARNINGS
#include "Point.h"
#include <math.h>
#include <iostream>


bool pointInit(Point* point, float x, float y){
    if (point == NULL) return false;

    point->x = x;
    point->y = y;

    return true;
}

bool pointInput(Point* point){
    if (point == NULL) return false;

    float x, y;
    if (scanf("%f%f", &x, &y) != 2) return false;


    return pointInit(point, x, y);
}

bool pointOutput(Point point)
{
    if (&point == NULL) return false;
    
    printf("x = %f, y = %f", point.x, point.y);

    return true;
}


float pointDistance(Point start, Point end){
    if (&start == NULL || &end == NULL) return -1;

    float d1 = end.x - start.x, d2 = end.y - start.y;
    return sqrt(d1 * d1 + d2 * d2);
}
