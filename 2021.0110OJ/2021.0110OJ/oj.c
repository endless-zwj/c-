#define _CRT_SECURE_NO_WARNINGS

//OJ 1
//����һ���������У�KiKi������е��ظ�������ȥ��������ȥ�غ�����д�С�������������
//�������� :
//��һ�У�����һ������n����ʾ������n��������
//�ڶ�������n��������ÿ���������ڵ���1��С�ڵ���1000��������֮���ÿո�ָ���
//������� :
//ȥ�ز��Ҵ�С�������е��������У�����֮���ÿո�ָ���

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