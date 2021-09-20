#include <iostream>   //��������� �� ������ ��� ���������� ��� ������������� NULL?
#include "LINE.h"

int LINE_construct(LINE* this_l, POINT first_p, POINT second_p)
{
	if (first_p.x == second_p.x && first_p.y == second_p.y) return 1;

	else 
	{
		this_l->first_point = first_p;                      
		this_l->second_point = second_p;
		this_l->lenght = POINT_distance(first_p, second_p);   

		return 0;
	}
}

int LINE_destruct(LINE* this_l)
{
	if (this_l == NULL)  return 1;

	else
	{
		delete this_l;
		return 0;
	}
}
