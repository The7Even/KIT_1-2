#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define arrsize 20

void Reverse(int* arr, int size);
void Print(int* arr, int size);


int main(void) {
	srand(time(NULL));

	int arr[arrsize] = {0};

	for (int i = 0; i < arrsize; i++)
		arr[i] = rand() % 10 + 1;

	int* point = &arr;

	printf(" ");
	for (int i = 0; i < arrsize; i++)
		printf("[%2d] ", i);
	printf("\n");

	Print(point, arrsize);

	Reverse(point, arrsize);

	Print(point, arrsize);

	return 0;
}

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%4d ", arr[i]);
	printf("\n");
}

void Reverse(int* arr, int size)
{
	// 1 > 10, 2 > 9, 3 > 8, 4 > 7, 5 > 6 으로 이동시켜야 함.
	int temp = 0;
	for (int i = 0; i < size/2; i++)
	{
		temp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = temp;
	}
}
