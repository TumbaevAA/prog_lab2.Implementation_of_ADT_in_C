#include <iostream>
#include "QUADRANGLE.h"

int QUADRANGLE_init(QUADRANGLE* this_q, const POINT* first_p, const POINT* second_p, const POINT* third_p, const POINT* fourth_p)
{
    if (this_q == NULL || first_p == NULL || second_p == NULL || third_p == NULL || fourth_p==NULL) return 1;

    float d1 = POINT_distance(first_p, second_p), d2 = POINT_distance(second_p, third_p), d3 = POINT_distance(third_p, fourth_p), d4 = POINT_distance(fourth_p, first_p);
    if (d1 == 0 || d2 == 0 || d3 == 0 || d4 == 0 ||                     //Если какие-то точки совпадают, возвращаем 1
        d1 == d2 + d3 + d4 ||                                          //Если какая-то точка лежит на отрезке между двумя другими, возращаем 1
        d2 == d1 + d3 + d4 ||
        d3 == d1 + d2 + d4 ||
        d4 == d1 + d2 + d3)       
    {
        return 1;
    }

    this_q->first_point = *first_p;
    this_q->second_point = *second_p;
    this_q->third_point = *third_p;
    this_q->fourth_point = *fourth_p;

    LINE_init(&(this_q->first_line), &(this_q->first_point), &(this_q->second_point));
    LINE_init(&(this_q->second_line), &(this_q->second_point), &(this_q->third_point));
    LINE_init(&(this_q->third_line), &(this_q->third_point), &(this_q->fourth_point));
    LINE_init(&(this_q->third_line), &(this_q->fourth_point), &(this_q->first_point));

    return 0;
}

float QUADRANGLE_perimeter(const QUADRANGLE* this_q)
{
    if (this_q == NULL) return -1;
    return this_q->first_line.lenght + this_q->second_line.lenght + this_q->third_line.lenght + this_q->fourth_line.lenght;
}
