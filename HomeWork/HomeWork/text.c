#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <windows.h>
#include"Seqlist.h"
#include"Sqlist.h"

//˳�����뷽ʽ�Ĳ˵�
void menu3(SeqList* seqlist)
{
	int val;
	int pos;
	system("cls");
	printf("\n\n\n\n");
	printf("\t\t\t\t���ڼ��ز��뷽ʽ������......\n");
	Sleep(1000);
	int x;
	do
	{
		system("cls");
		printf("\n\n\n\n");
		printf("\t\t\t\t\t\t1.ͷ��\n");
		printf("\t\t\t\t\t\t2.β��\n");
		printf("\t\t\t\t\t\t3.����Ų���\n");
		printf("\t\t\t\t\t\t0.�˳�\n");
		printf("\t\t\t\t\t\t��ѡ��:> ");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			system("cls");
			printf("\t\t\t\t\t��������Ҫ�����ֵ:> ");
			scanf("%d", &val);
			SeqListPushFront(seqlist, val);
			printf("\t\t\t\t\t[%d]�Ѳ���˳���!\n",val);
			Sleep(1000);
			break;
		case 2:
			system("cls");
			printf("\t\t\t\t\t��������Ҫ�����ֵ:> ");
			scanf("%d", &val);
			SeqListPushBack(seqlist, val);
			printf("\t\t\t\t\t[%d]�Ѳ���˳���!\n",val);
			Sleep(1000);
			break;
		case 3:
			system("cls");
			printf("\t\t\t\t\t��������Ҫ�����λ��:> ");
			scanf("%d", &pos);
			printf("\t\t\t\t\t��������Ҫ�����ֵ:> ");
			scanf("%d", &val);
			SeqListInsert(seqlist, pos, val);
			printf("\t\t\t\t\t[%d]�Ѳ���˳���!\n", val);
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
	printf("\t\t\t\t\t���ڼ���˳�������......\n");
	Sleep(1000);
	int x;
	int index;
	int val;
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
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			system("cls");
			SeqListInit(&seqlist);
			printf("\t\t\t\t\t����˳���ɹ�!\n");
			Sleep(1000);
			break;
		case 2:
			system("cls");
			printf("\t\t\t\t\t��˳���ĵĳ���Ϊ:[%d]\n",seqlist.size);
			Sleep(1000);
			break;
		case 3:
			system("cls");
			printf("��������Ҫ��ȡ��Ԫ���±�:> ");
			scanf("%d",&index);
			if (index > seqlist.size)
				printf("\t\t\t\t\t˳������޸�Ԫ��!\n");
			else
				printf("\t\t\t\t\t��Ԫ��Ϊ[%d]\n",seqlist.Array[index-1]);
			Sleep(1000);
			break;

		case 4:
			system("cls");
			printf("\t\t\t\t\t��������Ҫ���ҵ�Ԫ��:> ");
			scanf("%d",&val);
			int ret = SeqListFind(&seqlist , val);
			if (ret == -1)
				printf("\t\t\t\t\t˳������޸�ֵ!\n");
			else
				printf("\t\t\t\t\t��ֵ��˳���ĵ�[%d]λ\n", ret);
			Sleep(1000);
			break;
		case 5:
			system("cls");
			//���뷽ʽ�Ĳ˵�
			menu3(&seqlist);
			Sleep(1000);
			break;
		case 6:
			system("cls");
			printf("��������Ҫɾ��Ԫ�ص��±�:> ");
			scanf("%d",&index);
			SeqListErase(&seqlist, index);
			printf("\t\t\t\t��Ԫ����ɾ��!\n");
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
			printf("�����������������\n");
			break;
		}
	} while (x);
}

void menu2()
{
	SListNode* headNode = NULL;
	
	system("cls");
	printf("\n\n\n\n");
	printf("\t\t\t\t\t\t���ڼ�����������......\n");
	Sleep(1000);
	int x;//ѡ��
	int size;//�����С
	int index;//�±�
	int val;//ֵ
	int ret;//����ֵ
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
			system("cls");
			headNode = NULL;
			printf("\t\t\t\t�������ɹ�!\n");
			Sleep(1000);
			break;
		case 2:
			system("cls");
			size = SListSize(&headNode);
			printf("\t\t\t\t�������СΪ:[%d]\n",size);
			Sleep(1000);
			break;
		case 3:
			system("cls");
			printf("\t\t\t\t��������Ҫ���ҵ��±�:> ");
			scanf("%d",&index);
			printf("\t\t\t\t��ֵΪ[%d]\n",SListFind(&headNode,index) );
			Sleep(1000);
			break;
		case 4:
			system("cls");
		    printf("\t\t\t\t��������Ҫ���ҵ�ֵ:> ");
			scanf("%d",&val);
			ret = SListSearchVal(&headNode, val);
			if (ret == 0)
				printf("\t\t\t\t��ֵ������!\n");
			else
				printf("\t\t\t\t��ֵ���±�Ϊ: %d",ret);
			Sleep(1000);
			break;
		case 5:
			system("cls");
			printf("\t\t\t\t��������Ҫ�������:> ");
			scanf("%d",&val);
			SListPushFront(&headNode , val);
			printf("\t\t\t\t[%d]�ѱ���������\n",val);
			Sleep(1000);
			break;
		case 6:
			system("cls");
			SListPopFront(&headNode);
			printf("\t\t\t\t�����һ��Ԫ���ѱ�ɾ��!\n");
			Sleep(1000);
			break;
		case 7:
			system("cls");
			PrintSList(headNode);
			Sleep(1000);
			break;
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
			printf("�����������������\n");
		}
	} while (x);
	return 0;
}

