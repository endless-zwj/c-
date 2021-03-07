#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
		            <<< 1 >>>
		联合体  --->  判断计算机的大小端存储模式

		        联合体大小计算
		1.联合体大小至少是最大成员变量。
		2.当最大成员大小不是最大对齐数的整数倍，就要对齐。
*/

int check_sys1()
{
	int a = 1 ;
	char* p = (char*)&a ;
	return *p ;  // 小端返回 1 ， 大端返回 0 ；
}

int check_sys2()
{
	union
	{
		char c;
		int i ;
	}u;
	u.i = 1;
	return u.c ;  // 小端返回 1 ，大端返回 0 ；

}

int main()
{
	int ret1 = check_sys1();
	int ret2 = check_sys2();
	if (ret1 == 1)
		printf("sys1 :小端存储\n");
	else
		printf("sys1 :大端存储\n") ;
	if (ret2 == 1)
		printf("sys2 :小端存储\n");
	else
		printf("sys2 :大端存储\n");
	return 0 ;
}
