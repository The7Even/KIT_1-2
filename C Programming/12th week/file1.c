#include <stdio.h>
#include <stdlib.h>

int StrLen(const char* str);

int main(void)
{
	char str[100];
	gets(str, sizeof(str), stdin);

	printf("입력받은 문자열의 길이 : %d\n", StrLen(str));
	return 0;
}

int StrLen(const char* str)
{
	int len = 0;
	for (int i = 0; i < 100; i++)
	{
		if (str[i] == '\0')
			return len;
		else
			len++;
	}
}
