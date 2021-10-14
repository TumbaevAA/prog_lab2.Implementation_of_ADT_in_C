#pragma once
#include "Point.h"

typedef struct Square
{
	Point firstPoint, secondPoint, thirdPoint, fourthPoint;
};

bool squareInit(Square* square, Point first, Point second, Point third, Point fourth);

bool squareInput(Square* square);

bool squareOutput(Square square);

float squareLineLength(Square square);

float squarePerimeter(Square square);

float squareArea(Square square);