#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <iostream>
#include "Triangle.h"


bool triangleInit(Triangle* triangle, Point first, Point second, Point third){
    if (triangle == NULL || &first == NULL || &second == NULL || &third == NULL) return false;

    float d1 = pointDistance(first, second), d2 = pointDistance(second, third), d3 = pointDistance(third, first);
    if (d1 == 0 || d2 == 0 || d3 == 0 ||                      //Если какие-то точки совпадают, возвращаем false
        d1 == d2 + d3 || d2 == d1 + d3 || d3 == d1 + d2){     //Если точка лежит на отрезке между двумя другими - false
        return false;
    }

    triangle->firstPoint = first;
    triangle->secondPoint = second;
    triangle->thirdPoint = third;

    return true;
}

bool triangleInput(Triangle* triangle){
    if (triangle == NULL) return false;

    Point first, second, third;
    if (scanf("%f%f%f%f%f%f", &first.x, &first.y, &second.x, &second.y, &third.x, &third.y) != 6) return false;



    return triangleInit(triangle, first, second, third);
}

bool triangleOutput(Triangle triangle){
    if (&triangle == NULL) return false;

    printf("Triangle\n----------------------------------------------");
    printf("\nThe points");
    printf("\nfirst:");
    pointOutput(triangle.firstPoint);
    printf("\nsecond:");
    pointOutput(triangle.secondPoint);
    printf("\nthird:");
    pointOutput(triangle.thirdPoint);

    printf("\n\nThe line lenghts");
    printf("\nfirst: %f", triangleLineLength(triangle, 1)); 
    printf("\nsecond: %f", triangleLineLength(triangle, 2));
    printf("\nthird: %f", triangleLineLength(triangle, 3));

    printf("\n\nPerimeter = %f", trianglePerimeter(triangle));
    printf("\n\Area = %f", triangleArea(triangle));
    printf("\n----------------------------------------------");

    return true;
}


float triangleLineLength(Triangle triangle, int lineNumber) {
    if (&triangle == NULL || lineNumber < 1 || lineNumber>3) return -1;

    switch (lineNumber){
    case 1:
        return pointDistance(triangle.firstPoint, triangle.secondPoint);
       break;

    case 2:
        return pointDistance(triangle.secondPoint, triangle.thirdPoint);
        break;

    case 3:
        return pointDistance(triangle.thirdPoint, triangle.firstPoint); 
        break;
    }
}


float trianglePerimeter(Triangle triangle)
{
    if (&triangle == NULL) return -1;

    float perimeter = 0;
    for (int i = 1; i < 4; i++) {
        perimeter += triangleLineLength(triangle, i);
    }

    return perimeter;
}

float triangleArea(Triangle triangle)
{
    if (&triangle == NULL) return -1;

    float semiPerimeter = trianglePerimeter(triangle)  / 2;
    return  sqrtf(semiPerimeter * (semiPerimeter - triangleLineLength(triangle, 1)) * (semiPerimeter - triangleLineLength(triangle,2)) * (semiPerimeter - triangleLineLength(triangle, 3))); //Формула Герона
}
