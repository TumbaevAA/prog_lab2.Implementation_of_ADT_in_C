#pragma once
typedef struct POINT
{
	float x, y;
};

void POINT_construct(POINT* p, float x, float y);
int POINT_destruct(POINT* p);     //Нужно ли указывать в названии, что деструктор только
								 //для динамических переменных?


float POINT_distance(POINT this_p, POINT end_p);
