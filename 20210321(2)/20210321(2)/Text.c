#define _CRT_SECURE_NO_WARNINGS

#include "List.h"

int main()
{
	ListNode* phead = NULL;

	printf("测试尾插与头插---------------------------------------------------------------------:\n");
	InitList(&phead);
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushFront(phead, 10);
	ListPushFront(phead, 11);
	ListPushFront(phead, 12);
	ListPrint(phead);
	printf("测试尾删与头删----------------------------------------------------------------------:\n");
	ListPopBack(phead);
	ListPopFront(phead);
	ListPrint(phead);
	printf("测试Findnum，并在其前插入一个数(insert)，删除找到的数(erase):-----------------------\n");
	ListNode* pos = FindNum(phead, 2);
	ListInsert(pos, 8);
	ListPrint(phead);
	ListNode* Pos = FindNum(phead, 8);
	ListErase(Pos);
	ListPrint(phead);
	printf("测试清空链表:-------------------------------------------------------------------------\n");
	ListClear(phead);
	ListPrint(phead);
	return 0;
}

