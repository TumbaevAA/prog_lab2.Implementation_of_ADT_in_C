#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <malloc.h>
#include "POINT.h"
#include "LINE.h"
#include "TRIANGLE.h"
#include "SQUARE.h"


int main()
{
    //Тест POINT
    POINT first_point, second_point;
    POINT_init(&first_point, 0, 0);
    POINT_init(&second_point, 0, 1);
    float lenght = POINT_distance(&first_point, &second_point);



    //Тест динамических POINT
    POINT* first_dynamic_point = (POINT*)malloc(sizeof(POINT)), * second_dynamic_point = (POINT*)malloc(sizeof(POINT));
    POINT_init(first_dynamic_point, 0, 0);
    POINT_init(second_dynamic_point, 0, 1);

    lenght = 0;
    lenght = POINT_distance(first_dynamic_point, second_dynamic_point);


    //Тест LINE
    LINE line, line_dynamic_points;
    LINE_init(&line, &first_point, &second_point);
    LINE_init(&line_dynamic_points, first_dynamic_point, second_dynamic_point);

    POINT third_point;
    POINT_init(&third_point, 1, 1);
    int is_point_on_line = LINE_is_point_on_line(&line, &third_point);

    POINT on_line_point;
    POINT_init(&on_line_point, 0, 0.5);
    is_point_on_line = LINE_is_point_on_line(&line, &on_line_point);



    //Тест динамических LINE
    LINE* dynamic_line = (LINE*)malloc(sizeof(LINE)), * dynamic_line_dynamic_points = (LINE*)malloc(sizeof(LINE));
    LINE_init(dynamic_line, &first_point, &second_point);
    LINE_init(dynamic_line_dynamic_points, first_dynamic_point, second_dynamic_point);
    free(first_dynamic_point);
    free(second_dynamic_point);
    free(dynamic_line);
    free(dynamic_line_dynamic_points);




    //Тест TRIANGLE
    TRIANGLE triangle;
    TRIANGLE_init(&triangle, &first_point, &second_point, &third_point);
    float T_perimeter = TRIANGLE_perimeter(&triangle);
    float T_area = TRIANGLE_area(&triangle);


    //Тест динамического TRIANGLE
    TRIANGLE* dynamic_triangle = (TRIANGLE*)malloc(sizeof(TRIANGLE));
    TRIANGLE_init(dynamic_triangle, &first_point, &second_point, &third_point);
    T_perimeter = 0;
    T_perimeter = TRIANGLE_perimeter(dynamic_triangle); 
    T_area = 0;
    T_area = TRIANGLE_area(dynamic_triangle);
    free(dynamic_triangle);

    //Тест SQUARE
    POINT fourth_point;
    POINT_init(&fourth_point, 1, 0);
    SQUARE square;
    SQUARE_init(&square, &first_point, &second_point, &third_point, &fourth_point);
    float S_perimeter = SQUARE_perimeter(&square);
    float S_area = SQUARE_area(&square);

    //Тест динамического SQUARE
    SQUARE* dynamic_square = (SQUARE*)malloc(sizeof(SQUARE));
    SQUARE_init(dynamic_square, &first_point, &second_point, &third_point, &fourth_point);
    S_perimeter = 0;
    S_perimeter = SQUARE_perimeter(dynamic_square);
    S_area = 0;
    S_area = SQUARE_area(dynamic_square);








    return 0;
}

