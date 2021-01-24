#define _CRT_SECURE_NO_WARNINGS

 // Text  1 实现一个冒泡排序 (升序)
//
//#include <stdio.h>
//void bubblesort(int arr[], int sz)
//{
//	int i , j ;
//	int flag ; // 判断是否有序
//	for (i = 1; i < sz - 1; i++)
//	{
//		flag = 0 ;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 1;
//			}
//		}
//		if (flag == 0)
//			break ;
//	}
//}
//
//int main()
//{
//	int i;
//	int  arr[] = { 23, 21, 45, 25, 67, 36, 74 };
//	int sz = sizeof (arr) / sizeof (arr[0]);
//	bubblesort(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0 ;
//}


// Text 2 
//创建一个整形数组，完成对数组的操作
//实现函数init() 初始化数组为全0
//实现print()  打印数组的每个元素
//实现reverse()  函数完成数组元素的逆置。

//#include <stdio.h>
//
//void init(int arr[], int sz)
//{
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//
//void print(int arr[],int sz)
//{
//	int i ;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]); 
//	}
//	printf("\n");
//}
//
//void reverse (int arr[], int sz)
//{
//	int i; 
//	int left = 0 ;
//	int right = sz - 1;
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	int arr[] = { 23 , 34, 35 ,52 , 245 , 535 };
//	int sz = sizeof(arr) / sizeof (arr[0]);
//	print( arr,sz ) ;
//	reverse( arr,sz ) ;
//	print( arr , sz );
//	init( arr , sz );
//	print( arr , sz );
//	return 0 ;
//}


// Text 3 
//将数组A中的内容和数组B中的内容进行交换。（数组一样大）

#include <stdio.h>
void print(int arr[], int sz)
{
	int i;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Swap(int arr1[],int arr2[] , int sz)
{
	int tmp;
	for (int i = 0; i < sz; i++)
	{
		tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
}

int main()
{
	int arr1[] = { 0, 1, 2, 3 };
	int arr2[] = { 3, 4, 4, 56 };	
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	print(arr1, sz);
	print(arr2, sz);

	Swap(arr1, arr2 , sz );
	print(arr1, sz);
	print(arr2, sz);

	return 0;
}