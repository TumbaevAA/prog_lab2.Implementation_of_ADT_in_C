#pragma once
#include "Point.h"

typedef struct Triangle
{
	Point firstPoint, secondPoint, thirdPoint;              
};

bool triangleInit(Triangle* triangle, Point first,Point second, Point third);

bool triangleInput(Triangle* triangle);

bool triangleOutput(Triangle triangle);

float triangleLineLength(Triangle triangle, int lineNumber);

float trianglePerimeter(Triangle triangle);

float triangleArea(Triangle triangle);
