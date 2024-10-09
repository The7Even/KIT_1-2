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
void ResultProcess(void);

int Num1 = 0; // 위치 변경용 전역변수 4개
int Num2 = 0;
int Num3 = 0;
int Num4 = 0;

int pos1 = 0; int pos2 = 0; int pos3 = 0; int pos4 = 0; // 현재 위치 저장용 (아직 배열 안배워서 그냥 변수로 때움)
int current_grade = 1; // 등수 부여용 변수
int fin1 = 0; int fin2 = 0; int fin3 = 0; int fin4 = 0; // 골인 확인용 변수

int money = 500;
int selected = 0;
int FirstRank = 0;
int bet = 0;
int bestrecord = 500;

int main(void)
{
	int broken = 0;

	srand(time(NULL)); // 랜덤 시드 부여
	system("mode CON COLS=110 LINES=30"); // 화면 크기 조정

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
		DrawLine(); // 결승선 그리기 (x=100에 길이 15의 결승선)
		GotoXY(0, 16);
		if (money == 0)
		{
			printf("도박장은 거지를 받아줄 수 없습니다.\n");
			printf("최고 보유 금액 : %d원\n", bestrecord);
			printf("GAME OVER\n");
			for (int i = 0; i < 7; i++)
				printf("                                                                          \n");

			GotoXY(0, 20);
			break;
		}

		printf("보유한 금액 : %d\n", money);

		while (1)
		{
			GotoXY(0, 17);
			printf("선수를 선택하여 주십시오. >>>");
			scanf_s("%d", &selected);
			if (selected <= 4 && selected >= 1)
				break;
			else
			{
				printf("잘못된 입력입니다.");
				GotoXY(0, 17);
				printf("                                                                          ");
			}
		}
		
		while (1)
		{
			GotoXY(0, 18);
			printf("                                                                          ");
			GotoXY(0, 18);
			printf("얼마를 베팅하시겠습니까? >>>");
			scanf_s("%d", &bet);
			GotoXY(0, 19);
			printf("                                                                          ");
			GotoXY(0, 19);
			if (bet > money)
			{
				printf("가진 돈 보다 더 많이 베팅하실 수 없습니다.\n");
			}
			else if (bet <= 0)
			{
				printf("잘못된 입력입니다.\n");
			}
			else
			{
				money -= bet;
				break;
			}
		}

		while (1)
		{
			if (_kbhit())
			{
				int detect = _getch(); // ESC 감지용 조건절
				if (detect == 27)
				{
					GotoXY(0, 16);
					printf("ESC 입력을 감지했습니다. 종료합니다.");
					broken = 1;
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

		if (broken == 1)
			break;

		ResultProcess();
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
		GotoXY(0, 25 + current_grade);
		printf(">>> %d등 : 1번 선수", current_grade);
		current_grade++;
		fin1 = 1;
	}
	else if (pos2 >= 100 && fin2 == 0)
	{
		GotoXY(0, 25 + current_grade);
		printf(">>> %d등 : 2번 선수", current_grade);
		current_grade++;
		fin2 = 1;
	}
	if (pos3 >= 100 && fin3 == 0)
	{
		GotoXY(0, 25 + current_grade);
		printf(">>> %d등 : 3번 선수", current_grade);
		current_grade++;
		fin3 = 1;
	}
	if (pos4 >= 100 && fin4 == 0)
	{
		GotoXY(0, 25 + current_grade);
		printf(">>> %d등 : 4번 선수", current_grade);
		current_grade++;
		fin4 = 1;
	}
	if (FirstRank == 0)
	{
		if (fin1 + fin2 + fin3 + fin4 == 1)
		{
			if (fin1 == 1)
				FirstRank = 1;
			else if (fin2 == 1)
				FirstRank = 2;
			else if (fin3 == 1)
				FirstRank = 3;
			else if (fin4 == 1)
				FirstRank = 4;
		}
	}
}

void ResultProcess(void)
{
	GotoXY(40, 0);
	printf("                                                                          ");
	GotoXY(40, 0);
	if (FirstRank == selected)
	{
		money += bet * 4;
		printf("1위를 적중하셨습니다.\n");
		if (bestrecord < money)
			bestrecord = money;
	}
	else
	{
		printf("1위를 맞추지 못하였습니다.\n");
	}
	FirstRank = 0;
	fin1 = 0; fin2 = 0; fin3 = 0; fin4 = 0;
	current_grade = 1;

	GotoXY(pos1, 3);
	printf(" ");
	pos1 = 0;
	GotoXY(pos1, 3);
	printf("1");
	GotoXY(pos2, 6);
	printf(" ");
	pos2 = 0;
	GotoXY(pos2, 6);
	printf("2");
	GotoXY(pos3, 9);
	printf(" ");
	pos3 = 0;
	GotoXY(pos3, 9);
	printf("3");
	GotoXY(pos4, 12);
	printf(" ");
	pos4 = 0;
	GotoXY(pos4, 12);
	printf("4");

	GotoXY(0, 16);
	printf("                                                                          ");
	GotoXY(0, 17);
	printf("                                                                          ");
	GotoXY(0, 18);
	printf("                                                                          ");
}
