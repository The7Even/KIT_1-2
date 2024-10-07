#include <stdio.h>
#include <Windows.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;

	CONSOLE_CURSOR_INFO ci = { 100, TRUE }; // 커서 크기 100 & 커서 출력 여부 : 참 
	// 참고로 기본 설정값은 { 25, TRUE } 라는 점
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci); 

	printf("첫번째 정수 입력 : ");
	scanf_s("%d", &num1);

	ci.bVisible = FALSE; // 커서 크기 100 & 커서 출력 여부 : 거짓
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);

	printf("두번째 정수 입력 : ");
	scanf_s("%d", &num2);

	return 0;
}
