#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/*
                  <<<<<< 1 >>>>>>
                  结构体内存对齐：
1.第一个成员变量在结构体变量偏移量为0地址处；
2.其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处
     对齐数 = min（编译器默认对齐数，该成员大小）
     vs中默认为 8
3.结构体总大小为最大对齐数的整数倍；
4.嵌套结构体情况下：嵌套结构对齐到该结构体最大对齐数的整数倍处
*/

struct S1
{
	char a;
	int  b;
	char c;
};//12

struct S2
{
	char a;
	char b; 
	int  c;
};//8

/*
			    <<<<< 2 >>>>>>
				修改默认对齐数
#pragma pack(修改值) --->修改默认对齐数
 .....(结构体)
#pragma pack()       --->取消默认对齐数
*/

/*
               <<<<<< 3 >>>>>>>
			  宏实现求解变量偏移量
offsetof(struct S1 ,变量)
*/

int main()
{
	printf("%d,%d",sizeof(struct S1),sizeof(struct S2));
	printf("\n");
	return 0;
}
