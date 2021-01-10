#define _CRT_SECURE_NO_WARNINGS

//OJ 1
//给定一个整数序列，KiKi想把其中的重复的整数去掉，并将去重后的序列从小到达排序输出。
//输入描述 :
//第一行，输入一个整数n，表示序列有n个整数。
//第二行输入n个整数（每个整数大于等于1，小于等于1000），整数之间用空格分隔。
//输出描述 :
//去重并且从小到大排列的整数序列，整数之间用空格分隔。

#include<stdio.h>
int main()
{
	int i, j, min, n, a[100], b[100];
	int temp, count = 0;
	scanf("%d", &n);
	for (i = 0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i<n - 1; i++)
	{
		min = a[i];

		for (j = i; j<n; j++)
		{
			if (a[j]<min)
			{
				temp = min;
				min = a[j];
				a[j] = temp;
			}
		}

		a[i] = min;
	}

	j = 0;
	b[j] = a[0];

	for (i = 1; i<n; i++)
	{
		if (b[j] != a[i])
		{
			b[++j] = a[i];
			count++;
		}
	}

	for (j = 0; j <= count; j++)
		printf("%d ", b[j]);
	return 0;
}