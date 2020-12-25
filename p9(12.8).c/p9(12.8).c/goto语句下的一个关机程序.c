#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main()
{

	char arr[20] = { "0" };
	system ("shutdown -s -t 60");
	printf("电脑即将关机，请输入: 哈哈哈 停止关机\n");


	again:
		printf("请输入：");
		scanf("%s", arr);
		if (0 == strcmp("哈哈哈", arr))
		{
			printf("已停止关机\n");
			system("shoutdowm -a ");
		}
		else
		{
			printf("输入错误，请重试\n");
			goto again;
		}


	return 0;
}