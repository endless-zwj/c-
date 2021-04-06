#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <windows.h>
#include"Seqlist.h"
#include"Sqlist.h"

//顺序表插入方式的菜单
void menu3(SeqList* seqlist)
{
	int val;
	int pos;
	system("cls");
	printf("\n\n\n\n");
	printf("\t\t\t\t正在加载插入方式功能栏......\n");
	Sleep(1000);
	int x;
	do
	{
		system("cls");
		printf("\n\n\n\n");
		printf("\t\t\t\t\t\t1.头插\n");
		printf("\t\t\t\t\t\t2.尾插\n");
		printf("\t\t\t\t\t\t3.按序号插入\n");
		printf("\t\t\t\t\t\t0.退出\n");
		printf("\t\t\t\t\t\t请选择:> ");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			system("cls");
			printf("\t\t\t\t\t请输入你要插入的值:> ");
			scanf("%d", &val);
			SeqListPushFront(seqlist, val);
			printf("\t\t\t\t\t[%d]已插入顺序表!\n",val);
			Sleep(1000);
			break;
		case 2:
			system("cls");
			printf("\t\t\t\t\t请输入你要插入的值:> ");
			scanf("%d", &val);
			SeqListPushBack(seqlist, val);
			printf("\t\t\t\t\t[%d]已插入顺序表!\n",val);
			Sleep(1000);
			break;
		case 3:
			system("cls");
			printf("\t\t\t\t\t请输入你要插入的位置:> ");
			scanf("%d", &pos);
			printf("\t\t\t\t\t请输入你要插入的值:> ");
			scanf("%d", &val);
			SeqListInsert(seqlist, pos, val);
			printf("\t\t\t\t\t[%d]已插入顺序表!\n", val);
			Sleep(1000);
			break;
		}
	}while (x);
}

void menu1()
{
	SeqList seqlist;
	SeqListInit(&seqlist);
	system("cls");
	printf("\n\n\n\n");
	printf("\t\t\t\t\t正在加载顺序表功能栏......\n");
	Sleep(1000);
	int x;
	int index;
	int val;
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
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			system("cls");
			SeqListInit(&seqlist);
			printf("\t\t\t\t\t创建顺序表成功!\n");
			Sleep(1000);
			break;
		case 2:
			system("cls");
			printf("\t\t\t\t\t该顺序表的的长度为:[%d]\n",seqlist.size);
			Sleep(1000);
			break;
		case 3:
			system("cls");
			printf("请输入你要获取的元素下标:> ");
			scanf("%d",&index);
			if (index > seqlist.size)
				printf("\t\t\t\t\t顺序表中无该元素!\n");
			else
				printf("\t\t\t\t\t该元素为[%d]\n",seqlist.Array[index-1]);
			Sleep(1000);
			break;

		case 4:
			system("cls");
			printf("\t\t\t\t\t请输入你要查找的元素:> ");
			scanf("%d",&val);
			int ret = SeqListFind(&seqlist , val);
			if (ret == -1)
				printf("\t\t\t\t\t顺序表中无该值!\n");
			else
				printf("\t\t\t\t\t该值在顺序表的第[%d]位\n", ret);
			Sleep(1000);
			break;
		case 5:
			system("cls");
			//插入方式的菜单
			menu3(&seqlist);
			Sleep(1000);
			break;
		case 6:
			system("cls");
			printf("请输入你要删除元素的下标:> ");
			scanf("%d",&index);
			SeqListErase(&seqlist, index);
			printf("\t\t\t\t该元素已删除!\n");
			Sleep(1000);
			break;
		case 7:
			system("cls");
			PrintSeqList(&seqlist);
			Sleep(1000);
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (x);
}

void menu2()
{
	SListNode* headNode = NULL;
	
	system("cls");
	printf("\n\n\n\n");
	printf("\t\t\t\t\t\t正在加载链表功能栏......\n");
	Sleep(1000);
	int x;//选项
	int size;//链表大小
	int index;//下标
	int val;//值
	int ret;//返回值
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
			system("cls");
			headNode = NULL;
			printf("\t\t\t\t链表创建成功!\n");
			Sleep(1000);
			break;
		case 2:
			system("cls");
			size = SListSize(&headNode);
			printf("\t\t\t\t该链表大小为:[%d]\n",size);
			Sleep(1000);
			break;
		case 3:
			system("cls");
			printf("\t\t\t\t请输入你要查找的下标:> ");
			scanf("%d",&index);
			printf("\t\t\t\t该值为[%d]\n",SListFind(&headNode,index) );
			Sleep(1000);
			break;
		case 4:
			system("cls");
		    printf("\t\t\t\t请输入你要查找的值:> ");
			scanf("%d",&val);
			ret = SListSearchVal(&headNode, val);
			if (ret == 0)
				printf("\t\t\t\t该值不存在!\n");
			else
				printf("\t\t\t\t该值的下标为: %d",ret);
			Sleep(1000);
			break;
		case 5:
			system("cls");
			printf("\t\t\t\t请输入你要插入的数:> ");
			scanf("%d",&val);
			SListPushFront(&headNode , val);
			printf("\t\t\t\t[%d]已被插入链表\n",val);
			Sleep(1000);
			break;
		case 6:
			system("cls");
			SListPopFront(&headNode);
			printf("\t\t\t\t链表第一个元素已被删除!\n");
			Sleep(1000);
			break;
		case 7:
			system("cls");
			PrintSList(headNode);
			Sleep(1000);
			break;
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
		scanf("%d", &x);
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

