#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 10
int main()
{
	int i, j, k, t, a[N];
	for (i = 0; i <= N - 1; i++)
		scanf("%d", &a[i]);
	for (i = 0; i <N - 1; i++)
	{
		k = i;
		for (j = i + 1; j < N; j++)//每次循环都找到一个最小的数并把下标赋给k
		   if (a[j] < a[k])
			   k = j;
		if (k !=i )//判断a[i]是否为该次循环最小的数
		   {
			   t = a[i];
			   a[i] = a[k];
			   a[k] = t;
		   }
	}
	for (i = 0; i <= N - 1; i++)
		printf("%5d", a[i]);
		printf("\n");
	return 0;
}

