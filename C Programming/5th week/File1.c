#include <stdio.h>

int GCD();
int min();

int main(void)
{
	int num1 = 0;
	int num2 = 0;

	printf("두개의 정수를 입력하세요. \n>>>");
	scanf_s("%d %d", &num1, &num2);

	int result = GCD(num1, num2);
	printf("두 수의 최대공약수는 %d입니다.\n",result);

	return 0;
}

int GCD(int num1, int num2)
{
	int minnum = min(num1, num2);

	while (minnum >= 1)
	{
		if (num1 % minnum == 0 && num2 % minnum == 0)
			return minnum;
		
		minnum--;
	}
}

int min(int num1, int num2)
{
	if (num1 >= num2)
		return num2;
	else
		return num1;
}
