#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	int arr[3][5];
	int i, j;
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			arr[i][j] = rand() % 10 + 1;
		}
	}

	printf("<<< 3행 5열의 배열 >>>\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	int max[3] = { 0 };

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (max[i] < arr[i][j])
				max[i] = arr[i][j];
		}
	}

	printf("\n<<< 각 행의 최대값 출력하기 >>>\n");
	for (i = 0; i < 3; i++)
		printf("%d행의 최대값 : %d\n", i + 1, max[i]);
}
