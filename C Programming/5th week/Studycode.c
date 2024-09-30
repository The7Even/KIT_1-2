#include <stdio.h>
int globalnum = 0; // 전역변수 선언
extern int number = 0; // 이거는 다른파일까지 영향을 주는 전역변수 선언이라는데 자세한건 13주차에서 만나볼 예정.

int addnumber();
int SimpleFunc();

int main(void)
{
	int a = 3; // main내 지역변수 선언
	int b = 4;

	{
		int b = 100; // 위에서 선언된 지역변수 b와는 다른 지역변수 b임.
		a++; b++; // 여기서 바뀐 b는 방금 선언된 지역변수 b
	}

	addnumber(a);
	printf("a = %d, b = %d\n", a, b);
	printf("static var = %d\n", globalnum);

	for (int i = 0; i < 3; i++)
	{
		SimpleFunc();
	}

	return 0;
}

int addnumber(int num1)
{
	globalnum += num1; // 따로 말 안해줘도 이미 전역변수기때문에 알아서 처리가능.
	return 0;
}

int SimpleFunc(void)
{
	static int num2 = 0; // 얘는 앞으로 다시 SimpleFunc 호출돼도 초기화 안당함
	int num3 = 0; // 얘는 초기화당함ㅋ

	num2++; num3++;
	printf("static num2 : %d\nnon-static num3 : %d\n",num2, num3);
}
