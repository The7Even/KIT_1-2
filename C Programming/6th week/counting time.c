#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	double result = 0;
	clock_t current_clock;
	clock_t initial_clock = clock();

	printf("초기 clock : %d\n", initial_clock);

	for (int count = 0; count < 1000000000; count++)
		result += 0.0001;
	
	current_clock = clock();
	printf("종료 clock : %d\n", current_clock);

	printf("연산 결과 : %f\n", result);
	printf("실행 시간 : %.3f초\n", (double)(current_clock - initial_clock) / CLOCKS_PER_SEC);
}
