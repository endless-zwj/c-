#define _CRT_SECURE_NO_WARNINGS


Text 2
递归和非递归分别实现求n的阶乘（不考虑溢出的问题）
#include <stdio.h>

int func1(int n)    //非递归实现打印阶乘
{
	int ret = 1;
	for (int i = 1; i <= n; i++)
	{
		ret *= i;
	}
	return  ret;
}

int func2(int n)  // 递归实现打印阶乘
{
	if (n == 1)
		return 1;
	else
		return n * func2(n - 1);
}

int main()
{
	int n;
	scanf("%d", &n);
	int ret1 = func1(n);
	int ret2 = func2(n);
	printf("%d %d\n", ret1, ret2);
	return 0;

}