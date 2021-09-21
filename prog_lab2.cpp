#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "POINT.h"
#include "LINE.h"
#include "TRIANGLE.h"

int main()
{
    //Тест POINT
    POINT first_point, second_point;
    POINT_init(&first_point, 1, 1);
    POINT_init(&second_point, 2, 2);
    float lenght = POINT_distance(&first_point, &second_point);



    //Тест динамических POINT
    POINT* first_dynamic_point = new POINT, * second_dynamic_point = new POINT;
    POINT_init(first_dynamic_point, 1, 1);
    POINT_init(second_dynamic_point, 2, 2);

    lenght = 0;
    lenght = POINT_distance(first_dynamic_point, second_dynamic_point);



    //Тест LINE
    LINE line, line_dynamic_points;
    LINE_init(&line, &first_point, &second_point);
    LINE_init(&line_dynamic_points, first_dynamic_point, second_dynamic_point);

    POINT third_point;
    POINT_init(&third_point, 0, 3);
    int is_point_on_line = LINE_is_point_on_line(&line, &third_point);

    POINT on_line_point;
    POINT_init(&on_line_point, 1.5, 1.5);
    is_point_on_line = LINE_is_point_on_line(&line, &on_line_point);



    

    //Тест динамических LINE
    LINE* dynamic_line = new LINE, * dynamic_line_dynamic_points = new LINE;
    LINE_init(dynamic_line, &first_point, &second_point);
    LINE_init(dynamic_line_dynamic_points, first_dynamic_point, second_dynamic_point);


    //Тест TRIANGLE
    TRIANGLE triangle;
    TRIANGLE_init(&triangle, &first_point, &second_point, &third_point);


    return 0;
}

