#pragma once
typedef struct POINT
{
	float x, y;
};

void POINT_init(POINT* p, float x, float b);    //���������� ������������� ��������� �����
float POINT_distance(POINT* this_p, POINT* p);      //���������� ���������� �� ������ ����� � ������������
