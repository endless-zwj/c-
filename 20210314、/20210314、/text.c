#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//  动态内存管理 -- malloc/free 函数
//int main()
//{
//	int* p = (int*)malloc(sizeof(int)* 10);
//	//申请内存失败
//	if (p == NULL)
//	{
//		//打印错误信息
//		printf("%s\n",strerror(errno));
//	}
//	else
//	{
//		//正常使用空间
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ",*(p+i));
//		}
//		free(p);//指针内容释放为空，但其指向没发生改变（但不能在对其访问，会造成非法访问内存）
        //            <free注意事项>
        // free函数只能对动态内存的数据进行释放（堆区）
		// free不能释放一段动态内存空间，要对一段连续的空间全部释放
		//不能对同一块空间多次释放 解决方法：释放完后将原指针置为空

//		printf("%d\n", *p); //此时里面的内容为随机值
//		p = NULL;
//	}
//
//	return 0;
//}

//  动态表内存管理------calloc函数
//int main()
//{
//	int* arr = (int*)calloc(10,sizeof(int));//第一个参数元素个数 ，第二个参数每个元素的大小
//	//calloc初始化空间全为零
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ",*(arr+i));
//	}
//	printf("\n");
//	printf("1234");
//	free(arr);
//	return 0;
//}

// 动态内存管理 --- realloc函数  扩容函数

/*
	realloc基本原理:
	1.如果p后面的空间足够大，则realloc直接在p后面拼接一段空间，并返回原值p
	2.如果p后面的空间不够大，则realloc函数在堆区重新开辟一块空间，并返回新地址(原数据不改变，后面数据不初始化)
	3.如果realloc开辟空间失败，则返回NULL，因此不能直接用原指针接收realloc的返回值
	4.realloc函数第一个参数如果为NULL，则作用效果 = malloc
*/
int main()
{
	int* p = calloc(10, 4);
	int* ptr = realloc(p, 20 * 4);
	if (ptr != NULL)
	{
		p = ptr;
		for (int i = 0; i < 20; i++)
		{
			printf("%d ", *(p + i));
		}
		free(p);
	}
	
	return 0;

}
