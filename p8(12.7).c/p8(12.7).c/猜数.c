#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
	printf("***********************************\n");
	printf("********1:START      0:EXIT********\n");
	printf("***********************************\n");

}

void game()
{
	int ret = 0;
	int guess = 0;
	ret = rand()%100+1;
	while (1)
	{
		printf("请输入你要猜的数：");
		scanf("%d", &guess);
		if (guess > ret)
			printf("猜大了\n");
		else if (guess < ret)
			printf("猜小了\n");
		else
		{
			printf("恭喜您，猜对了，是%d\n",guess);
			break;
		}
	}

}

int main()
{
	int input = 0;

	srand((unsigned int)time(NULL));


	do
	{
		menu();
		printf("请选择：（1开始/0退出）\n");
		scanf("%d", &input);

		switch (input)
		{
		case 0:
			printf("请按回车/空格/tab退出\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} 
	while ( input );

	return 0;
}