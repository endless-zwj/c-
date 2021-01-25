#define _CRT_SECURE_NO_WARNINGS

#include "game.h"


void Initboard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row ; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void Displayboard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j != col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i != row - 1)
		{
			for (j = 0; j < row; j++)
			{
				printf("---");
				if (j != col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void Playermove( char board[ROW][COL], int row, int col)
{
	int x, y;
	while (1)
	{
		printf("请输入你要下的坐标 x y :> ");
		scanf("%d%d", &x, &y);
		Sleep(1000);

		if ((x <= row && x >= 1 && y <= col && y >= 1) && (board[x - 1][y - 1] == ' '))
		{
			board[x - 1][y - 1] = '*';
			break ;
		}
		else if ((board[x - 1][y - 1] != ' ') && (x <= row && x >= 0 && y <= col && y >= 0))
		{
			printf("你输入的坐标被占用\n");
		}
		else
		{
			printf("你输入的坐标越界\n");
		}
		printf("请重新确认你的坐标(x,y) :> ");
	}
}

void Computermove ( char board[ROW][COL])
{
	printf("电脑(菜鸟)下:\n");
	Sleep(1000);
	while (1)
	{
		int x = rand() % ROW;
		int y = rand() % COL;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

static int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char checkWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//判断行相等
	for (i = 0; i < ROW; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	//判断列相等
	for (i = 0; i < COL; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
	}
	//判断斜对角相等
	if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' '))
		return board[1][1];

	if ((board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' '))
		return board[1][1];

	//判断棋盘是否下满
	

	if (IsFull(board, ROW, COL)  == 1)
	{
		return 'Q';
	}
	return 'C';

}

