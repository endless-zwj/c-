#define _CRT_SECURE_NO_WARNINGS

//  在一个有序数组中查找具体的某个数字n。编写 int binsearch 
// （int x, int v[], int n）;功能；在v[0]<=v[2]<v[3]<......<v[n-1]
//  的数组中查找x;
//
//#include <stdio.h>
//int main()
//{
//	int n = 0;
//	int arr[] = { 1, 3, 4, 5, 6, 7, 9 };
//	int sz = sizeof (arr) / sizeof (arr[0]);
//	int left = 0;
//	int right = sz - 1;
//
//	scanf("%d", &n);
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < n)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > n)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("找到了\n");
//			break;
//		}
//	}
//
//	if (arr[left] >arr[right])
//		printf("找不到");
//
//	return 0;
//}
