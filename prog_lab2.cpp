#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <malloc.h>
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Square.h"
#include "Circle.h"


int main()
{
    //Тест Point
    Point firstPoint, secondPoint;
    printf("Enter the coordinates of the first point: ");
    pointInput(&firstPoint);
    printf("\nEnter the coordinates of the second point: ");
    pointInput(&secondPoint);

    printf("\nThe coordinates of the first point: ");
    pointOutput(firstPoint);
    printf("\nThe coordinates of the second point: ");
    pointOutput(secondPoint);

    printf("\nDistance between points: %f", pointDistance(firstPoint, secondPoint));


    //Тест Line
    Line line;
    printf("\n\n\nEnter the coordinates of the start and the end of the line: ");
    lineInput(&line);
    lineOutput(line);

    //Тест Triangle
    Triangle triangle;
    printf("\n\n\nEnter the coordinates of the first, the second and the third points: ");
    triangleInput(&triangle);
    triangleOutput(triangle);

    //Тест Square
    Square square;
    printf("\n\n\nEnter the coordinates of the first, the second, the third and the fourth points: ");
    squareInput(&square);
    squareOutput(square);

    //Тест Circle
    Circle circle;
    printf("\n\n\nEnter the coordinates of the center and radius: ");
    circleInput(&circle);
    circleOutput(circle);
    
    return 0;
}


