#include <stdio.h>
#include <math.h>

int main(void)
{
	int select = 0;
	printf("몇번 문제의 소스코드를 실행합니까? >>>");
	scanf_s("%d", &select);

	if (select == 1) {
		int num1 = 0, num2 = 0;
		printf("두 정수를 @/@ 형식으로 입력하십시오. >>>");
		scanf_s("%d/%d", &num1, &num2);

		printf("\n----------------------------------------------------\n");
		printf("%3d + %-3d = %-10d\n", num1, num2, num1 + num2);
		printf("%3d - %-3d = %-10d\n", num1, num2, num1 - num2);
		printf("%3d * %-3d = %-10d\n", num1, num2, num1 * num2);
		printf("%3d / %-3d = %-10f\n", num1, num2, (double)num1 / num2);

		printf("----------------------------------------------------\n");
	}
	if (select == 2) {
		double num3 = 0; int num4 = 0;

		printf("실수 하나를 입력하십시오. >>>");
		scanf_s("%lf", &num3);
		printf("\n몇번째 자리까지 표기합니까? >>>");
		scanf_s("%d", &num4);

		double originalnum = num3;
		num3 = num3 * pow(10, num4);
		num3 = num3 + 0.5;
		int num5 = num3;
		double result = num5 / pow(10, num4);

		printf("\n%f를 %d번째 자리에서 반올림하면 %f입니다.", originalnum, num4 + 1, result);
		
	}
	return 0;
}
