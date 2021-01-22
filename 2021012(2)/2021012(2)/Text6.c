#define _CRT_SECURE_NO_WARNINGS



Text 6
递归实现N的K次方

#include <stdio.h>

int My_pow(int k, int n)
{
	if (k == 1)
		return n;
	else
		return n*My_pow(k - 1, n);
}

int main()
{
	int n;
	int k;
	scanf("%d%d", &n, &k);
	int ret = My_pow(k, n);
	printf("%d\n", ret);
	return 0;
}
