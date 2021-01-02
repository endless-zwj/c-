#define _CRT_SECURE_NO_WARNINGS

//OJ 1
#include <stdio.h>
int main()
{
	float a, b, c, d, e, aver;
	scanf("%f %f %f %f %f", &a, &b, &c, &d, &e);
	aver = (a + b + c + d + e) / 5;
	printf("%.2f", aver);
	return 0;
}


//OJ 2
#include <stdio.h>
int main()
{
	int M;
	scanf("%d", &M);
	if (M % 5 == 0)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}


//OJ 3
#include <stdio.h>
int main()
{
	int M;
	scanf("%d", &M);
	if (M<0)
		printf("1");
	else if (M == 0)
		printf("0");
	else
		printf("-1");
	return 0;
}

//OJ 4
#include <stdio.h>
int main()
{
	int M;
	scanf("%d", &M);
	if (M<0)
		printf("1");
	else if (M == 0)
		printf("0");
	else
		printf("-1");
	return 0;
}

//OJ 5
#include <stdio.h>
int main()
{
	int a[10];
	int i;
	for (i = 0; i<10; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i<10; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}

//OJ 6
#include<stdio.h>
int main()
{
	int i;
	int count = 0;
	for (i = 1; i <= 2019; i++)
	{
		int j = i;
		while (j)
		{
			if (j % 10 == 9)
			{
				count++;
				break;
			}
			j /= 10;
		}
	}
	printf("%d", count);
	return 0;
}

