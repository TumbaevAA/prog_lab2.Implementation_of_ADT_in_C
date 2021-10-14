#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Circle.h"
#define PI 3.1415926535

bool circleInit(Circle* circle, Point center, float radius){
	if (circle == NULL || &center == NULL || radius <= 0) return false;

	circle->center = center;
	circle->radius = radius;

	return true;
}

bool circleInput(Circle* circle){
	if (circle == NULL) return false;

	Point center;
	float radius;
	if (scanf("%f%f%f", &center.x, &center.y, &radius) != 3) return false;

	return circleInit(circle, center, radius);
}

bool circleOutput(Circle circle)
{
    if (&circle == NULL) return false;

    printf("Circle\n----------------------------------------------");
    printf("\nCenter: ");
    pointOutput(circle.center);
	printf("\nRadius = %f", circle.radius);

    printf("\n\Circumference = %f", circleCircumference(circle));
    printf("\n\Area = %f", circleArea(circle));
    printf("\n----------------------------------------------");

    return true;
}


float circleArea(Circle circle){
	if (&circle == NULL) return false;

	return PI * circle.radius * circle.radius;
}

float circleCircumference(Circle circle){
	if (&circle == NULL) return -1;

	return 2 * PI * circle.radius;
}


