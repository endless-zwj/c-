#define _CRT_SECURE_NO_WARNINGS

//  ��һ�����������в��Ҿ����ĳ������n����д int binsearch 
// ��int x, int v[], int n��;���ܣ���v[0]<=v[2]<v[3]<......<v[n-1]
//  �������в���x;
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
//			printf("�ҵ���\n");
//			break;
//		}
//	}
//
//	if (arr[left] >arr[right])
//		printf("�Ҳ���");
//
//	return 0;
//}
