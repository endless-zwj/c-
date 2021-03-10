#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

SListNode* BuySListNode(SLDataType x)
{
	SListNode* newNode =( (SListNode*)malloc(sizeof(SListNode)) );
	if (newNode == NULL)
	{
		printf("�ڴ�����ʧ�ܣ�\n");
		exit(-1);
	}
	newNode->next = NULL ;
	newNode->data = x;

	return newNode;
}

void PrintSList(SListNode* phead) //һ��ָ��phead����pListָ��  phead��pList��һ����ʱ������
                                  //����pList�޷��ı�ָ��,����������ӡ����
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
	if (*pphead == NULL)               //�޽ڵ�
	{
		printf("������Ϊ�գ�\n");
		return;
	}
	else if ((*pphead)->next == NULL) //һ���ڵ�
	{
		free(*pphead);
	}
	else                              //����������   
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
		printf("������Ϊ�գ�\n");
		return;
	}
	else
	{
		SListNode* cur = *pphead;
		*pphead = (*pphead)->next;
		free(cur);
	}
}