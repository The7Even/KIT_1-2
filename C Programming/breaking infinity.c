#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>

int main(void)
{
	double a = 1;
	int e = 0;
	for (int x = 0; x < 100000; x++)
	{
		a *= 2;
		if (a >= 10)
		{
			a /= 10;
			e += 1;
		}

		if (x == 1023)
		{
			printf("2^1024 = inf\n");
			for (int i = 0; i < 3; i++)
			{
				Sleep(1000);
				printf(".");
			}
			Sleep(2000);
			printf("\nBreak Infinity!\n");
			Sleep(1500);
		}

		if (e > 3)
			printf("2^%d = %.3fe%d\n", x + 1, a, e); 
		else
			printf("2^%d = %.0f\n",x+1, a * pow(10, e));
	}
}

// 9.999e2147483647까지 저장하여 출력할 수 있음. (2147483648자리, 2^7,133,786,263까지 저장 가능.)
// e 변수를 int형이 아닌 long long으로 지정하여 실행할경우 9.999e9223372036854775807까지 출력 가능. (2^3.063e19까지 저장 가능)
