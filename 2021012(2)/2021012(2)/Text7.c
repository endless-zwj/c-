#define _CRT_SECURE_NO_WARNINGS



Text 7
递归和非递归分别实现求第n个斐波那契数
例如： 输入：5 输出：5    输入：10, 输出：55     输入：2, 输出：1

#include <stdio.h>

int fab1(int n) //非递归实现斐波那契
{
	int f1 = 1;
	int f2 = 1;
	int f3 = 0;
	if (n == 1)
		return f1;
	else if (n == 2)
		return f2;
	else
	{
		for (int i = 3; i <= n; i++)
		{
			f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
		}
	}
	return f3;
}

int fab2(int n)   //递归实现斐波那契数列
{
	if (n == 1 || n == 2)
		return 1;
	else
		return fab2(n - 1) + fab2(n - 2);
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int ret1 = fab1(n);
		int ret2 = fab2(n);
		printf("%d %d\n", ret1, ret2);
	}
	return 0;
}