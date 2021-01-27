#define _CRT_SECURE_NO_WARNINGS

// Text 1 
//写一个函数打印arr数组的内容，不使用数组下标，使用指针。
//arr是一个整形一维数组。

//#include <stdio.h>
//
//void print(int* p, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//}
//
//int main()
//{
//	int arr[5] = { 2, 4, 5, 6, 7 };
//	int sz = sizeof(arr) / sizeof (arr[0]);
//	print(arr, sz);
//	return 0;
//}


// Text 2 字符串逆序
//输入
//I am a student
//输出
//tneduts a ma I

//#include <stdio.h>
//#include <string.h>
//
//void reverse(char* p, int sz)
//{
//	for (int i = sz - 1; i >= 0; i--)
//	{
//		printf("%c", *(p + i));
//	}
//}
//
//int main()
//{
//	char arr[100];
//	while (gets(arr))
//	{
//		int sz = strlen( arr );
//		reverse(arr, sz);
//	}
//	return 0;
//}


//Text 3 
//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222

//#include <stdio.h>
//#include <math.h>
//
//int Sn(int a, int n)
//{
//	if (n == 1)
//		return a ;
//	else
//	{
//		int ret = 0 ;
//		for (int i = 0; i < n; i++)
//		{
//			ret += a * (int)pow( 10 , i);
//		}
//		return  ret + Sn( a , n - 1);
//	}
//}
//
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	int n = 5 ;
//	int sum = Sn( a , n);
//	printf("%d\n", sum);
//	return 0;
//}

//Text 4
//求出0～100000之间的所有“水仙花数”并输出。
//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如 : 153＝1 ^ 3＋5 ^ 3＋3 ^ 3，则153是一个“水仙花数”。

//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	for (int i = 0; i <= 100000; i++)
//	{
//		int sum = 0;
//		int j = i % 10;
//		int x = i ;
//		int count = 1;
//		while (x/10)
//		{
//			x /= 10 ;
//			count++;
//		}
//		x = i ;
//		while (x)
//		{
//			sum += (int)pow((x % 10) , count ) ;
//			x /= 10 ;
//		}
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0 ;
//}

// Text 5

//#include <stdio.h>
//int main()
//{
//	int i, j ,k;
//	for (i = 0; i < 13; i++)
//	{
//		if (i < 7)
//		{
//			for (j = 1; j <= 13; j++)
//			{
//				if (j>=7 - i && j <= 7 + i)
//					printf("*");
//				else
//					printf(" ");
//			}
//		}
//		else
//		{
//
//			for (j = 1; j <= 13; j++)
//			{
//				if (j>= i - 5  && j <= 13 - (i-6))
//					printf("*");
//				else
//					printf(" ");
//			}
//		}
//		printf("\n");
//	
//	}
//	return 0;
//}

//Text 6
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水
#include <stdio.h>
int main()
{
	int count = 20 ; 
	int n = 20 ; 
	while (n >= 2)
	{
		if (n % 2 == 1)
		{
			count += (n - 1) / 2;
			n = (n - 1) / 2 + 1 ;
		}
		else
		{
			count += n / 2;
			n = n / 2 ;
		}
	}
	printf("%d\n",count);
	return 0;
}