#include <iostream>
#include "LINE.h"


int LINE_init(LINE* this_l, const POINT* start_p, const POINT* end_p)
{
	if (start_p->x == end_p->x && start_p->y == end_p->y || this_l == NULL || start_p == NULL || end_p == NULL) return 1;

	this_l->start_point = *start_p;
	this_l->end_point = *end_p;
	this_l->lenght = POINT_distance(&(this_l->start_point), &(this_l->end_point));

	return 0;		
}

int LINE_is_point_on_line(const LINE* this_l, const POINT* p)
{
	if (this_l == NULL || p == NULL) return -1;

	if (POINT_distance(&(this_l->start_point), p) + POINT_distance(p, &(this_l->end_point)) == this_l->lenght) return 1;
	else return 0;
}