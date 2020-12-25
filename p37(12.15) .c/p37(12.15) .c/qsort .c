#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

Buble_sort(float arr[], int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz; i++)
	{
		for (j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] >arr[j + 1])
			{
				float  swap;
				swap = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = swap;
			}
		}
	}
}

int main()
{
	float  arr[10] = { 9.0, 8.0, 7.0, 6.0,5.0, 4.0, 3.0, 2.0, 1.0, 0.0 };
	int sz = sizeof (arr) / sizeof (arr[0]);
	Buble_sort(arr, sz);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%f ", arr[i]);
	}
	return 0;
}
