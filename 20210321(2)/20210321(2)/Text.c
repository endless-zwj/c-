#define _CRT_SECURE_NO_WARNINGS

#include "List.h"

int main()
{
	ListNode* phead = NULL;

	printf("����β����ͷ��---------------------------------------------------------------------:\n");
	InitList(&phead);
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushFront(phead, 10);
	ListPushFront(phead, 11);
	ListPushFront(phead, 12);
	ListPrint(phead);
	printf("����βɾ��ͷɾ----------------------------------------------------------------------:\n");
	ListPopBack(phead);
	ListPopFront(phead);
	ListPrint(phead);
	printf("����Findnum��������ǰ����һ����(insert)��ɾ���ҵ�����(erase):-----------------------\n");
	ListNode* pos = FindNum(phead, 2);
	ListInsert(pos, 8);
	ListPrint(phead);
	ListNode* Pos = FindNum(phead, 8);
	ListErase(Pos);
	ListPrint(phead);
	printf("�����������:-------------------------------------------------------------------------\n");
	ListClear(phead);
	ListPrint(phead);
	return 0;
}

