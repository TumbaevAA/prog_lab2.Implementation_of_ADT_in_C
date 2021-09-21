#include <iostream>
#include "LINE.h"


int LINE_init(LINE* this_l, POINT* first_p, POINT* second_p)
{
	if (first_p->x == second_p->x && first_p->y == second_p->y || this_l == NULL || first_p == NULL || second_p == NULL) return 1;

	this_l->first_point = *first_p;
	this_l->second_point = *second_p;
	this_l->lenght = POINT_distance(&(this_l->first_point), &(this_l->second_point));

	return 0;
		
}

int LINE_is_point_on_line(LINE* this_l, POINT* p)
{
	if (this_l == NULL || p == NULL) return -1;    //Надо ли возвращать -1 в других при NULL?

	if (POINT_distance(&(this_l->first_point), p) + POINT_distance(p, &(this_l->second_point)) == this_l->lenght) return 1;
	else return 0;
}
