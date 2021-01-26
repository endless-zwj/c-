#define _CRT_SECURE_NO_WARNINGS

//交换两个变量（不创建临时变量）
//不允许创建临时变量，交换两个整数的内容

//#include <stdio.h>
//
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("交换前：a=%d,b=%d\n", a, b);
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	printf("交换后：a=%d,b=%d\n", a, b);
//	return 0;
//}



//Text 2 
//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列

//#include <stdio.h>
//int main()
//{
//	int a ;
//	scanf("%d", &a);
//	printf("二进制偶数位: ");
//	for (int i = 31; i >= 1; i -= 2)
//	{
//		printf("%d ", a >> i);
//	}
//	printf("\n");
//	printf("二进制偶数位: ");
//	for (int i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", a >> i);
//	}
//	printf("\n");
//	return 0;
//}


//Text 3
//输入一个整数，输出该数32位二进制表示中1的个数。其中负数用补码表示。

#include <stdio.h>
int main()
{
	int a;
	scanf("%d", &a);
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (((a >> i) & 1) == 1)
			count++;
	}
	printf("%d\n", count);
	return 0;
}