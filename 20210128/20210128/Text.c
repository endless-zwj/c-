#define _CRT_SECURE_NO_WARNINGS

// Text 1 模拟实现strlen 

#include <stdio.h>
int My_Strlen(char* p)
{
	int ret = 0 ;
	while (*p++)
	{
		ret++ ;
	}
	return ret ;
}

int main()
{
	char arr[100];
	gets(arr);
	int ret = My_Strlen(arr);
	printf("%d\n", ret);
	return 0;
}


// Text 2 模拟实现strcpy
#include <stdio.h>
char* My_strcpy(char* des, const char* src)
{
	char* ret = des ; 
	while (*des++ = *src++)
	{
		;
	}
	return ret ;
}

int main()
{
	char arr1[] = "abcdefgzwj" ;
	char* p = "zwjhaha" ;
	printf("%s\n", My_strcpy(arr1, p));
	return 0 ;
}

//Text 3  奇数前偶数后
#include <stdio.h>
void func1(int arr[], int left, int right)
{
	while (left < right)
	{
		if (arr[left] % 2 == 1 && left < right)
		{
			left++ ;
		}
		if (arr[right] % 2 == 0 && left < right)
		{
			right-- ;
		}
		if (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp ;
		}
	}
}

int main()
{
	int arr[] = { 123, 345, 252, 342, 748, 422, 125, 436, 248 };
	int left = 0 ;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	func1(arr, left, right);
	for (int i = 0; i < right; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0 ;
}
