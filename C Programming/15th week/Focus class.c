#include <stdio.h>

#define A										int main(void)
#define AA											int a = 10;
#define AAA										for (int aa = 0 ; aa < a; aa++)
#define AAAA										for (int aaa = 0 ; aaa<aa+1; aaa++)
#define AAAAA											printf("A");
#define AAAAAA									printf("\n");
#define AAAAAAA								return 'A';

A
{
	AA;
	AAA
	{
		AAAA
			AAAAA;
		AAAAAA;
	}
	AAAAAAA;
}
