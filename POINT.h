#pragma once
typedef struct POINT
{
	float x, y;
};

void POINT_construct(POINT* p, float x, float b);    //���������� ��������� ����� (�����������)
int POINT_destruct(POINT* p);

float POINT_distance(POINT* this_p, POINT* p);      //���������� ���������� �� ������ ����� � ������������
