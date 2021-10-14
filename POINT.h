#pragma once
typedef struct Point
{
	float x, y;
};

bool pointInit(Point* point, float x, float y);

bool pointInput(Point* point);

bool pointOutput(Point point);

float pointDistance(Point start, Point end);