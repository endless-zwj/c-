#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <windows.h>

void menu1()
{
	system("cls");
	printf("\t\t\t\t\t\t正在加载顺序表......");
	Sleep(1000);
	int x;
	do
	{
		system("cls");
		printf("\n\n\n\n");
		printf("\t\t\t\t\t\t1.创建顺序表\n");
		printf("\t\t\t\t\t\t2.求顺序表长度\n");
		printf("\t\t\t\t\t\t3.按序号取顺序表的元素\n");
		printf("\t\t\t\t\t\t4.按值查找顺序表\n");
		printf("\t\t\t\t\t\t5.插入元素\n");
		printf("\t\t\t\t\t\t6.删除元素\n");
		printf("\t\t\t\t\t\t7.输出顺序表\n");
		printf("\t\t\t\t\t\t0.退出\n");
		printf("\t\t\t\t\t\t请选择:> ");
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
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (x);
}

void menu2()
{
	system("cls");
	printf("\t\t\t\t\t\t正在加载链表......");
	Sleep(1000);
	int x;
	do
	{
		system("cls");
		printf("\n\n\n\n");
		printf("\t\t\t\t\t\t1.创建链表\n");
		printf("\t\t\t\t\t\t2.求链表长度\n");
		printf("\t\t\t\t\t\t3.按序号取链表的元素\n");
		printf("\t\t\t\t\t\t4.按值查找顺序表\n");
		printf("\t\t\t\t\t\t5.插入元素\n");
		printf("\t\t\t\t\t\t6.删除元素\n");
		printf("\t\t\t\t\t\t7.输出链表\n");
		printf("\t\t\t\t\t\t0.退出\n");
		printf("\t\t\t\t\t\t请选择:> ");
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
			printf("输入错误，请重新输入\n");
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
		printf("\t\t\t\t\t\t1.顺序表\n");
		printf("\t\t\t\t\t\t2.链表\n");
		printf("\t\t\t\t\t\t0.退出\n");
		printf("\t\t\t\t\t\t请选择:> ");
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
			printf("输入错误，请重新输入\n");
		}
	} while (x);
	return 0;
}
