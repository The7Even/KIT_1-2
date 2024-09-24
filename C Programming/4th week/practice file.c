#include <stdio.h>

int main(void)
{
	int sel = 0;
	printf("문제 번호를 입력해주세요. \n>>>");
	scanf_s("%d", &sel);
	if (sel == 1) { // 문제번호 1 >> 특정 범위 구구단 출력
		int num1 = 0;
		int num2 = 0;

		printf("정수 두개를 입력하세요. \n>>>");
		scanf_s("%d %d", &num1, &num2);

		printf("---------------------------\n");
		if (num1 == 0 || num2 == 0) { // 둘 중 하나라도 0인 경우 - 프로그램 종료
			printf("program shutting down (inputed 0)\n");
			printf("---------------------------\n");
		}
		else if (num1 < num2) { // 작은수 / 큰수 입력시 대응 (정방향 출력)
			for (int dan = num1; dan <= num2; dan++) {
				for (int time = 1; time <= 9; time++) {
					printf("%d × %d = %d\n", dan, time, dan * time);
				}
				printf("---------------------------\n");
			}
		}
		else if (num1 > num2) { // 큰수 / 작은수 입력시 대응 (역방향 출력)
			for (int dan = num1; dan >= num2; dan--) {
				for (int time = 1; time <= 9; time++) {
					printf("%d × %d = %d\n", dan, time, dan * time);
				}
				printf("---------------------------\n");
			}
		}
		else if (num1 == num2) { // 서로 같은수 입력시 대응
			int dan = num1;
			for (int time = 1; time <= 9; time++) {
				printf("%d × %d = %d\n", dan, time, dan * time);
			}
			printf("---------------------------\n");
		}
	}
	else if (sel == 2) { // 문제번호 2 >> * 피라미드 출력
		int num3 = 0;
		printf("정수 하나를 입력하세요. \n>>>");
		scanf_s("%d", &num3);

		printf("\n");

		for (int trial = 1; trial <= num3; trial++) { 
			for (int count = 0; count < num3 - trial; count++) // 선행 빈칸 출력
				printf(" ");
			for (int count = 0; count < 1 + 2 * (trial - 1); count++) // * 문자 출력
				printf("*");
			printf("\n");
		}
	}
}

/* 2번문제 관련 알고리즘 구상
	- line 47 >> inputed 5 (set)
	- trial = 1 > 4 blank + 1 letter + 4 blank 
	- trial = 2 > 3 blank + 3 letter + 3 blank
	- trial = 3 > 2 blank + 5 letter + 2 blank
	...
	- trial = n > 5-n blank + 1+2(n-1) letter + 5-n blank
*/
