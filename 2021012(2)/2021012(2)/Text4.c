#define _CRT_SECURE_NO_WARNINGS

Text 4
编写一个函数 reverse_string(char * string)（递归实现）
实现：将参数字符串中的字符反向排列。

#include <stdio.h>

void  reverse_string(char* string)
{
	if (*(string) == 0)
	{
		return;
	}
	else
	{
		reverse_string(string + 1);
		printf("%c", *string);
	}

}

int main()
{
	char string[] = "hello";
	reverse_string(string);
	printf("\n");
	return 0;
}

