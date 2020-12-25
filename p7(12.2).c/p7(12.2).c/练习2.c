#define _CRT_SECURE_NO_WARNINGS
//编写代码实现，模拟用户登录情景，并且只能登录三次。
//只能输三次密码，如果输错则退出程序。

#include<stdio.h>
#include<string.h>
int main()
{
	char password[] = "12345";    //如果密码为 12345 abcd 要怎么设计程序

	int i = 0;
	char arr[20];

	for (i = 0; i < 3; i++)
	{
		
		scanf("%s", arr);

		if (strcmp(arr, password) == 0)
		{
			printf("登录成功\n");
		    break;
		}
	}

	if (strcmp(arr, password) != 0)
		printf("很遗憾，系统即将退出\n");

	return 0;
}
