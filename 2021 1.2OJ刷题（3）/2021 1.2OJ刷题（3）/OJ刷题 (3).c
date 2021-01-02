#define _CRT_SECURE_NO_WARNINGS
//OJ 1
#include<stdio.h>
int main()
{
	int i, j, M, N, arr[100][100];
	int sum = 0;
	scanf("%d %d", &M, &N);
	for (i = 0; i<M; i++)
	{
		for (j = 0; j<N; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j]>0)
				sum += arr[i][j];
		}
	}
	printf("%d", sum);
	return 0;
}

//OJ 2
#include <stdio.h>
int main()
{
	int i, a[10];
	for (i = 0; i<10; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 9; i >= 0; i--)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
