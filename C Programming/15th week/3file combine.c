/* num.c */
int num = 0;

/* main.c */
#include <stdio.h>

int GetNum(void);
void increment(void); // main.c >> func.c

int main(void)
{
	printf("num : %d\n", GetNum());
	increment();
	printf("num : %d\n", GetNum());
}

/* func.c */
extern int num; // func.c > num.c

void increment(void)
{
	num++;
}

int GetNum(void)
{
	return num;
}
