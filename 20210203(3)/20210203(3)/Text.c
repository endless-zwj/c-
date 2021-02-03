#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//函数指针的定义
//int Add(int x, int y)
//{
//	return x + y ;
//}
//
//int main()
//{
//	int(*p) (int, int) = Add;
//	printf("%d\n", p(2, 4));
//	return 0;
//}

//函数指针数组
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Dev(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	int(*arr[4])(int, int) = { Add, Sub, Mul, Dev };
//	
//		for (int i = 0; i < 4; i++)
//		{
//			printf("%d\n", arr[i](6, 3));
//		}
//		return 0;
//}
