#include <stdio.h>
#include <math.h>

void PointMinMax(int** min, int** max, int arr[])
{
	int mini = arr[0]; int maxi = arr[0];
	*min = *max = arr;

	for (int i = 0; i < 5; i++)
	{
		if (mini > arr[i])
		{
			mini = arr[i];
			*min = &arr[i];
		}
		if (maxi < arr[i])
		{
			*max = &arr[i];
			maxi = arr[i];
		}
	}
}

void Traverse(int (*ary)[2], int len)
{
	printf("<%d, %d>\n", ary[0][0], ary[0][1]);
	int done[5] = { 0 };
	float mindis;
	int curpos = 0;
	float totaldis = 0;
	int check = 0;
	int finpos = 0;

	for (int i = 1; i < len; i++) // 1번도시 default, 다시 돌아오는건 별개로.
	{
		mindis = 999;
		for (int j = 1; j < len; j++)
		{
			if (mindis > sqrt(pow((double)(ary[curpos][0]) - ary[j][0], 2.00) + pow((double)(ary[curpos][1] - ary[j][1]), 2.00)))
			{
				check = 0;
				for (int k = 0; k < 5; k++)
				{
					if (done[k] != j)
						check++;
				}
				if (check == 5)
				{
					finpos = j;
					mindis = sqrt(pow((double)(ary[curpos][0]) - ary[j][0], 2.00) + pow((double)(ary[curpos][1] - ary[j][1]), 2.00));
				}
			}
		}
		done[i] = finpos;
		curpos = done[i];
		printf("<%d, %d>\n", ary[curpos][0], ary[curpos][1]);
		totaldis += mindis;
	}

	printf("<%d, %d>\n", ary[0][0], ary[0][1]);
	totaldis += sqrt(pow((double)(ary[curpos][0]) - ary[0][0], 2.00) + pow((double)(ary[curpos][1] - ary[0][1]), 2.00));

	printf("Distance you totally moved : %f\n", totaldis);
}

void Question1(void)
{
	int ary[5] = { 1,6,3,9,4 };
	int* min = NULL;
	int* max = NULL;

	PointMinMax(&min, &max, ary);

	printf("min : %d\nmax : %d\n", *min, *max);
}

void Question2(void)
{
	int ary[5][2] = { { 1,2 }, { 8,2 }, { 2,3 }, { 2,4 }, { 5,5 } };
	Traverse(ary, 5);
}

int main(void)
{
	int qwarp = 0;
	printf("Question No. ");
	scanf_s("%d", &qwarp);

	switch (qwarp)
	{
	case 1:
		Question1();
		break;
	case 2:
		Question2();
		break;
	}
}
