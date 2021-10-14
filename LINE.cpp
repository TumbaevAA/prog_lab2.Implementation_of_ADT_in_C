#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Line.h"


bool lineInit(Line* line, Point start, Point end){
	if (start.x == end.x && start.y == end.y || line == NULL || &start == NULL || &end == NULL) return false;

	line->startPoint = start;
	line->endPoint = end;
	return true;		
}

bool lineInput(Line* line){
	if (line == NULL) return false;

	Point start, end;
	if (scanf("%f%f%f%f", &start.x, &start.y, &end.x, &end.y) != 4) return false;

	

	return lineInit(line, start, end);
}

bool lineOutput(Line line)
{
	if (&line == NULL) return false;

	printf("The start of the line: ");
	pointOutput(line.startPoint);
	printf("\nThe end of the line: ");
	pointOutput(line.endPoint);

	printf("\nThe length of the line: %f", lineLength(line));


	return true;
}



float lineLength(Line line) {
	if (&line == NULL) return -1;

	return pointDistance(line.startPoint, line.endPoint);
}

bool lineIsPointOnLine(Line line, Point point){
	if (&line == NULL || &point == NULL) return false;

	if (pointDistance(line.startPoint, point) + pointDistance(point, line.startPoint) == lineLength(line)) return true; //Если точка на линии, возвращаем true
	else return false;                                                                                                  //Иначе false
}

