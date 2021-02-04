#define _CRT_SECURE_NO_WARNINGS
//练习使用qsort
#include<stdio.h>
#include<stdlib.h>

int cmp_float(const void* e1, const void* e2)
{
	return (*(float*)e1) >= (*(float*)e2) ? 1 : -1 ;
}

void text1()
{
	float arr[5] = { 12.3f, 23.5f, 12.3f, 43.5f, 11.4f };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_float);
	for (int i = 0; i < sz; i++)
	{
		printf("%.2f ", arr[i]); 
	}
	printf("\n");
}


int main()
{
	text1();//对浮点数数组进行排序
	
	return 0 ;
}
