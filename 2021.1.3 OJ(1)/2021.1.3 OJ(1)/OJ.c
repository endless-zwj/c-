#define _CRT_SECURE_NO_WARNINGS
//OJ
#include <stdio.h>
int main()
{
	int i, j = 0, k = 0, positive[10], negative[10], a[10];
	for (i = 0; i<10; i++)
	{
		scanf("%d", &a[i]);
		if (a[i]>0)
		{
			positive[j] = a[i];
			j++;
		}
		if (a[i]<0)
		{
			negative[k] = a[i];
			k++;
		}
	}

	printf("positive:%d\n", j);
	printf("negative:%d", k);

	return 0;
}

//OJ 2
#include<stdio.h>
int main()
{
	int i, n, a[50], sum = 0;
	scanf("%d", &n);
	for (i = 0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i<n; i++)
	{
		sum += a[i];
	}
	printf("%d", sum);
	return 0;
}

//OJ 3
#include<stdio.h>
int main()
{
	int i, n, min, max, a[100];
	scanf("%d", &n);
	for (i = 0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	max = min = a[0];
	for (i = 0; i<n; i++)
	{
		if (a[i]<min)
			min = a[i];
		if (a[i]>max)
			max = a[i];
	}
	printf("%d", max - min);
	return 0;
}

//OJ 4

