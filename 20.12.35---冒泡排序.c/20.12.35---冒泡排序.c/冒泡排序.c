#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 10
int main()
{
	int i, j, k, t, a[N];
	for (i = 0; i <= N - 1; i++)
		scanf("%d", &a[i]);
	for (i = 0; i <N - 1; i++)
	{
		k = i;
		for (j = i + 1; j < N; j++)//ÿ��ѭ�����ҵ�һ����С���������±긳��k
		   if (a[j] < a[k])
			   k = j;
		if (k !=i )//�ж�a[i]�Ƿ�Ϊ�ô�ѭ����С����
		   {
			   t = a[i];
			   a[i] = a[k];
			   a[k] = t;
		   }
	}
	for (i = 0; i <= N - 1; i++)
		printf("%5d", a[i]);
		printf("\n");
	return 0;
}

