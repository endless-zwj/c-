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
		printf("��������Ҫ�µ�����");
		scanf("%d", &guess);
		if (guess > ret)
			printf("�´���\n");
		else if (guess < ret)
			printf("��С��\n");
		else
		{
			printf("��ϲ�����¶��ˣ���%d\n",guess);
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
		printf("��ѡ�񣺣�1��ʼ/0�˳���\n");
		scanf("%d", &input);

		switch (input)
		{
		case 0:
			printf("�밴�س�/�ո�/tab�˳�\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("�������\n");
			break;
		}
	} 
	while ( input );

	return 0;
}