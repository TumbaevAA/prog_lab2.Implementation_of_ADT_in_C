#pragma once
#include "Point.h"

typedef struct Line
{
	Point startPoint, endPoint;
};

bool lineInit(Line* line, Point start, Point end); 

bool lineInput(Line* line);

bool lineOutput(Line line);

float lineLength(Line line);

bool lineIsPointOnLine(Line line, Point point); 





