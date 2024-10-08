#include <stdio.h>
#include <math.h>

int main(void)
{
	int first_x = 0; int first_y = 0;
	int second_x = 0; int second_y = 0;

	double mdis = 0; double sdis = 0;

	while (1)
	{
		printf("*** 첫 번째 좌표 입력 : ");
		scanf_s("%d %d", &first_x, &first_y);

		printf("*** 두 번째 좌표 입력 : ");
		scanf_s("%d %d", &second_x, &second_y);

		if (first_x == 0 && second_x == 0 && first_y == 0 && second_y == 0)
			break;

		mdis = fabs((double)(first_x - second_x)) + fabs((double)(first_y - second_y));
		sdis = sqrt(pow((double)(first_x - second_x), 2) + pow((double)(first_y - second_y), 2));

		printf(">>> 맨해튼 거리 : %.2f\n", mdis);
		printf(">>> 직선 거리   : %.2f\n ", sdis);
	}
	printf("* 프로그램을 종료합니다 *\n");
}
