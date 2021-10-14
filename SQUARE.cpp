#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Square.h"

bool squareInit(Square* square, Point first, Point second, Point third, Point fourth){
    if (square == NULL || &first == NULL || &second == NULL || &third == NULL || &fourth == NULL) return 1;

    float d1 = pointDistance(first, second), d2 = pointDistance(second, third), d3 = pointDistance(third, fourth), d4 = pointDistance(fourth, first);
    
    if (d1 == 0 || d2 == 0 || d3 == 0 || d4 == 0 ||                                           //≈сли какие-то точки совпадают, возвращаем false
        pointDistance(first, third) == 0 || pointDistance(second, fourth) == 0 ||

        d1 != d2 || d1 != d3 || d1 != d4 || d2 != d3 || d2 != d4 || d3 != d4){                //≈сли стороны не равны, возвращаем false
        return false;
    }
    
    square->firstPoint = first;
    square->secondPoint = second;
    square->thirdPoint = third;
    square->fourthPoint= fourth;
   
    return true;
}

bool squareInput(Square* square){
    if (square == NULL) return false;

    Point first, second, third, fourth;
    if (scanf("%f%f%f%f%f%f%f%f", &first.x, &first.y, &second.x, &second.y, &third.x, &third.y, &fourth.x, &fourth.y) != 8) return false;

    return squareInit(square, first, second, third, fourth);
}

bool squareOutput(Square square){
    if (&square == NULL) return false;

    printf("Square\n----------------------------------------------");
    printf("\nThe points");
    printf("\nfirst:");
    pointOutput(square.firstPoint);
    printf("\nsecond:");
    pointOutput(square.secondPoint);
    printf("\nthird:");
    pointOutput(square.thirdPoint);
    printf("\nfourth:");
    pointOutput(square.fourthPoint);


    printf("\n\nThe line lenght: %f", squareLineLength(square));

    printf("\n\nPerimeter = %f", squarePerimeter(square));
    printf("\n\Area = %f", squareArea(square));
    printf("\n----------------------------------------------");

    return true;
}

float squareLineLength(Square square){
    if (&square == NULL) return -1;

    return pointDistance(square.firstPoint, square.secondPoint);
}



float squarePerimeter(Square square){
    if (&square == NULL) return -1;

    return squareLineLength(square)*4;
}

float squareArea(Square square){
    if (&square == NULL)  return -1;

    return squareLineLength(square) * squareLineLength(square);
}


