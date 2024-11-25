#include <stdio.h>

typedef int INT;
typedef int* PTR_INT;

typedef unsigned int UINT;
typedef unsigned int* PTR_UINT;

typedef unsigned char UCHAR;
typedef unsigned char* PTR_UCHAR;

typedef struct Point
{
	int xpos;
	int ypos;
} Point;

typedef struct Circle
{
	Point cen;
	double rad;
} Circle;

void ShowPosition(Point pos)
{
	printf("[%d, %d]\n", pos.xpos, pos.ypos);
}

Point GetCurrentPosition(void)
{
	Point cen;
	printf("좌표 입력 >>> ");
	scanf_s("%d,%d", &cen.xpos, &cen.ypos);
	return cen;
}

void Transformation(Point* ptr)
{
	ptr->xpos = (ptr->xpos) * (-1);
	ptr->ypos = (ptr->ypos) * (-1);
}

Point AddPoint(Point pos1, Point pos2)
{
	Point newpoint = { pos1.xpos + pos2.xpos , pos1.ypos + pos2.ypos };
	return newpoint;
}

int main(void)
{
	INT num1 = 120;
	PTR_INT pnum1 = &num1;

	UINT num2 = 190;
	PTR_UINT pnum2 = &num2;

	UCHAR ch = 'Z';
	PTR_UCHAR pch = &ch;

	printf("%d, %u, %c\n", *pnum1, *pnum2, *pch);

	Point curpos = GetCurrentPosition();
	ShowPosition(curpos);

	Point pos = { 7, -5 };
	Transformation(&pos);
	ShowPosition(pos);
	Transformation(&pos);
	ShowPosition(pos);

	Point pos1 = { 7,5 };
	Point pos2 = { 4,9 };
	Point pos3 = AddPoint(pos1, pos2);
	ShowPosition(pos3);

	Circle cir1 = { {4,5}, 5.5 };
}
