#define _CRT_SECURE_NO_WARNINGS


Text3  用递归和非递归实现strlen

#include <stdio.h>

int My_strlen1(char arr[])  //非递归实现strlen 
{
	int count = 0;
	int i = 0;
	while (arr[i] != '\0')
	{
		i++;
		count++;
	}
	return count;
}

int My_strlen2(char arr[]) //递归实现strlen 
{
	if (arr[0] == 0)
		return 0;
	else
		return 1 + My_strlen2(arr + 1);
}

int main()
{
	char arr[100];
	scanf("%s", arr);
	int ret1 = My_strlen1(arr);
	int ret2 = My_strlen2(arr);
	printf("%d %d\n", ret1, ret2);
	return 0;
}