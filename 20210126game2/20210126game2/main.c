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
	
	//��ʼ������
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');

	//չʾ����
	//Displayboard(mine, ROW, COL);
	Displayboard(show, ROW, COL);

	//���õ���
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
		printf("ȷ���Ƿ�ʼ��Ϸ(1/0) :>  ");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("�����˳� :>\n");
				break;
			default:
				printf("ѡ�����,������ѡ�� :>\n");
				break;
		}
	} while (input);
	return 0;
}