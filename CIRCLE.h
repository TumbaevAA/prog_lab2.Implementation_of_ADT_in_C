#pragma once
#include "Point.h"

typedef struct Circle
{
	Point center;
	float radius;
};

bool circleInit(Circle* circle, Point center, float radius);

bool circleInput(Circle* circle);

bool circleOutput(Circle circle);

float circleArea(Circle circle);

float circleCircumference(Circle circle);
