#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int BinToInt(const char* str);

int main(void)
{
	char str[31];
	while (1)
	{
		printf("2진수 입력 : ");
		gets(str, sizeof(str), stdin);
		

		if (BinToInt(str) != 0)
			printf("10진수 변환 : %d\n", BinToInt(str));
		else
			break;
	}
}

int BinToInt(const char* str)
{
	int len = strlen(str);
	int total = 0;
	for (int i = 0; i < len; i++)
		total += str[len-i] * pow(2, i);
	return total;
}
