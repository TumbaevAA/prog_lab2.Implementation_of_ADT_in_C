#include <iostream>
#include "SQUARE.h"

int SQUARE_init(SQUARE* this_s, const POINT* first_p, const POINT* second_p, const POINT* third_p, const POINT* fourth_p)
{
    if (this_s == NULL || first_p == NULL || second_p == NULL || third_p == NULL || fourth_p == NULL) return 1;

    float d1 = POINT_distance(first_p, second_p), d2 = POINT_distance(second_p, third_p), d3 = POINT_distance(third_p, fourth_p), d4 = POINT_distance(fourth_p, first_p);
    
    if (d1 == 0 || d2 == 0 || d3 == 0 || d4 == 0 ||                                           //≈сли какие-то точки совпадают, возвращаем 1
        POINT_distance(first_p, third_p) == 0 || POINT_distance(second_p, fourth_p) == 0 ||

        d1 != d2 || d1 != d3 || d1 != d4 || d2 != d3 || d2 != d4 || d3 != d4)                //≈сли стороны не равны, возвращаем 1
    {
        return 1;
    }
    
    this_s->first_point = *first_p;
    this_s->second_point = *second_p;
    this_s->third_point = *third_p;
    this_s->fourth_point = *fourth_p;

    LINE_init(&(this_s->first_line), &(this_s->first_point), &(this_s->second_point));
    LINE_init(&(this_s->first_line), &(this_s->second_point), &(this_s->third_point));
    LINE_init(&(this_s->first_line), &(this_s->third_point), &(this_s->fourth_point));
    LINE_init(&(this_s->first_line), &(this_s->fourth_point), &(this_s->first_point));
   
    return 0;
}

float SQUARE_perimeter(const SQUARE* this_s)
{
    if (this_s == NULL) return -1;

    return this_s->first_line.lenght * 4;
}

float SQUARE_area(const SQUARE* this_s)
{
    if (this_s == NULL)  return -1;

    return this_s->first_line.lenght * this_s->first_line.lenght;
}


