#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

#define KEY_ESC 27

void GotoXY(int x, int y);
void DrawLine(void);
void MoveGen(void);
void MakeMove(void);
void FinishDetect(void);

int Num1 = 0; // 위치 변경용 전역변수 4개
int Num2 = 0;
int Num3 = 0;
int Num4 = 0;

int pos1 = 0; int pos2 = 0; int pos3 = 0; int pos4 = 0; // 현재 위치 저장용 (아직 배열 안배워서 그냥 변수로 때움)
int current_grade = 1; // 등수 부여용 변수
int fin1 = 0; int fin2 = 0; int fin3 = 0; int fin4 = 0; // 골인 확인용 변수

int main(void)
{
	srand(time(NULL)); // 랜덤 시드 부여
	system("mode CON COLS=110 LINES=25"); // 화면 크기 조정
	DrawLine(); // 결승선 그리기 (x=100에 길이 15의 결승선)

	GotoXY(0, 3);
	printf("1");
	GotoXY(0, 6);
	printf("2");
	GotoXY(0, 9);
	printf("3");
	GotoXY(0, 12);
	printf("4"); // 플레이어 1~4 소환

	while (1)
	{
		if (_kbhit())
		{
			int detect = _getch(); // ESC 감지용 조건절
			if (detect == 27)
			{
				GotoXY(0, 16);
				printf("ESC 입력을 감지했습니다. 종료합니다.");
				break;
			}
		}

		clock_t current_clock = clock(); // 시간 측정용 (현재 값)

		if (current_clock % 500 == 0) // 0.5초마다 작동
		{
			MoveGen();
			MakeMove();
			FinishDetect();

			if (current_grade == 5)
				break;
		}
	}
}

void GotoXY(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void DrawLine(void)
{
	for (int i = 0; i < 15; i++)
	{
		GotoXY(100, i);
		printf("|");
	}
}

void MoveGen(void)
{
	int distance = 0;

	distance = rand() % 3 + 1; // 0~2 >> 1~3으로 변경
	Num1 = distance;
	distance = rand() % 3 + 1;
	Num2 = distance;
	distance = rand() % 3 + 1;
	Num3 = distance;
	distance = rand() % 3 + 1;
	Num4 = distance;
}

void MakeMove(void)
{
	if (fin1 == 0)
	{
		GotoXY(pos1, 3);
		printf(" ");
		pos1 += Num1;
		GotoXY(pos1, 3);
		printf("1");
	}
	if (fin2 == 0)
	{
		GotoXY(pos2, 6);
		printf(" ");
		pos2 += Num2;
		GotoXY(pos2, 6);
		printf("2");
	}
	if (fin3 == 0)
	{
		GotoXY(pos3, 9);
		printf(" ");
		pos3 += Num3;
		GotoXY(pos3, 9);
		printf("3");
	}
	if (fin4 == 0)
	{
		GotoXY(pos4, 12);
		printf(" ");
		pos4 += Num4;
		GotoXY(pos4, 12);
		printf("4");
	}
}

void FinishDetect(void)
{
	if (pos1 >= 100 && fin1 == 0)
	{
		GotoXY(0, 15+current_grade);
		printf(">>> %d등 : 1번 선수", current_grade);
		current_grade++;
		fin1 = 1;
	}
	else if (pos2 >= 100 && fin2 == 0)
	{
		GotoXY(0, 15 + current_grade);
		printf(">>> %d등 : 2번 선수", current_grade);
		current_grade++;
		fin2 = 1;
	}
	if (pos3 >= 100 && fin3 == 0)
	{
		GotoXY(0, 15 + current_grade);
		printf(">>> %d등 : 3번 선수", current_grade);
		current_grade++;
		fin3 = 1;
	}
	if (pos4 >= 100 && fin4 == 0)
	{
		GotoXY(0, 15 + current_grade);
		printf(">>> %d등 : 4번 선수", current_grade);
		current_grade++;
		fin4 = 1;
	}
}
