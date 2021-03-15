#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/*
柔性数组：
(1)定义：在结构体中，若最后一个元素是不规定大小的数组（该结构体元素大于1），该数组长度是弹性可变的
*/

//example ---柔性数组
typedef struct S1
{
	int n;
	int arr[];
}S1; // sizeof(S)所求的结构体大小未包含柔性数组的大小

//example ---非柔性数组
typedef struct S2
{
	int n;
	int* arr;
}S2;

int main1()
{
	// 用动态内存来定义一个含柔性数组的结构体：
	S1* ps = (S1*)malloc(sizeof(S1)+sizeof(int)* 10);//为柔性数组开辟40个字节的空间
	
	return 0;
}

int main2()
{
	//定义一个非柔性数组
	S2*ps = (S2*)malloc(sizeof(S2));
	int*a = (int*)malloc(sizeof(int)* 10);
}

//利用柔性数组更简便
//(1)只要malloc一次内存，且内存连续，访问速度快。
//   而非柔性数组多次malloc产生的空间碎片多，空间利用率低
//(2)非柔性数组需要释放两次内存，操作麻烦

