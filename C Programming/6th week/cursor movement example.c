#include <stdio.h>
#include <Windows.h>

void GotoXY(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		GotoXY(2 * i, i);
		printf("*");
	}
}
