#pragma once
typedef struct POINT
{
	float x, y;
};

void POINT_init(POINT* p, float x, float b);    //ѕрисвоение опеределенных координат точке
float POINT_distance(POINT* this_p, POINT* p);      //¬ычисление рассто€ни€ от данной точки к передаваемой
