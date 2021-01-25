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
		printf("��������Ҫ�µ����� x y :> ");
		scanf("%d%d", &x, &y);
		Sleep(1000);

		if ((x <= row && x >= 1 && y <= col && y >= 1) && (board[x - 1][y - 1] == ' '))
		{
			board[x - 1][y - 1] = '*';
			break ;
		}
		else if ((board[x - 1][y - 1] != ' ') && (x <= row && x >= 0 && y <= col && y >= 0))
		{
			printf("����������걻ռ��\n");
		}
		else
		{
			printf("�����������Խ��\n");
		}
		printf("������ȷ���������(x,y) :> ");
	}
}

void Computermove ( char board[ROW][COL])
{
	printf("����(����)��:\n");
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
	//�ж������
	for (i = 0; i < ROW; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	//�ж������
	for (i = 0; i < COL; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
	}
	//�ж�б�Խ����
	if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' '))
		return board[1][1];

	if ((board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' '))
		return board[1][1];

	//�ж������Ƿ�����
	

	if (IsFull(board, ROW, COL)  == 1)
	{
		return 'Q';
	}
	return 'C';

}

