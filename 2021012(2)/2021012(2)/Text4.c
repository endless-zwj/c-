#define _CRT_SECURE_NO_WARNINGS

Text 4
��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
ʵ�֣��������ַ����е��ַ��������С�

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

