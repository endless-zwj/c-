#define _CRT_SECURE_NO_WARNINGS



Text 7
�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
���磺 ���룺5 �����5    ���룺10, �����55     ���룺2, �����1

#include <stdio.h>

int fab1(int n) //�ǵݹ�ʵ��쳲�����
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

int fab2(int n)   //�ݹ�ʵ��쳲���������
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