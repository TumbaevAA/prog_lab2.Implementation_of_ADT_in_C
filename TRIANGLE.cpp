#include <iostream>
#include "TRIANGLE.h"

int TRIANGLE_init(TRIANGLE* this_t, POINT* first_p, POINT* second_p, POINT* third_p)
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
