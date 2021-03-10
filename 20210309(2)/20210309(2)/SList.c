#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

SListNode* BuySListNode(SLDataType x)
{
	SListNode* newNode =( (SListNode*)malloc(sizeof(SListNode)) );
	if (newNode == NULL)
	{
		printf("内存申请失败！\n");
		exit(-1);
	}
	newNode->next = NULL ;
	newNode->data = x;

	return newNode;
}

void PrintSList(SListNode* phead) //一级指针phead接收pList指针  phead是pList的一份临时拷贝，
                                  //最终pList无法改变指向,但可用来打印链表
{
	while (phead != NULL)
	{
		printf("%d->", phead->data);
		phead = phead->next;
	}
	printf("NULL\n");
}

void SListPushBack(SListNode** pphead, SLDataType x)
{
	SListNode* newNode = BuySListNode(x);
	if ((*pphead) == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		SListNode* tail = *pphead ;
		while (tail->next != NULL)
		{
			tail = tail->next ;
		}
		tail->next = newNode;

	}
}

void SListPopBack(SListNode** pphead)
{
	if (*pphead == NULL)               //无节点
	{
		printf("该链表为空！\n");
		return;
	}
	else if ((*pphead)->next == NULL) //一个节点
	{
		free(*pphead);
	}
	else                              //两个及以上   
	{
		SListNode* Next = (*pphead)->next;
		SListNode* Prev = *pphead; 
		while (Next->next != NULL)
		{
			Prev = Prev->next;
			Next = Next->next;
		}
		free(Next);
		Prev->next = NULL;
	}
}

void SListPushFront(SListNode** pphead, SLDataType x)
{
	SListNode* newNode = BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		newNode->next = *pphead;
		*pphead = newNode;
	}
}

void SListPopFront(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		printf("该链表为空！\n");
		return;
	}
	else
	{
		SListNode* cur = *pphead;
		*pphead = (*pphead)->next;
		free(cur);
	}
}