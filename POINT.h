#pragma once
typedef struct POINT
{
	float x, y;
};

int POINT_init(POINT* this_p, float x, float y);

float POINT_distance( const POINT* this_p, const POINT*  end_p);
