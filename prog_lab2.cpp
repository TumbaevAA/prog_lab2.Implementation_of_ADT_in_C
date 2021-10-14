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
    printf("Point test\nEnter the coordinates of the first point: ");
    pointInput(&firstPoint);
    printf("\nEnter the coordinates of the second point: ");
    pointInput(&secondPoint);

    printf("\nThe coordinates of the first point: ");
    pointOutput(firstPoint);
    printf("\nThe coordinates of the second point: ");
    pointOutput(secondPoint);

    printf("\nDistance between points: %f", pointDistance(firstPoint, secondPoint));



    //Тест динамических Point
    Point* firstDynamicPoint = (Point*)malloc(sizeof(Point)) , * secondDynamicPoint = (Point*)malloc(sizeof(Point));
    printf("\n\n\nDynamic Point test\nEnter the coordinates of the first dynamic point: ");
    pointInput(firstDynamicPoint);
    printf("\nEnter the coordinates of the second dynamic point: ");
    pointInput(secondDynamicPoint);

    printf("\nThe coordinates of the first dynamic point: ");
    pointOutput(*firstDynamicPoint);
    printf("\nThe coordinates of the second dynamic point: ");
    pointOutput(*secondDynamicPoint);

    printf("\nDistance between dynamic points: %f", pointDistance(*firstDynamicPoint, *secondDynamicPoint));

    free(firstDynamicPoint);
    free(secondDynamicPoint);





    //Тест Line
    Line line;
    printf("\n\n\nLine test\nEnter the coordinates of the start and the end of the line: ");
    lineInput(&line);
    lineOutput(line);


    //Тест динамической Line
    Line* dynamicLine = (Line*)malloc(sizeof(Line));
    printf("\n\n\nDynamic line test\nEnter the coordinates of the start and the end of the dynamic line: ");
    lineInput(dynamicLine);
    lineOutput(*dynamicLine);
    free(dynamicLine);



    //Тест Triangle
    Triangle triangle;
    printf("\n\n\nTriangle test\nEnter the coordinates of the first, the second and the third points: ");
    triangleInput(&triangle);
    triangleOutput(triangle);

    //Тест Square
    Square square;
    printf("\n\n\nSquare test\nEnter the coordinates of the first, the second, the third and the fourth points: ");
    squareInput(&square);
    squareOutput(square);

    //Тест Circle
    Circle circle;
    printf("\n\n\nCircle test\nEnter the coordinates of the center and radius: ");
    circleInput(&circle);
    circleOutput(circle);
    
    return 0;
}


