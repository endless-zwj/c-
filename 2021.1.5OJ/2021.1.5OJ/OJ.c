#define _CRT_SECURE_NO_WARNINGS
//OJ 1
//#include <stdio.h>
//int main()
//{
//	int i, j;
//	int n, m;   //n�� m��
//	int arr[10][10];
//	int a, b;   //��ָ���������л���
//	int k;     //��������
//	char t;    //ִ�в����ж�
//	scanf("%d%d", &m, &n);
//	for (i = 0; i<n; i++)
//	{
//		for (j = 0; j<m; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	scanf("%d", &k);
//
//	while (k--)
//	{
//		int swap = 0;  //����ý��
//		scanf(" %c %d %d", &t, &a, &b);
//		if (t == 'r')//�н��� ��ֵ��ͬ
//		for (i = 0; i<m; i++)
//		{
//			swap = arr[a - 1][i];
//			arr[a - 1][i] = arr[b - 1][i];
//			arr[b - 1][i] = swap;
//		}
//		else if (t == 'c')//�н��� ��ֵ��ͬ
//		for (i = 0; i<n; i++)
//		{
//			swap = arr[i][a - 1];
//			arr[i][a - 1] = arr[i][b - 1];
//			arr[i][b - 1] = swap;
//		}
//	}
//
//	for (i = 0; i<n; i++)
//	{
//		for (j = 0; j<m; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

#include <stdio.h>
int main()
{
	int i, j,c;
	int n, m;   //n�� m��
	int arr[10][10];
	int a, b;   //��ָ���������л���
	int k;     //��������
	char t;    //ִ�в����ж�
	int swap = 0;  //����ý��
	scanf("%d%d", &m, &n);
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	scanf("%d", &k);

	for (i = 0; i<k; i++)
	{
		getchar();
		scanf("%c %d %d", &t, &a, &b);//scanf��Ŀո����ջ������Ŀո�

		if (t == 'r')//�н��� ��ֵ��ͬ
		{
			for (j = 0; j<m; j++)
			{
				swap = arr[a - 1][j];
				arr[a - 1][j] = arr[b - 1][j];
				arr[b - 1][j] = swap;
			}
		}

		else if (t == 'c')//�н��� ��ֵ��ͬ
		{
			for (c = 0; c<n; c++)
			{
				swap = arr[c][a - 1];
				arr[c][a - 1] = arr[c][b - 1];
				arr[c][b - 1] = swap;
			}
		}
	}

	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

