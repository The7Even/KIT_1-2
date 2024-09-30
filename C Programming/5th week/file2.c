#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int wincount = 0;
int losecount = 0;
int drawcount = 0;
int playtime = 1;

int InputUser(void)
{
	int select = 0;
	printf("----------------------------------------------\n");
	printf("%d회차 게임을 시작합니다.\n",playtime);
	printf("가위(1) / 바위(2) / 보(3) / 중단(0) \n>>>");
	scanf_s("%d", &select);
	return select;
}

int InputCom(void)
{
	srand(time(NULL));
	int num = rand() % 3;
	return num;
}

int DecideWinner(int num1, int num2)
{
	if (num1 == 1)
		printf("플레이어는 가위를 냈습니다.\n");
	else if (num1 == 2)
		printf("플레이어는 바위를 냈습니다.\n");
	else
		printf("플레이어는 보를 냈습니다.\n");
	if (num2 == 0)
		printf("컴퓨터는 가위를 냈습니다.\n");
	else if (num2 == 1)
		printf("컴퓨터는 바위를 냈습니다.\n");
	else
		printf("컴퓨터는 보를 냈습니다.\n");

	if (num1 - num2 == 1)
	{
		printf("비겼습니다.\n");
		drawcount++;
	}
	else if (num1 - num2 == 3 || num1 == num2)
	{
		printf("졌습니다.\n");
		losecount++;
	}
	else
	{
		printf("이겼습니다.\n");
		wincount++;
	}
	playtime++;
}

int PrintResult(void)
{
	printf("----------------------------------------------\n");
	printf("승리 횟수 : %d\n무승부 횟수 : %d\n패배 횟수 : %d", wincount, drawcount, losecount);
}

int main(void)
{
	while (1)
	{
		int usersel = InputUser();
		int comsel = InputCom();

		if (usersel <= 0)
			break;
		else if (usersel > 3)
		{
			printf("잘못된 입력입니다.\n");
			continue;
		}

		DecideWinner(usersel, comsel);
	}

	PrintResult();
	return 0;
}
