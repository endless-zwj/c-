#define _CRT_SECURE_NO_WARNINGS
/*
		      <<<< 1 >>>>
		         位段
1.位段成员可以是 int unsigned int  signed int char 
2.位段的空间按照 4字节（int） /  1字节 （char） 开辟
3.位段涉及很多不确定因素，位段不跨平台。
*/

//example 1
#include <stdio.h>

struct S
{
	char a : 3 ; // a 存在 3  个 bit 位内
	char b : 4 ; // b 存在 4  个 bit 位内 
	char c : 5 ;
	char d : 4 ; 
};

int main()
{
	struct S s = { 0 };
	s.a = 10;
	s.b = 20;
	s.c = 3;
	s.d = 4;

	/*
	   vs 下 一个字节 0 0 0 0 0 0 0 0
						[   b ][  a ]
	   从右往左开辟空间
	   且无法利用的空间废弃
	*/

	printf("%d\n", s.a); // 2  (只取3位bit位内的数)
	printf("%d\n", s.b); // 4  (只取4位bit位内的数)
	printf("%d\n", s.c); // 3
	printf("%d\n", s.d); // 4
	return 0 ;

}
