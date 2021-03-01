#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void swap(char* buf1, char * buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void my_qsort(void* base, int sz, int width, int(*cmp)(void* e1, void* e2))
{
	int i = 0;
	//ÅÅ sz - 1 ÌË
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - i; j++)
		{
			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width) > 0) // ÉýÐò
			{
				swap((char*)base + j* width, (char*)base + (j + 1)* width, width);
			}
		}
	}
}

int main()
{
	int arr[3] = { 12, 23, 45 };
	int sz = sizeof(arr) / sizeof (arr[0]);
	my_qsort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

