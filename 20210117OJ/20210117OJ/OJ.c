#define _CRT_SECURE_NO_WARNINGS
//OJ 1   �������
//#include <stdio.h>
//int main()
//{
//	int arr[3],swap,i,j;
//	for (i = 0; i < 3; i++)
//		scanf("%d", &arr[i]);
//	for (i = 0; i < 2; i++)
//	{
//		for (j = i+1; j <=2; j++)
//		{
//			if (arr[j]>arr[i])
//			{
//				swap = arr[i];
//				arr[i] = arr[j];
//				arr[j] = swap;
//			}
//		}
//	}
//	for (i = 0; i <= 2; i++)
//		printf("%d ",arr[i]);
//
//	return 0;
//}


//OJ 2  3�ı���
//#include <stdio.h>
//int main()
//{
//	int i;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//			printf("%d ", i);
//	}
//	return 0;
//}


//OJ 3 ���Լ��
//#include <stdio.h>
//int main()
//{
//	int r, a, b, m,swap;
//	scanf("%d%d", &a, &b);
//	if (b > a)
//	{
//		swap = a;
//		a = b;
//		b = swap;
//	}
//		r = a%b;
//	while (r)
//	{
//		a = b;
//		b = r;
//		r = a%b;
//	}
//	m = b;
//		printf("���Լ��Ϊ:%d\n",m);
//	return 0;
//}


//OJ 4 ��ӡ���꣨1000-2000��
//     �ж���������4����������100���� �����߱�400����
//#include <stdio.h>
//int main()
//{
//	int year,count=0;
//	printf("������:\n");
//	for (year = 1000; year <= 2000; year++)
//	{
//		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//		{
//			printf("%d ",year);
//			count++;
//			if (count % 10 == 0)
//				printf("\n");
//		}
//	}
//	return 0;
//}


//OJ 5  ��ӡ������100--200��
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int i,k,count=0;
//	printf("������:\n");
//	for (i = 100; i <= 200; i++)
//	{
//		for (k = 2; k <=i; k++)
//		{
//			if (i%k == 0)
//				break;
//		}
//		if (k == i)
//		{
//			printf("%d ", i);
//			count++;
//			if (count % 10 == 0)
//				printf("\n");
//		}
//	}
//
//	return 0;
//}


//OJ 6 ��9��������1--100 �г���9�Ĵ�����
//#include<stdio.h>
//int main()
//{
//	int i,t,count=0;
//	for (i = 1; i <= 100; i++)
//	{
//		t = i;
//		while (t)
//		{
//			if (t % 10 == 9)
//				count++;
//			t /= 10;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}


//OJ 6     ����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ����ӡ�����
//#include <stdio.h>
//int main()
//{
//	int i;
//	double sum = 0.0;
//	for (i = 1; i <= 100; i+=2)
//		sum += 1.0 / i;
//	for (i = 2; i <= 100; i += 2)
//		sum -= 1.0 / i;
//	printf("%f\n", sum);
//	return 0;
//}


//OJ 7 ��10 �����������ֵ
//#include <stdio.h>
//int main()
//{
//	int  arr[10], MAX,i;
//	for (i = 0; i < 10; i++)
//		scanf("%d", &arr[i]);
//	MAX = arr[0];
//	for (i = 0; i < 10; i++)
//	{
//		if (arr[i]>MAX)
//			MAX = arr[i];
//	}
//	printf("���ֵΪ��%d\n", MAX);
//	return 0;
//}

//OJ 8  ����Ļ�����9*9�˷��ھ���
//#include <stdio.h>
//int main()
//{
//	int i, j;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-4d", i, j, i*j);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//OJ 9 ��д������һ���������������в��Ҿ����ĳ����
//     Ҫ���ҵ��˾ʹ�ӡ�������ڵ��±꣬�Ҳ�����������Ҳ�����
#include <stdio.h>
int main()
{
	int i,n,k;
	scanf("%d", &n);
	int a[100];
	int left = 0;
	int right = n-1;
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &k);
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (k>a[mid])
			left++;
		else if (k < a[mid])
			right--;
		else
		{
			printf("�ҵ��ˣ��±�Ϊ��%d\n", mid);
			break;
		}

	}
	if (left>right)
		printf("�Ҳ���\n");

	return 0;
}