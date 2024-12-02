#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define PLAY_TIME 500

int main(void)
{
	FILE* fp = fopen("bestrec.txt", "r");

	int best = 0;
	fscanf_s(fp, "%d", &best);

	fclose(fp);

	srand(time(NULL));

	clock_t start = clock();

	int clientbest = 9999999;
	int bestrec = 0;
	int undercount = 0;
	int count = 0;
	int rep = 0;
	for (int i = 0; i < PLAY_TIME; i++)
	{
		count = 0;
		rep = 0;

		while (1)
		{
			count++;
			int num = rand();
			if (num > 32766)
			{
				rep++;
			}
			if (rep == 100)
				break;
		}

		if (count < 2500000)
			undercount++;

		if (best > count)
		{
			best = count;
			FILE *fp = fopen("bestrec.txt", "w");
			fprintf(fp, "%d", best);
		}

		if (clientbest > count)
		{
			clientbest = count;
			bestrec = i + 1;
		}
		system("cls");
		printf("%d", i + 1);

	}

	clock_t end = clock();

	printf(" times played.\n");
	printf("best : Try %d\n", best);
	printf("This process best : Try %d (%04d)\n", clientbest, bestrec);
	printf("Count of under Try 2.5M : %02d\n", undercount);
	printf("\ntime elapsed : %.3lf sec.\n", (double)(end - start) / CLOCKS_PER_SEC);
}
