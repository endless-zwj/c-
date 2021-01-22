#define _CRT_SECURE_NO_WARNINGS

//Text 1
//汉诺塔问题

//#include <stdio.h>
//
//void move(char pos1, char pos2)
//{
//	printf("%c%s%c ", pos1, "-->", pos2);
//}
//
//// n : 箱子个数
//// pos1 :  起始位置
//// pos2 :  中间位置
//// pos3 :  目的位置
//
//void Hanoi(int n , char pos1 , char pos2 , char pos3)
//{
//	if (n == 1)
//	{
//		move(pos1, pos3);
//	}
//	else
//	{
//		Hanoi(n - 1, pos1, pos3, pos2);
//		move(pos1, pos3);
//		Hanoi(n - 1, pos2 , pos1 , pos3 );
//	}
//}
//
//#include <stdio.h>
//int main()
//{
//	int n;
//	char pos1 = 'A';
//	char pos2 = 'B';
//	char pos3 = 'C';
//	while (scanf("%d", &n) != EOF)
//	{
//		Hanoi(n, pos1, pos2, pos3);
//	}
//	return 0;
//}



//Text 2
//青蛙跳台阶问题 一次可跳一阶或两阶

#include <stdio.h>

int Jump(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}else 
	{
		return Jump(n - 1) + Jump(n - 2);
	}
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int ret = Jump(n);
		printf("有%d种跳法\n", ret);
	}

	return 0;
}