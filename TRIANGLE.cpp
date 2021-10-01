#include <iostream>
#include "TRIANGLE.h"
#include <math.h>

int TRIANGLE_init(TRIANGLE* this_t, const POINT* first_p, const POINT* second_p, const POINT* third_p)
{
    if (this_t == NULL || first_p == NULL || second_p == NULL || third_p == NULL) return 1;

    float d1= POINT_distance(first_p, second_p), d2 = POINT_distance(second_p, third_p), d3 = POINT_distance(third_p, first_p);
    if (d1 == 0 || d2 == 0 || d3 == 0 ||                      //Если какие-то точки совпадают, возвращаем 1
        d1 == d2 + d3 || d2 == d1 + d3 || d3 == d1 + d2)      //Если какая-то точка лежит на отрезке между двумя другими, возращаем 1
    {
        return 1;
    }

    this_t->first_point = *first_p;
    this_t->second_point = *second_p;
    this_t->third_point = *third_p;

    
    LINE_init(&(this_t->first_line), &(this_t->first_point), &(this_t->second_point));
    LINE_init(&(this_t->second_line), &(this_t->second_point), &(this_t->third_point));
    LINE_init(&(this_t->third_line), &(this_t->third_point), &(this_t->first_point));


    return 0;
}

float TRIANGLE_perimeter(const TRIANGLE* this_t)
{
    if (this_t == NULL) return -1;
    return this_t->first_line.lenght + this_t->second_line.lenght + this_t->third_line.lenght;

}

float TRIANGLE_area(const TRIANGLE* this_t)
{
    if (this_t == NULL) return -1;

    float semi_per = TRIANGLE_perimeter(this_t) / 2;
    return  sqrtf(semi_per * (semi_per - this_t->first_line.lenght) * (semi_per - this_t->second_line.lenght) * (semi_per - this_t->third_line.lenght));
}
