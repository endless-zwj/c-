#define _CRT_SECURE_NO_WARNINGS
// text1 
//模拟实现memmove

//#include <stdio.h>
//#include<assert.h>
//
//void*  my_memmove(void* des, void* src, size_t count)
//{
//	void* ret = des;
//	assert(des && src);
//	if (des <= src)//前插
//	{
//		while (count--)
//		{
//			* (char*)des = * (char*)src;
//			++(char*)des ;
//			++(char*)src ;
//		}
//	} 
//	else //后插
//	{
//		while (count--)
//		{
//			*((char*)des + count) = *((char*)src + count);
//		}
//	}
//	return ret;
//
//}
//
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	my_memmove(arr + 2, arr + 3, 12);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0 ;
//}


//text2
//模拟实现memcpy

#include <stdio.h>
void* my_memcpy(void* des, void* src, size_t count)
{
	void* ret = des ;
	while (count--)
	{
		*(char*)des = *(char*)src ;
		++(char*)des ;
		++(char*)src ;
	}
	return ret ; 
}

int main()
{
	int arr1[] = { 12, 34, 43, 45 };
	int arr2[] = { 11, 23 ,12 };
	my_memcpy(arr1, arr2 + 1, 8);
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0 ;
}

