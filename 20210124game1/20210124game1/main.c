#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void menu()
{
	
	printf("########################\n");
	printf("####     1.play    #####\n");
	printf("####     0.exit    #####\n");
	printf("########################\n");

}

void game()
{
	char ret  ; // 用于接收判断游戏进程
	char board[ROW][COL] ; //用于创建一个棋盘

	Initboard(board, ROW, COL);  //初始化一个棋盘,用空格表示
	Displayboard(board, ROW, COL); //使棋盘显示出来

	while (1)
	{
		Playermove(board, ROW, COL);
		ret = checkWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		Displayboard(board, ROW, COL);

		
		Computermove(board);
		ret = checkWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		Displayboard(board, ROW, COL);
	}

		if (ret == '*')
		{
			printf("Player win !!!\n");
		}
		else if (ret == '#')
		{
			printf("Computer win !!!\n");
		}
		else if (ret == 'Q')
		{
			printf("平局!!!\n");
		}
		Displayboard(board, ROW, COL);

}

int main()
{
	srand( (unsigned int) time(NULL));
	int input = 0;

	do
	{
		menu();
		printf("是否开始游戏:(1/0)\n");
		printf("请选择:> ");
	    scanf("%d", &input);
	

		switch(input)
		{
			case 1 :
				game() ;
				break ;
			case 0 :
				break ;
			default :
				printf("输入错误，请重新选择:>\n");
				break ;
		}
	} while (input);

	return 0 ;
}