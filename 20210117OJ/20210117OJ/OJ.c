#define _CRT_SECURE_NO_WARNINGS
//OJ 1   按序输出
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


//OJ 2  3的倍数
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


//OJ 3 最大公约数
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
//		printf("最大公约数为:%d\n",m);
//	return 0;
//}


//OJ 4 打印闰年（1000-2000）
//     判断条件：被4整除但不被100整除 ；或者被400整除
//#include <stdio.h>
//int main()
//{
//	int year,count=0;
//	printf("闰年有:\n");
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


//OJ 5  打印素数（100--200）
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int i,k,count=0;
//	printf("素数有:\n");
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


//OJ 6 数9个个数（1--100 中出现9的次数）
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


//OJ 6     计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值，打印出结果
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


//OJ 7 求10 个整数中最大值
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
//	printf("最大值为：%d\n", MAX);
//	return 0;
//}

//OJ 8  在屏幕上输出9*9乘法口诀表
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


//OJ 9 编写代码在一个整形有序数组中查找具体的某个数
//     要求：找到了就打印数字所在的下标，找不到则输出：找不到。
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
			printf("找到了，下标为：%d\n", mid);
			break;
		}

	}
	if (left>right)
		printf("找不到\n");

	return 0;
}