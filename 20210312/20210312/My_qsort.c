#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int cmp_by_int(void*start, void* end)
{
	return  *((int*)start) - *((int*)end) ;
}

void swap(char* e1, char* e2, int width)
{
	char tmp;
	while (width--)
	{
		tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;
	}
}

void My_qsort(void* parr, int length, int width, int(*cmp)(void*, void*))
{
	int i = 0;
	for (i = 0; i < length - 1 ; i++)
	{
		int j = 0;
		for (j = 0; j < length - i - 1; j++)
		{
			if (cmp((char*)parr + j*width, (char*)parr + (j + 1)*width)>0)
				swap((char*)parr + j*width, (char*)parr + (j + 1)*width, width);
		}
		(char*)parr += width;
	}
}

int main()
{
	int arr[10] = { 0, 4, 6, 4, 8, 14, 9, 4, 36, 89 };
	int length = sizeof(arr) / sizeof(arr[0]); 
	int width = sizeof(int);
	My_qsort(arr, length, width, cmp_by_int);
	int i = 0;
	for (i = 0; i < 10;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	
	return 0; 
}

