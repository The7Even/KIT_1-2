#include <stdio.h>
#define PI 3.14159 // C언어에서 이 #define구문은 많이 쓰일 예정 (13주차에 알려주신다네요)

int main(void)
{
	const int MAX = 4; // 이 const 키워드 붙은 변수는 일명 심볼릭 상수이다. 그 옆에 있는 '4' 얘는 리터럴 상수이고.
	// MAX++; << 이러면 이제 오류남
	// PI--; << 이거도
	printf("%f\n", PI);

	int num1 = 129; // 00000000 00000000 00000000 10000001 (10진수로 129였는데..?)
	char ch1 = num1; // 10000001 (상위 3바이트 손실, 10진수로 -127로 출력됨. 128을 표현하는 1이 음을 표현하는 1이 되어버림..)

	int num2 = 3.1415; // 뭐야 int라면서요 왜 소수있어
	printf("%d\n", num2); // 정수형으로 지정해주었기에 출력값은 3

	short num3 = 4; short num4 = 5;
	short num5 = num3 + num4; // 변수의 값으로 sizeof ( num3 + num4 )를 입력하면 num5에는 4가 저장됨.

	int num6 = 3; int num7 = 4;
	double div_result;

	div_result = num6 / num7; // 여기서 div_result를 확인해보면 0.000000으로 나오게 된다..
	printf("나눗셈의 결과는 0.75인줄 아셨겠지만 %f 입니다.\n", div_result);

	div_result = (double)num6 / num7; // num6앞이던 num7앞이던 두 군데중 한군데라도 (double)을 붙여주기만 하면 double형 + int형 연산이라 double로 정상 반환된다.
	printf("하지만 이번에는 %f입니다.\n", div_result);

	printf("말을 전하고 싶다면?\n\"이렇게 전하세요\"\n");  
	/*
	그 외 특문들
	\a 경고음 출력하기
	\b 백스페이스 입력?
	\f 폼 피드?
	\n 줄넘김
	\r 캐리지 리턴??
	\t 수평 탭
	\v 수직 탭
	\' 작은따옴표 출력
	\" 큰따옴표 출력
	\? 물음표 출력
	\\ 백슬래쉬 출력
	*/

	// printf 부분 수업 필기 자료

	/*
	* 알아두면 매우 좋은거
	%d(char, short, int)
	%o(unsigned int, 8진수)
	%x(unsigned int, 16진수)
	%f(float double, 일반 실수)
	%e(float, double, 5e17과 같이 표기)
	%g (%f, %e중에서 알아서 골라서 적어줌)
	%c(char, short, int > letter)
	%s(char > string) 
	*/
	int num8 = 7; int num9 = 13;
	printf("%o > %#o\n", num1, num1); // 7 > 07
	printf("%x > %#x\n", num2, num2); // D > 0xD

	float num10 = 0.01234; double num11 = 0.0123456789;
	printf("%f / %e\n", num10, num10);
	printf("%.0f / %.3f / %f / %.10f\n", num11, num11, num11, num11); // 기본값은 6자리까지, 선택가능.

	printf("%-12s | %12s", "왼쪽정렬", "오른쪽정렬\n"); // -이면 왼쪽정렬, +이면 오른쪽정렬, 한글은 글자당 2칸씩 잡아먹는다고 한다 숫자랑 영어는 1칸씩.
	printf("%5.2f\n", num10); // 복합사용 가능, 정수부는 칸수정렬, 소수부는 소수 표기 설정. 

	// scanf 부분 수업 필기 자료

	// scanf_s("%d", &num9); < 제일 기초 구문
	// 주의할것! scanf로 double형 자료를 받으려면 %f가 아니라 %lf로 받아야한다. 출력할때는 다시 %f로 해도 되지만
	// e표기법으로도 입력이 가능하다. 5e4를 입력하면 50000이 입력되는 것처럼..

	// scanf_s("%d %d %d", &num7, &num8, &num9); << 입력할때 "4 5 6"로 입력하면 됨.
	// scanf_s("%d#%d#%d", &num7, &num8, &num9); << 입력할때 "4#5#6"로 입력하면 됨.
}
