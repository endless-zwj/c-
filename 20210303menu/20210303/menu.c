#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <windows.h>

void menu1()
{
	system("cls");
	printf("\t\t\t\t\t\t���ڼ���˳���......");
	Sleep(1000);
	int x;
	do
	{
		system("cls");
		printf("\n\n\n\n");
		printf("\t\t\t\t\t\t1.����˳���\n");
		printf("\t\t\t\t\t\t2.��˳�����\n");
		printf("\t\t\t\t\t\t3.�����ȡ˳����Ԫ��\n");
		printf("\t\t\t\t\t\t4.��ֵ����˳���\n");
		printf("\t\t\t\t\t\t5.����Ԫ��\n");
		printf("\t\t\t\t\t\t6.ɾ��Ԫ��\n");
		printf("\t\t\t\t\t\t7.���˳���\n");
		printf("\t\t\t\t\t\t0.�˳�\n");
		printf("\t\t\t\t\t\t��ѡ��:> ");
		scanf("%d",&x);
		switch (x)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 0:
		default:
			printf("�����������������\n");
			break;
		}
	} while (x);
}

void menu2()
{
	system("cls");
	printf("\t\t\t\t\t\t���ڼ�������......");
	Sleep(1000);
	int x;
	do
	{
		system("cls");
		printf("\n\n\n\n");
		printf("\t\t\t\t\t\t1.��������\n");
		printf("\t\t\t\t\t\t2.��������\n");
		printf("\t\t\t\t\t\t3.�����ȡ�����Ԫ��\n");
		printf("\t\t\t\t\t\t4.��ֵ����˳���\n");
		printf("\t\t\t\t\t\t5.����Ԫ��\n");
		printf("\t\t\t\t\t\t6.ɾ��Ԫ��\n");
		printf("\t\t\t\t\t\t7.�������\n");
		printf("\t\t\t\t\t\t0.�˳�\n");
		printf("\t\t\t\t\t\t��ѡ��:> ");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 0:
		default:
			printf("�����������������\n");
			break;
		}
	} while (x);
}

int main()
{
	int x;
	do
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t\t\t1.˳���\n");
		printf("\t\t\t\t\t\t2.����\n");
		printf("\t\t\t\t\t\t0.�˳�\n");
		printf("\t\t\t\t\t\t��ѡ��:> ");
		scanf("%d",&x);
		switch (x)
		{
		case 1:
			menu1();
			break;
		case 2:
			menu2();
			break;
		case 0:
			break;
		default:
			printf("�����������������\n");
		}
	} while (x);
	return 0;
}
