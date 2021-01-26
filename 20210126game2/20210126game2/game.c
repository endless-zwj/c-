#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void Initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void Displayboard(char board[ROWS][COLS], int row, int col)
{
	for (int i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}

	printf("\n");

	for (int i = 0; i <= row; i++)
	{
		if (i == 0)
		{
			printf("-|");
		}
		else
		{
			printf("--");
		}
	}

	printf("\n");

	for (int i = 1; i <= row; i++)
	{
		printf("%d|", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i <= row; i++)
	{
		printf("--");
	}

	printf("\n");
}

void SetMine(char board[ROWS][COLS], int row, int col , int count)
{
	while (count)
	{
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}

}

int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return
		mine[x - 1][y - 1] +
		mine[x + 0][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y + 0] +
		mine[x + 1][y + 1] +
		mine[x + 0][y + 1] +
		mine[x - 1][y - 1] +
		mine[x + 0][y - 1] -  8 * '0';
}

void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS] , int row, int col,int hp)
{
	int x, y;
	
	while (hp)
	{
		printf("请选择坐标 :> ");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("GameOver!!!\n");
				Displayboard(mine, ROW, COL);
				break;
			}
			else
			{
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				Displayboard(show, ROW, COL);
				hp--;
			}
		}
		else
		{
			printf("坐标越界,请重新输入:>\n");
			continue;
		}
	}
	if (hp == 0)
	{
		printf("YOU WIN!!!\n");
		Displayboard(mine, ROW, COL);
	}
}
