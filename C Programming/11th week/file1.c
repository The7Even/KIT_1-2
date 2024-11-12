#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Max(int* ary, int len)
{
	int maxi = 0;
	printf("생성된 배열 : [ ");
	for (int i = 0; i < len; i++)
	{
		if (i + 1 != len)
			printf("%d, ", ary[i]);
		else
			printf("%d", ary[i]);

		if (maxi < ary[i])
			maxi = ary[i];
	}
	printf(" ]\n");
	return maxi;
}

int main(void)
{
	srand(time(NULL));
	int* ary = NULL;
	int count = 0;

	// 동적 1차원 배열 만들기
	printf("몇개의 요소? >>>");
	scanf_s("%d", &count);

	ary = malloc(4 * count);
	for (int i = 0; i < count; i++)
		ary[i] = rand() % 100 + 1;

	int max = Max(ary, count);
	printf("최대값 : %d\n", max);
	free(ary);
}
