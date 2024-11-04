#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>

int main(void)
{
	double a = 1;
	double e = 0;
	int chemical_e = 0;
	double dummy_e = 0;

	printf("1B = 1.000e9 (1,000,000,000)\n");
	for (unsigned long long x = 0; x < 10000000000; x++)
	{
		a *= 2;
		if (a >= 10)
		{
			a /= 10;
			e++;
		}

		if ((x + 1) % 100000000 == 0)
		{
			dummy_e = e;
			chemical_e = 0;
			while (dummy_e >= 10)
			{
				dummy_e /= 10;
				chemical_e++;
			}
			printf("2^%.1fB = %.3fe(%.3fe%d)\n", (double)(x + 1) / 1000000000, a, e / pow(10, chemical_e), chemical_e);
		}
	}
}
