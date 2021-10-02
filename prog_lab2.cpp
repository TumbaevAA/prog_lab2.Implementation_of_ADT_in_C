#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <malloc.h>
#include "POINT.h"
#include "LINE.h"
#include "TRIANGLE.h"
#include "SQUARE.h"
#include "CIRCLE.h"


int main()
{
    setlocale(LC_ALL, "ru");

    //Тест POINT
    POINT first_point, second_point;
    POINT_init(&first_point, 0, 0);
    POINT_init(&second_point, 0, 1);
    float lenght = POINT_distance(&first_point, &second_point);

    printf("Координаты first_point: x=%f, y=%f", first_point.x, first_point.y);
    printf("\nКоординаты second_point: x=%f, y=%f", second_point.x, second_point.y);
    printf("\nРасстояние между first_point и second_point: %f", lenght);

    //Тест динамических POINT
    POINT* first_dynamic_point = (POINT*)malloc(sizeof(POINT)), * second_dynamic_point = (POINT*)malloc(sizeof(POINT));
    POINT_init(first_dynamic_point, 0, 0);
    POINT_init(second_dynamic_point, 0, 1);

    lenght = 0;
    lenght = POINT_distance(first_dynamic_point, second_dynamic_point);

    printf("\n\nКоординаты first_dynamic_point: x=%f, y=%f", first_point.x, first_point.y);
    printf("\nКоординаты second_dynamic_point: x=%f, y=%f", second_point.x, second_point.y);
    printf("\nРасстояние между first_dynamic_point и second_dynamic_point: %f", lenght);


    //Тест LINE
    LINE line, line_dynamic_points;
    LINE_init(&line, &first_point, &second_point);
    LINE_init(&line_dynamic_points, first_dynamic_point, second_dynamic_point);
    
    printf("\n\nДлина line с начальной точкой first_point и конечной second_point:  %f", line.lenght);
    printf("\nДлина line c динамическими точками с начальной точкой first_dynamic_point (0,0) и конечной second_dynamic_point(0,1):  %f", line_dynamic_points.lenght);

    POINT third_point;
    POINT_init(&third_point, 1, 1);
    int is_point_on_line = LINE_is_point_on_line(&line, &third_point);

    printf("\nПроверка, находится ли точка third_point(1,1) на линии line. 1 - да, 0 - нет: %d ", is_point_on_line);

    POINT on_line_point;
    POINT_init(&on_line_point, 0, 0.5);
    is_point_on_line = LINE_is_point_on_line(&line, &on_line_point);

    printf("\nПроверка, находится ли точка on_line_point(0,0.5) на линии line. 1 - да, 0 - нет: %d ", is_point_on_line);



    //Тест динамических LINE
    LINE* dynamic_line = (LINE*)malloc(sizeof(LINE)), * dynamic_line_dynamic_points = (LINE*)malloc(sizeof(LINE));
    LINE_init(dynamic_line, &first_point, &second_point);
    LINE_init(dynamic_line_dynamic_points, first_dynamic_point, second_dynamic_point);

    printf("\n\nДлина динамической line с начальной точкой first_point и конечной second_point:  %f", dynamic_line->lenght);
    printf("\nДлина динамической line c динамическими точками с начальной точкой first_dynamic_point (0,0) и конечной second_dynamic_point(0,1):  %f", dynamic_line_dynamic_points->lenght);

    free(first_dynamic_point);
    free(second_dynamic_point);
    free(dynamic_line);
    free(dynamic_line_dynamic_points);




    //Тест TRIANGLE
    TRIANGLE triangle;
    TRIANGLE_init(&triangle, &first_point, &second_point, &third_point);
    float T_perimeter = TRIANGLE_perimeter(&triangle);
    float T_area = TRIANGLE_area(&triangle);

    printf("\n\nПериметр треугольника с точками first_poin, second_point, third_point: %f", T_perimeter);
    printf("\nПлощадь треугольника с точками first_poin, second_point, third_point: %f", T_area);


    //Тест динамического TRIANGLE
    TRIANGLE* dynamic_triangle = (TRIANGLE*)malloc(sizeof(TRIANGLE));
    TRIANGLE_init(dynamic_triangle, &first_point, &second_point, &third_point);
    T_perimeter = 0;
    T_perimeter = TRIANGLE_perimeter(dynamic_triangle); 
    T_area = 0;
    T_area = TRIANGLE_area(dynamic_triangle);
    printf("\n\nПериметр динамического треугольника с точками first_poin, second_point, third_point: %f", T_perimeter);
    printf("\nПлощадь динамического труегольника с точками first_poin, second_point, third_point: %f", T_area);

    free(dynamic_triangle);



    //Тест SQUARE
    POINT fourth_point;
    POINT_init(&fourth_point, 1, 0);
    SQUARE square;
    SQUARE_init(&square, &first_point, &second_point, &third_point, &fourth_point);
    float S_perimeter = SQUARE_perimeter(&square);
    float S_area = SQUARE_area(&square);

    printf("\n\nПериметр квадрата с точками first_poin, second_point, third_point, fourth_point(1,0): %f", S_perimeter);
    printf("\nПлощадь квадрата с точками first_poin, second_point, third_point, fourth_point: %f", S_area);



    //Тест динамического SQUARE
    SQUARE* dynamic_square = (SQUARE*)malloc(sizeof(SQUARE));
    SQUARE_init(dynamic_square, &first_point, &second_point, &third_point, &fourth_point);
    S_perimeter = 0;
    S_perimeter = SQUARE_perimeter(dynamic_square);
    S_area = 0;
    S_area = SQUARE_area(dynamic_square);

    printf("\n\nПериметр динамического квадрата с точками first_poin, second_point, third_point, fourth_point: %f", S_perimeter);
    printf("\nПлощадь динамического квадрата с точками first_poin, second_point, third_point, fourth_point: %f", S_area);

    free(dynamic_square);


    //Тест CIRCLE
    CIRCLE circle;
    CIRCLE_init(&circle, &first_point, 4);
    float C_area = CIRCLE_area(&circle);
    float C_circumference = CIRCLE_circumference(&circle);
    
    printf("\n\nПлощадь круга с центром в first_point и радиусом 4: %f", C_area);
    printf("\nДлина окружности круга с центром в first_point и радиусом 4: %f", C_circumference);




    //Тест динамическог CIRCLE
    CIRCLE* dynamic_circle = (CIRCLE*)malloc(sizeof(CIRCLE));
    CIRCLE_init(dynamic_circle, &first_point, 4);
    C_area = 0;
    C_area = CIRCLE_area(dynamic_circle);
    C_circumference = 0;
    C_circumference = CIRCLE_circumference(dynamic_circle);

    printf("\n\nПлощадь динамического круга с центром в first_point и радиусом 4: %f", C_area);
    printf("\nДлина окружности динамического круга с центром в first_point и радиусом 4: %f", C_circumference);


    free(dynamic_circle);

    
    
    return 0;
}

