#define _CRT_SECURE_NO_WARNINGS



Text 5
дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19

#include <stdio.h>

int DigitSum(int n)
{
	if (n / 10 == 0)
		return n;
	else
		return  n % 10 + DigitSum(n / 10);
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int ret = DigitSum(n);
		printf("%d", ret);
	}
	return 0;
}
