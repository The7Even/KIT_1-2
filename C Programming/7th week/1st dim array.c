#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    int arr[100];

    printf("{");
    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand() % 11 + 10;
        printf("%d", arr[i]);
        if (i != 99)
            printf(", ");
    }
    printf("}\n");

    int sum = 0;
    for (int i = 0; i < 100; i++)
        sum += arr[i];

    printf("Sum : %d", sum);

    return 0;
}
