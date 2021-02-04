#define _CRT_SECURE_NO_WARNINGS
//qsort的实现  ---->基于冒泡排序实现
#include <stdio.h>
#include<string.h>
struct stu
{
	char name[100];
	int age;

};

void Swap(void* base, int j, int width)
{
	char* e1 = (char*)base + j * width;
	char* e2 = (char*)base + (j+1) * width;
	int i = 0 ;
	for (i = 0; i < width; i++)
	{
		char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp ;
		e1++;
		e2++;
	}
}

void My_qsort(  void* base , int sz, int width,  int(*cmp)( const void* e1,const void* e2) )//函数回调
{
	int i ;
	for (i = 0; i < sz; i++)
	{
		int j;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width) > 0)
			{
				Swap(base, j, width); 
			}
		}
	}
}

int cmp_int(const void* e1, const void* e2)
{
	return (int*)e1 - (int*)e2 ;//升序
}

int cmp_float(const void* e1, const void* e2)
{
	return (float*)e1 - (float*)e2 ;
}

int cmp_char(const void* e1, const void* e2)
{
	return (char*)e1 - (char*)e2;
}

int cmp_stu_by_name(const void* e1, const void* e2)
{
	if (strcmp((((struct stu*)e1)->name), (((struct stu*)e2)->name)) > 0)
		return  1;
	 else if (strcmp((((struct stu*)e1)->name), (((struct stu*)e2)->name)) == 0)
		return  0;
	 else 
		return  -1;
}


void text1()
{
	 struct stu s[3] = { { "zhangsan", 14 }, { "lisi", 53 }, { "wangwu", 32 } };
	 int sz = sizeof(s) / sizeof(s[0]);
	 My_qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
}

int main()
{
	text1();
	
	return 0;
}
