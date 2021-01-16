#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, i, j;
	while (scanf("%d", &a) != EOF)
	{
		for (i = a + 1; i >= 1; i--)
		{
			for (j = i; j >= 1; j--)
			{
				printf("* ");
			}
			printf("\n");
		}
		for (i = 2; i <= a + 1; i++)
		{
			for (j = 1; j <= i; j++)
			{
				printf("* ");
			}
			printf("\n");
		}
	}
	return 0;
}
