#define _CRT_SECURE_NO_WARNINGS
//OJ 1
#include<stdio.h>
int main()
{
	int i, j;
	char a[3][3];
	char flag = 'o';
	for (i = 0; i<3; i++)
	for (j = 0; j<3; j++)
	{
		a[i][j] = getchar();
		getchar();
	}
	for (i = 0; i<3; i++)
	{
		if (a[i][0] == a[i][1] && a[i][1] == a[i][2])//判断行
			flag = a[i][0];
		if (a[0][i] == a[1][i] && a[1][i] == a[2][i])
			flag = a[0][i];
	}
	if (a[0][0] == a[1][1] && a[1][1] == a[2][2])
		flag = a[0][0];
	if (a[0][2] == a[1][1] && a[1][1] == a[2][0])
		flag = a[0][2];
	if (flag == 'K')
		printf("KiKi wins!\n");
	else if (flag == 'B')
		printf("BoBo wins!\n");
	else
		printf("No winner!\n");

	return 0;
}

//OJ 2
#include <stdio.h>
int main()
{
	long n;
	long t = 1;   //权重数
	int x;
	long s = 0;
	scanf("%ld", &n);
	if (n<6)
		printf("%ld", n);
	else
	while (n)
	{
		int x = 0;
		x = n % 6;
		n /= 6;
		s = s + t*x;
		t *= 10;
	}
	printf("%ld", s);
	return 0;
}

//OJ 3
#include <stdio.h>
int main()
{
	long long n;
	long long i;
	scanf("%lld", &n);
	long long s = 0;
	for (i = 1; i <= n; i++)
		s += i;
	printf("%lld", s);
	return 0;
}