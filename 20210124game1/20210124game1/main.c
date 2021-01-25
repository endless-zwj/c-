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
	char ret  ; // ���ڽ����ж���Ϸ����
	char board[ROW][COL] ; //���ڴ���һ������

	Initboard(board, ROW, COL);  //��ʼ��һ������,�ÿո��ʾ
	Displayboard(board, ROW, COL); //ʹ������ʾ����

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
			printf("ƽ��!!!\n");
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
		printf("�Ƿ�ʼ��Ϸ:(1/0)\n");
		printf("��ѡ��:> ");
	    scanf("%d", &input);
	

		switch(input)
		{
			case 1 :
				game() ;
				break ;
			case 0 :
				break ;
			default :
				printf("�������������ѡ��:>\n");
				break ;
		}
	} while (input);

	return 0 ;
}