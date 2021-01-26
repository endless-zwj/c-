#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void menu()
{
	printf("##############################\n");
	printf("######      1. play      #####\n");
	printf("######      2. exit      #####\n");
	printf("##############################\n");
}

void game()
{
	char mine[ROWS][COLS] ;
	char show[ROWS][COLS] ;
	
	//初始化棋盘
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');

	//展示棋盘
	//Displayboard(mine, ROW, COL);
	Displayboard(show, ROW, COL);

	//设置地雷
	SetMine(mine, ROW, COL,EASY_COUNT);
	Displayboard(mine, COL, ROW);
	FindMine(mine, show, ROW, COL,HP);
	
}

int main()
{
	srand((unsigned int)time(NULL));
	int input;
	do
	{
		menu();
		printf("确认是否开始游戏(1/0) :>  ");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("正在退出 :>\n");
				break;
			default:
				printf("选择错误,请重新选择 :>\n");
				break;
		}
	} while (input);
	return 0;
}