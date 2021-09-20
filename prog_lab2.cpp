#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "POINT.h"
#include "LINE.h"

int main()
{
    //Тест POINT
    POINT first_point, second_point;
    POINT_construct(&first_point, 1, 1);
    POINT_construct(&second_point, 2, 2);
    float lenght = POINT_distance(first_point, second_point);

    //Тест динамических POINT
    POINT* first_dynamic_point = new POINT, * second_dynamic_point = new POINT;
    POINT_construct(first_dynamic_point, 1, 1);
    POINT_construct(second_dynamic_point, 2, 2);
    lenght = 0;
    lenght = POINT_distance(*first_dynamic_point, *second_dynamic_point);

    //Тест LINE
    LINE first_line, second_line;
    LINE_construct(&first_line, first_point, second_point);
    LINE_construct(&second_line, *first_dynamic_point, *second_dynamic_point);

    //Тест динамических LINE
    LINE* first_dynamic_line = new LINE, * second_dynamic_line = new LINE;
    LINE_construct(first_dynamic_line, first_point, second_point);
    LINE_construct(second_dynamic_line, *first_dynamic_point, *second_dynamic_point);

   //Уничтожение динамических POINT и LINE
    POINT_destruct(first_dynamic_point);
    POINT_destruct(second_dynamic_point);
    LINE_destruct(first_dynamic_line);
    LINE_destruct(second_dynamic_line);




    return 0;
}

